#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE  sizeof(int)

int main() {
    int shmid, *num; //num tem q ser ponteiro pra passar o endereço dps
    pid_t pid;

    if ((shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    if ((num = shmat(shmid, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(1);
    }

    *num = 1;

    printf("Pai imprimindo valor inicial da variavel: %d\n", *num);

    pid = fork();
  
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { 
        *num += 2;
        exit(0);
    } else {  
        wait(NULL);
      
        *num *= 4;

        printf("\nPai imprimindo valor final da variavel, apos ela ter sido somada com 2 no filho, e este resultado multiplicado por 4 no pai: %d\n", *num);

        if (shmdt(num) == -1) {
            perror("shmdt");
            exit(1);
        }
        if (shmctl(shmid, IPC_RMID, 0) == -1) {
            perror("shmctl");
            exit(1);
        }
    }
    return 0;
}
