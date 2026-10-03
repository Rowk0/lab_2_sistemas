#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
   pid_t pid1, pid2; //variables que se va almacenar el PID.
   int status1, status2; //variables donde se almacena el estado.
   
   if ((pid1=fork())==0) //primer fork(), es el abuelo que crea el hijo(padre).
   { 
      if ((pid2=fork())==0) //segundo fork(), es el padre y crea al hijo.
      {
         printf("Soy el hijo (%d, hijo de %d)\n",getpid(),getppid());
      }
     
      else
      {
         wait (&status2); //padre espera a que su hijo termine la ejecucion.
         printf("Soy el padre (%d. hijo de %d)\n",getpid(),getppid());
      }
   }

   else
   {
      wait (&status1); //abuelo espera a que su hijo(padre) termine su ejecucion
      printf("Soy el abuelo (%d, hijo de %d)\n",getpid(),getppid());
   }

   return 0;
}