#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <math.h>

//gcc ec_cuadratica_fork.c -o ./ec_cuadratica_fork.out -lm && ./ec_cuadratica_fork.out

int main(int argc, char *argv[])
{
    double a, b, c;
    double discriminante, x1, x2, parteReal, parteImaginaria;
    pid_t pid1;
    int status1;

    printf("Ingrese los coeficientes a, b y c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // a no puede ser 0 en una ecuación cuadrática
    if (a == 0) {
        printf("No es una ecuacion cuadratica ('a' debe ser distinto de 0).\n");
        return 1;
    }

    // Calculamos el discriminante (b^2 - 4ac)
    discriminante = pow(b, 2) - (4 * a * c);

    if (discriminante < 0)
    {
        parteReal = -b / (2 * a);
        parteImaginaria = sqrt(-discriminante) / (2 * a);
        printf("Raices complejas / imaginarias:\n");
        printf("x1 = %.2lf + %.2lfi   (PID: %d)\n", parteReal, parteImaginaria, getpid());
        printf("x2 = %.2lf - %.2lfi   (PID: %d)\n", parteReal, parteImaginaria, getpid());
    }
    

    if ((pid1 = fork()) == 0){
        if (discriminante > 0)
        {
            x1 = (-b + sqrt(discriminante)) / (2 * a);
            printf("Raices reales y distintas:\n");
            printf("x1 = %.2lf    (PID: %d)\n", x1, getpid());
        }
        else if (discriminante == 0)
        {
            x1 = -b / (2 * a);
            printf("Raiz real unica (doble):\n");
            printf("x1 = x2 = %.2lf\n  (PID: %d)", x1, getppid());
        }
    }
    else
    {
        wait(&status1);
        if (discriminante > 0)
        {
            x2 = (-b - sqrt(discriminante)) / (2 * a);
            printf("x2 = %.2lf   (PID: %d)\n", x2, getpid());
        }
    }
    
    return 0;
}