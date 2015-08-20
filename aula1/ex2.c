#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
	int x = 1;
	printf("Valor antes do fork %d\n", x);
	pid_t pid = fork();
	if(pid == 0){
		//processo filho
		x = 5;
		printf("Valor do X no filho %d\n", x);
	}
	else{
		waitpid(-1, NULL, 0);
		printf("Valor do X no pai %d\n", x);
		exit(0);
	}

	return 0;
}



/**********
*
* Os processos rodam simultaneamente, com a cópia dos valores obtidos no início do fork
* então, o outro processo vai pegar o valor inalterado da variavel
*
*****/
