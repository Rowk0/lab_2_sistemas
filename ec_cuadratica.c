#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <math.h>

//gcc ec_cuadratica.c -o ./ec_cuadratica.out -lm && ./ec_cuadratica.out

//Hay que dividir el proceso en fork()

int main(int argc, char *argv[])
{
   double a, b, c;
    double discriminante, x1, x2, parteReal, parteImaginaria;

    printf("Ingrese los coeficientes a, b y c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // a no puede ser 0 en una ecuación cuadrática
    if (a == 0) {
        printf("No es una ecuacion cuadratica ('a' debe ser distinto de 0).\n");
        return 1;
    }

    // Calculamos el discriminante (b^2 - 4ac)
    discriminante = pow(b, 2) - (4 * a * c);

    // Caso 1: Raíces reales y distintas
    if (discriminante > 0) {
        x1 = (-b + sqrt(discriminante)) / (2 * a);
        x2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("Raices reales y distintas:\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }
    // Caso 2: Una única raíz real (doble)
    else if (discriminante == 0) {
        x1 = -b / (2 * a);
        printf("Raiz real unica (doble):\n");
        printf("x1 = x2 = %.2lf\n", x1);
    }
    // Caso 3: Raíces complejas / imaginarias
    else {
        parteReal = -b / (2 * a);
        parteImaginaria = sqrt(-discriminante) / (2 * a);
        printf("Raices complejas / imaginarias:\n");
        printf("x1 = %.2lf + %.2lfi\n", parteReal, parteImaginaria);
        printf("x2 = %.2lf - %.2lfi\n", parteReal, parteImaginaria);
    }
}