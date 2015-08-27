#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#define LIN 10
#define COL 10

int main(int argc, char * argv[]){
	int segmento1, segmento2, segmento3, *p1, *p2, *p3, id, pid, status;
	int i, j = 0;
	int count = 0;
	segmento1 = shmget (IPC_PRIVATE, sizeof(int)*LIN*COL, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	p1 = (int *) shmat (segmento1, 0, 0 );
	
	segmento2 = shmget (IPC_PRIVATE, sizeof(int)*LIN*COL, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	p2 = (int *) shmat (segmento2, 0, 0 );
	
	segmento3 = shmget (IPC_PRIVATE, sizeof(int)*LIN*COL, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
	p3 = (int *) shmat (segmento3, 0, 0 );
	


	if(id = fork() < 0){
		printf("Erro\n");
		exit(-1);
	}
	if(id == 0){
		for(i = 0; i < COL; i++)
			for(j = 0; j < LIN; j++, count++){
				if(id == 0){
					p3[count]	= p1[count] + p2[count];
					if(id = fork() < 0)
						printf("Erro\n");
						exit(-1);
				}
		}
	}

	else{
		printf("dfjaks\n");
		for(i = 0; i < COL*LIN; i++){
			p1[i] = 1;
			p2[i] = 2;
			p3[i] = 0;	
		}
		waitpid(-1, NULL, 0 );
		printf("aaa %d\n", p3[0]);
	}		
}	
