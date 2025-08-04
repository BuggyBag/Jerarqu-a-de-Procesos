#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define SUCCESS 1
#define ERROR -1

int ErrorManagement(long int var){
  if (var < 0){

    printf("Ocurrió un error: ");

    switch(errno){
      case EAGAIN:
        printf("Archivo bloqueado. \n");
        return ERROR;
      case EACCES:
        printf("Problema de permisos del archivo.\n");
        return ERROR;
      case EBADF:
        printf("Mal descriptor del archivo.\n"); 
        return ERROR;
      default:
        printf("Error desconocido. \n");  
        return ERROR;
      }
  }

  return SUCCESS;
}