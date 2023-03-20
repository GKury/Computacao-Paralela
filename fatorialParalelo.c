#include <stdio.h>
#include <sys/types.h>;
#include <unistd.h>;
#include<stdlib.h>
#include<sys/wait.h>

int main(void) {
  int i, num, j, res2, div, fd[2];
  pid_t processo;

  if(pipe(fd)<0) {
    perror("pipe") ;
    return -1 ;
  }
  
  printf ("Enter the number: ");   
  scanf ("%d", &num);
  
  j = num;

  div = num / 2;

  processo = fork();
  if (processo == -1){
    perror("Erro ao criar processo novo");
    return 0;
    
  } else if (processo == 0){
    for (i=1; j > div; j = j -1) {
      i=i*j;
    } 
    close(fd[0]);
    write(fd[1], &i, sizeof(i)); 
    exit(0);
  } else{
    wait(NULL);
    for (res2=1; div > 1; div = div -1) {
      res2=res2*div;
    }
    close(fd[1]);
    read(fd[0], &i, sizeof(i));
  }

  printf("\n\nThe factorial of %d is %d\n",num,i*res2);
}
