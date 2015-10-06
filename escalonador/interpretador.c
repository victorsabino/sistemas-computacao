#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main () {

	int escalonador;
	printf("Selecione o escalonador:\n1 - SJF\n2 - Prioridade com Preempção\n3 - Round-Robin\n");
	scanf("%d", &escalonador);

	switch (escalonador) {
		case 1:
			system("./shortestjobfirst.c");
			break;
		case 2:
			system("./prioridade.c");
			break;
		case 3:
			system("./roundrobin.c");
			break;
		default:
			break;
	}

	return 0;
}

© 2014 Microsoft Termos Privacidade e cookies Desenvolvedores Português (Brasil)
