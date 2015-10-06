#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
	
	int i = 0;
	FILE * saida;
	saida = fopen("/Users/Rito/Downloads/SC/saidaProg0.txt","w");
    
	while(1) {
        i++;
            if((i == 100)||(i == 1000)||(i == 10000)||(i == 100000));
			fprintf(saida, "Valor atual = %d", i);
    }
	
    fclose(saida);
    
	return 0;
}
