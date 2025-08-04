#include "syscall.h"

int main(void){
  
  pid_t pid_m;
  int fd, n, m;

  int numbers[5] = {0,1,2,3,4};
  char charNumbers[5], buff[5]; 

  int i, current = 0;
  
  for (i = 0; i < 5; i++){
    charNumbers[current++] = (char)(numbers[i]) + '0';
    printf("%c ", charNumbers[i]);
  }

  fd = creat("/home/carlos/Desktop/datos.txt", 0777);
  ErrorManagement(fd);
  close(fd);
  
  pid_m = fork();

  if(pid_m == -1) {
    perror("Fork. ");
    exit(-1);
    
  } else if(pid_m == 0) { // Child process

    fd = open("/home/carlos/Desktop/datos.txt", 2); // Reopen file with appropriate mode
    if(fd == -1){
      ErrorManagement(fd);
      exit(-1);
    }

    printf("Child process: writing in file \n");

    n = write(fd, charNumbers, sizeof(charNumbers));
    ErrorManagement(n);
    
  } else if (pid_m > 0) { // Parent process
  
    sleep(3);

    fd = open("/home/carlos/Desktop/datos.txt", 2); // Reopen file with appropriate mode
    if(fd == -1){
      ErrorManagement(fd);
      exit(-1);
    }

    printf("Parent process: reading file \n");

    m = read(fd, buff, sizeof(buff));
    ErrorManagement(m);

    n = write(STDOUT_FILENO, buff, sizeof(buff));
    ErrorManagement(n);

  }

  close(fd);

  return 0;
}