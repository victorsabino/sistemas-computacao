#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
int main(){
	int x[10] = {2, 3, 1, 9, 4, 5, 7, 6, 10, 12};
	int i, j;
	int aux;
	int tamanho = 10;
	printf("Vetor antes do fork\n");	
	for(i = 0; i < 10; i++){
		printf("%d -", x[i]);
	}
	printf("\n");
	
	pid_t pid = fork();
	if(pid == 0){
		//processo filho
		printf("Vetor do filho\n");
		
 		 for( i=tamanho-1; i >= 1; i--) {  
        
   			 for(j=0; j < i ; j++) {
          
      				if(x[j]>x[j+1]) {
                
     				   aux = x[j];
       				 x[j] = x[j+1];
        			x[j+1] = aux;
        
        			}
      			}
    		}

		printf("---------------\n");
		for(i = 0; i < 10; i++){
			printf("%d -", x[i]);
		}	
		printf("\n");
	}
	else{
		waitpid(-1, NULL, 0);
		printf("Vetor deopsi do waitpid\n");
		for(i = 0; i < 10; i++){
			printf("%d -", x[i]);
		}	
		printf("\n");
		exit(0);
	}

	return 0;
}




/*******
* Os processos usam espaços diferentes de memória pro vetor, pois na divisão
* de processos utilizando o ofkr há a cópia de todos os valores e a alocação dos mesmos
* em um novo espaço de memória
*
*******/
