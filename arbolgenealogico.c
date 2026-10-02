#include<sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
   pid_t pid1,pid2,pid3;
   int status1,status2,status3;
   if((pid1=fork())==0)
   {
      printf("Soy el nieto 1 (%d, hijo de %d)\n",getpid(),getppid());
      if((pid2=fork())==0)
      {
         //printf("Soy el nieto 2 (%d, hijo de %d)\n",getpid(),getppid()); 
         if((pid3=fork())==0)
            printf("Soy el tataranieto (%d, hijo de %d)\n",getpid(),getppid());
      }
    /*  else
      {
         waitpid(pid2,&status2,0);
         printf("Soy el nieto1 (%d, hijo de %d)\n",getpid(),getppid()); 
      }*/
   }
   else
   {
      if((pid2=fork())==0)
         printf("Soy el nieto 2 (%d, hijo de %d)\n",getpid(),getppid()); 
      else
      {
         waitpid(pid1,&status1,0);
         waitpid(pid2,&status2,0);
         printf("Soy el padre (%d, hijo de %d)\n",getpid(),getppid());
      }
   }
   return 0;
}
