#nclude <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(){
	int buff[8];
	int pid[2];
	int qid = 99;
	int result1, result2;

	pid[0] = fork();
	if(pid[0] < 0) return -1;
	else if (pid[0] > 0){
		//pai
		pid[1] = fork();
		if(pid[1] < 0)		return -1;
		else if(pid[1] > 0){
			//pai
			if((qid = msgget( 8790 , IPC_CREAT | 0660 )) == -1){
				return -1;
			}
			for(i = 0; i < 64; i++){
				if((result1 = msgsnd(qid, buff, sizeof(buff), 0) == - 1) return -1;
				waitpid(pid[0], NULL, 0);
				waitpid(pid[1], NULL, 0);
			}
			else if(pid[2] == 0)
				//filho 2
								
			}
	}
	
	else if (pid[0] == 0){
		//filho 1
	}

}

