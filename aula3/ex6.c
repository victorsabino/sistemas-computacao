#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int tempo = 0;
int ligado = 0;
float preco  = 0;

void alarm_handler(){
	if(ligado)
		tempo++;
	 printf("Entrei no alarm");
	alarm(1);
}
void liga(){
	printf("Entrei no ligar\n");
	ligado = 1;
}

void desliga(){
	if(tempo > 60)
		preco = 0.2*60 + (tempo - 60)*0.1;
	printf("preço pelo tempo = %f", preco);
}

int main(){
	int custo;
	int pid;
	char switcher = 'l';

	if(signal(SIGUSR1, liga) == SIG_ERR)
		return -1;
	if(signal(SIGUSR2, desliga) == SIG_ERR)
		return -1;
	if(signal(SIGALRM, alarm_handler) == SIG_ERR)
		return -1;

	alarm(1);

	
	pid = fork();
	if(pid == 0){
		scanf("%c", &switcher);
		for(;1;){
			if(switcher == 'l')
				kill(pid, SIGUSR1);			
			else if(switcher == 'd'){
				ligado = 0;
				kill(pid, SIGUSR2);
			}
			else{
				printf("Digite l ou d");
			}
			sleep(5);
			scanf("%c", &switcher);
			switcher = 'd';
		}
	}
}
