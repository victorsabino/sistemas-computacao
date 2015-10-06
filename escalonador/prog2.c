#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	
	int i = 0;
	FILE * saida;
	saida = fopen("/Users/Rito/Downloads/SC/saidaProg2.txt","w");
    
	while(1) {
        i++;

			fprintf(saida, "Executando o prog 2...");
    }
	
    fclose(saida);
    
	return 0;
}
