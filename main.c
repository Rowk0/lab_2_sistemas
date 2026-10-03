#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <math.h>

//gcc main.c -o ./main.out -lm && ./main.out

void duplica_potencia_raiz(int a, int b, int c);

int main(int argc, char *argv[])
{
   duplica_potencia_raiz(4, 3, 16);
}

void duplica_potencia_raiz(int a, int b, int c)
{
    pid_t pid1, pid2;
   int status1, status2;
   int resultado_padre = 0, resultado_abuelo = 0, resultado_hijo = 0;
   
   if ((pid1=fork())==0)
   {
        if ((pid2=fork())==0)
        {   

            resultado_hijo = sqrt(c);

            printf("Soy el hijo (%d, hijo de %d)\n",getpid(),getppid());
            printf("Raiz de %d, resultando %d\n", c, resultado_hijo);
        }
     
        else
        {   
            wait (&status2);

            resultado_padre = a * 2;

            printf("Soy el padre (%d. hijo de %d)\n",getpid(),getppid());
            printf("Duplique el %d, resultando %d\n", a, resultado_padre);
        }
   }

   else
   { 
        wait (&status1);

        resultado_abuelo = pow(b, 3);

        printf("Soy el abuelo (%d, hijo de %d)\n",getpid(),getppid());
        printf("%d a la potencia 3, resultando %d\n", b, resultado_abuelo);
   }
}