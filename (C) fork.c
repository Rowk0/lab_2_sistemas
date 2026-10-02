#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
   pid_t pid;

   if ((pid=fork()) == 0 )
   { /*Hijo*/
      printf("Soy el hijo (%d, hijo de %d)\n", getpid(),getppid());
   }

   else
   { /*Padre*/
      printf("Soy el padre (%d, hijo de %d)\n", getpid(),getppid());
   }

   return 0;
}

