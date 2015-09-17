#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(){
	char informacao[100];
	char leitura[100];
	int pid;
	static char * arg[] = {"echo", "NULL"};
	static char * arg2[] = {"ls", "-A" , "NULL"};
	int fd[2];

	pid = fork();
	if ( pid < 0)
		return -1;

	else if(pid > 0){
	//pai
	waitpid(-1, NULL, 0);
	execve("/bin/echo", arg, 0);
	}
	else if(pid == 0){
	//filho
	execve("/bin/ls", arg2, 0);
	close(fd[0]);
	}
}
