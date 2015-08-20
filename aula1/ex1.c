#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
	pid_t pid = fork();
	if(pid == 0){
		//processo filho
		printf("Filho %d\n", getpid());
	}
	else{
		waitpid(-1, NULL, 0);
		printf("Pai %d\n", getpid());
		exit(0);
	}

	return 0;
}
