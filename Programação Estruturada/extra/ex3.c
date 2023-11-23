#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int temp_sem_dim(int vet[10])
{
    int contador[10] = {0};
    int index = 0;
    for (int i = 0; i < 9; i++)
    {
        if (vet[i] == vet[i + 1])
        {
            contador[index]++;
        }
        else
        {
            index++;
        }
    }

    int maior = contador[0];
    for (int i = 0; i <= index; i++)
    {
        if (contador[i] > maior)
        {
            maior = contador[i];
        }
    }

    return maior;
}

int freagem(int vet[10])
{

    int freagens[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        freagens[i] = vet[i + 1] - vet[i];
    }
    int menor = freagens[0];
    int pos = 0;
    for (int i = 0; i < 10; i++)
    {
        if (freagens[i] < menor)
        {
            menor = freagens[i];
            pos = i;
        }
    }

    return pos;
}
int aceleracao(int vet[10])
{
    int acel_temp = 0;
    int acel = 0;
    int pos = 0;
    for (int i = 0; i < 9; i++)
    {
        acel_temp = vet[i + 1] - vet[i];

        if (acel_temp > acel)
        {
            acel = acel_temp;
            pos = i;
        }
    }

    return pos;
}
int main(int argc, char const *argv[])
{

    int vet[10];

    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        vet[i] = rand() % 5;
        printf("%d ", vet[i]);
    }

    printf("Maior tempo sem diminuir a velocidade: %d\n", temp_sem_dim(vet));
    printf("A freagem mais abrupta ocorreu no momento: %d\n", freagem(vet) + 1);
    printf("A maior aceleração ocorreu no momento: %d\n", aceleracao(vet));

    return 0;
}
