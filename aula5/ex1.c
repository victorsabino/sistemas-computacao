#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
int main(){
	int fd[2];
	const char * informacao = "uma mensagem";
	char leitura[sizeof informacao];
	int pid;
	pipe(fd);
	pid = fork();
	if(pid < 0){
		printf("Erro\n");
		exit(-1);
	}

	if(pid > 0){
		//pai
		waitpid(-1, NULL, 0);
		close(fd[1]);
		read(fd[0], leitura, strlen(informacao) + 1);
		printf("Lido do pipe : %s \n", leitura);
		kill(pid, SIGKILL);
	}
	else if(pid == 0){
		//filho
		close(fd[0]);
		write(fd[1], informacao, strlen(informacao) + 1);		
		printf("Escrito no pipe\n");
	}

}
