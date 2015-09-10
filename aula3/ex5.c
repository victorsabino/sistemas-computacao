#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void SIGNAL_HANDLER(){
	puts("Sinal ativado");
	exit(-1);
}

int main(){
	int num1, num2;

	if(signal(SIGFPE, SIGNAL_HANDLER) == SIG_ERR)
		return -1;puts("Digite dois numeros reais");

	scanf("%d %d", &num1, &num2);
	
	printf("%d - %d = %d\n", num1, num2, num1 + num2);
	printf("%d + %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
	
}
