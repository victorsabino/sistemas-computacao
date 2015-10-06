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
    int i, bigPrio, priorities[4], pid[4], verify[4] = {0,0,0,0};
    FILE * entrada;
    FILE * saida;
    char command[5];
    char nomePrograma[10][10];
    printf("Executando o escalonador por prioridade...\n");
    
    saida = fopen("saidaprio.txt", "w");
    entrada = fopen("entradaprio.txt", "r");
    
    for(i=0; i<1; i++){
	printf("h\n");
        fscanf(entrada, "%*s %s %*s%*c %d", nomePrograma[i][0], &priorities[i]);
	printf("\n command - %s \n", command);	
    }
    
    
        while((priorities[0] != 7)||(priorities[1] != 7)||(priorities[2] != 7)||(priorities[3] != 7)){
            
            bigPrio = compare(priorities);
            if(verify[bigPrio] == 0){
                fprintf(saida, "Executando o programa %d... \n", bigPrio);
                pid[bigPrio] = fork();
                if(pid[bigPrio] == 0){
                    execute(bigPrio);
                }
                sleep(1);
                kill(pid[bigPrio], SIGSTOP);
                fprintf(saida, "Interrompendo o programa %d... \n\n", bigPrio);
                verify[bigPrio] = 1;
                priorities[bigPrio]++;
                if(priorities[bigPrio] > 7){
                    priorities[bigPrio] = 7;
                }
            }
            else{
                fprintf(saida, "Continuando o programa %d... \n", bigPrio);
                if(pid[bigPrio] == 0){
                    kill(pid[bigPrio], SIGCONT);
                }
                    sleep(1);
                    kill(pid[bigPrio], SIGSTOP);
                    fprintf(saida, "Interrompendo o programa %d... \n\n", bigPrio);
                
                priorities[bigPrio]++;
                if(priorities[bigPrio] > 7){
                    priorities[bigPrio] = 7;
                }
            }
        }


    fclose(entrada);
    fclose(saida);
    
    return 0;
}
