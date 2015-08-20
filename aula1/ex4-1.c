#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
	char * args[3] = {"echo", "hello", NULL};
	pid_t pid = fork();
	if(pid == 0){
		//processo filho
		//execve("ex4", NULL, 0);
		execve("/bin/echo", args , 0);
	}
	else{
		waitpid(-1, NULL, 0);
		exit(0);
	}

	return 0;
}


