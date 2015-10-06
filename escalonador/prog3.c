#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	
	int i = 1;
	FILE * saida;
	saida = fopen("saidaProg1.txt","w");

	while(1) {
		i++;
		if(i == 0){
			printf("Espaço para int ultrapassado. Valor atual = %ld\n", i);
			fprintf(saida, "Espaço para int ultrapassado. Valor atual = %ld\n", i);
		}	
	}

	return 0;
}