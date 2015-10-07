#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute(int i){
    switch(i){
        case 0:
            system("/Users/Rito/Downloads/SC/testesjf");
            break;
        case 1:
            system("/Users/Rito/Downloads/SC/testesjf");
            break;
        case 2:
            system("/Users/Rito/Downloads/SC/testesjf");
            break;
        case 3:
            system("/Users/Rito/Downloads/SC/testesjf");
            break;
    }
}

int main(){
    int i, tempo[4], fatia = 1, pid[4], verify[4] = {0,0,0,0};
    FILE * entrada;
    FILE * saida;
    
    printf("Executando o escalonador round-robin...\n");
    
    saida = fopen("/Users/Rito/Downloads/SC/saidarr.txt", "w");
    entrada = fopen("/Users/Rito/Downloads/SC/entradarr.txt", "r");
    
    fscanf(entrada, "%d", &tempo[i]);
    
    
        while((tempo[0] > 0)||(tempo[1] > 0)||(tempo[2] > 0)||(tempo[3] > 0)){
            
            for(i = 0; (i < 4) && (tempo[i] > 0); i++){
                if(verify[i] == 0){
                    fprintf(saida, "Executando o programa %d... \n", i);
                    pid[i] = fork();
                    if(pid[i] == 0){
                        execute(i);
                    }
                    
                        sleep(fatia);
                        kill(pid[i], SIGSTOP);
                        fprintf(saida, "Interrompendo o programa %d... \n\n", i);
                    tempo[i] -= fatia;
                    verify[i] = 1;
                }
                else{
                    fprintf(saida, "Continuando o programa %d... \n", i);
                    if(pid[i] == 0){
                        kill(pid[i], SIGCONT);
                    }
                        sleep(fatia);
                        kill(pid[i], SIGSTOP);
                        fprintf(saida, "Interrompendo o programa %d... \n\n", i);
                    
                    tempo[i] -= fatia;
                }
            }
        }
    
    
    fclose(entrada);
    fclose(saida);
    
    return 0;
    
}


