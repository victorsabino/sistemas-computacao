#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main () {
	char * prior[] = {"prioridade", NULL};
	char * rr[] = {"roundrobin", NULL};

	int escalonador;
	printf("\n1 - Prioridade com Preempção\n2 - Round-Robin\n");
	scanf("%d", &escalonador);

	switch (escalonador) {
		case 1:
			execve("/prioridade", prior);
			break;
		case 2:
			execve("/roundrobin", rr);
			break;
		default:
			break;
	}

	return 0;
}
