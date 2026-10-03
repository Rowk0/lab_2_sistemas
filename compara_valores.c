#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

//gcc compara_valores.c -o ./compara_valores.out -lm && ./compara_valores.out

int main(){
    pid_t pid1;
    int status1;
    int variable;

    printf("Ingrese un numero: \n");
    scanf("%d", &variable);

    if ((pid1 = fork()) == 0)
    {
        printf("Este es el hijo y su varibale es: %d | PID: %d | direccion de memoria: %p \n", variable, getpid(), (void*)&variable);
    }
    else
    {
        wait(&status1);
        printf("Este es el padre y su variable es: %d | PID: %d | direccion de memoria: %p \n", variable, getpid(), (void*)&variable);
    }

    return 0;
}