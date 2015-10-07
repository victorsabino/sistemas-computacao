#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int compare(int * priorities){
    int i, bigPrioIdx = 0;
    
    for(i=1; i<4; i++){
        if(priorities[bigPrioIdx] > priorities[i]){
            bigPrioIdx = i;
        }
    }
    return bigPrioIdx;
}

void execute(int i){
	switch(i){
        case 0:
            system("prog0.c");
            break;
        case 1:
            system("prog1.c");
            break;
        case 2:
            system("prog2.c");
            break;
        case 3:
            system("prog3.c");
            break;
    }
}

int main(){
    int i, bigPrio, priorities[4], pid[4], verify[4] = {0,0,0,0}, nProgramas;
    FILE * entrada;
    FILE * saida;
    char command[5];
    char nomePrograma[10][10];
    printf("Executando o escalonador por prioridade...\n");
    
    saida = fopen("saidaprio.txt", "w");
    entrada = fopen("entradaprio.txt", "r");
    
    for(nProgramas = 0;fscanf(entrada, "%*s %s %*s%*c %d", &nomePrograma[i][0], &priorities[i])== 2; nProgramas++);
    
    
    for(i; i < nPrograma; i++){        
            bigPrio = compare(priorities);
            if(verify[bigPrio] == 0){
                fprintf(saida, "Executando o programa %d... \n", bigPrio);
                pid[bigPrio] = fork();
                if(pid[bigPrio] == 0){
                    execve(nomePrograma[bigPrio][0], 0, 0);
                }
                sleep(1);
                kill(pid[bigPrio], SIGKILL);
                fprintf(saida, "Finalizando o programa %d... \n\n", bigPrio);
                verify[bigPrio] = 1;
                priorities[bigPrio] = 10;
                
            }
        }
 
    fclose(entrada);
    fclose(saida);
    
    return 0;
}
