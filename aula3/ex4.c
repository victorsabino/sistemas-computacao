#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
int main(){
	int pid[2];
	int i;

	pid[0] = fork();
	pid[1] = fork();
	
	//interromper o primeiro processo
	kill(pid[0], SIGSTOP);
	kill(pid[1], SIGSTOP);
	if(pid[0] == 0){
		for(i = 0; i < 10; i++){
			kill(pid[0], SIGCONT);
			printf("Continuou o processo 0\n");
			kill(pid[0], SIGSTOP);
			printf("Pausar o processo 0\n");
		
			kill(pid[1], SIGCONT);
			printf("Continue o processo 1\n");
			kill(pid[1], SIGSTOP);
			printf("Pausar o processo 1\n");
			
		}
		kill(pid[0], SIGKILL);
		kill(pid[1], SIGKILL);
		exit(1);
	}
	
	if(pid[0] < 0 || pid[1] < 0)
		return -1;

	if(pid[0] > 0)
		while(1){	//loop infinito	
			printf("Processo0\n");
		}
	if(pid[1] > 0)
		while(1){	//loop infinito
			printf("Processo1\n");
		}
	
}
