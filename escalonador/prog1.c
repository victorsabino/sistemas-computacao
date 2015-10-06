#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	
	int i = 1;
	FILE * saida;
	saida = fopen("/Users/Rito/Downloads/SC/saidaProg1.txt","w");

	while(1) {
		i = i*2;
		
			fprintf(saida, "Valor atual = %d\n", i);

		}

    fclose(saida);

	return 0;
}