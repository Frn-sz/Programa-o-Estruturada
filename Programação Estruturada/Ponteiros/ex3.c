#include <stdio.h>
/*
Fazer uma função fatores que:
a. Recebe 3 parâmetros: um vetor de inteiros, um número inteiro n passado por valor e
outro número x passado como ponteiro.
b. Retorna um número inteiro.
c. Decompõe o número n em fatores primos e armazena-os nas posições do vetor até um
limite de 10. O conteúdo de x deve receber o número de fatores primos encontrados.
Caso o número de fatores encontrados seja maior que 10, a função deve retornar 1 e o
vetor deve receber somente até o décimo fator primo, do contrário deve retornar 0.*/

int fatores(int array[], int n, int *x)
{
    int prime = 2;

    while (n > 1)
    {
        int isPrime = 0;
        for (int j = 2; j < prime / 2; j++)
        {
            if (prime % j == 0)
            {
                isPrime = 1;
                break;
            }
        }

        if (isPrime == 0)
        {
            if (n % prime == 0)
            {
                if (*x == 10)
                {
                    return 1;
                }
                n = n / prime;
                array[*x] = prime;
                (*x)++;
            }
            else
            {
                prime++;
            }
        }
        else
        {
            prime++;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int array[10] = {0};
    int n;
    int x = 0;
    printf("Digite um número: \n");
    scanf("%d", &n);
    fatores(array, n, &x);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}
