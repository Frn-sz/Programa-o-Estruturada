/*1. Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas
respectivas quantidades de elementos, n1 e n2. A função deverá retornar um ponteiro para um
terceiro vetor, v3, com capacidade para (n1 + n2) elementos, alocado dinamicamente, contendo
a união de v1 e v2.

Por exemplo, se v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13, 45, 7, 24, 4,
16, 81, 10, 12}.

O cabeçalho dessa função deverá ser o seguinte:

int* uniao(int *v1, int n1, int *v2, int n2);
Em seguida, crie a função principal do programa para chamar a função uniao passando dois
vetores informados pelo usuário (ou declarados estaticamente). Em seguida, o programa deve
exibir na tela os elementos do vetor resultante. Não esqueça de liberar a memória alocada
dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *uniao(int *v1, int *v2, int n1, int n2)
{
    int *v_n = (int *)(malloc((n1 + n2) * sizeof(int)));

    for (int i = 0; i < n1; i++)
    {
        v_n[i] = v1[i];
    }

    for (int i = n1; i < n1 + n2; i++)
    {
        v_n[i] = v2[i - n1];
    }

    return v_n;
}

int main(int argc, char const *argv[])
{

    int n1, n2, *v1, *v2;

    printf("Digite o número de elementos do primeiro vetor: \n");
    scanf("%d", &n1);

    printf("Digite o número de elementos do segundo vetor: \n");
    scanf("%d", &n2);

    v1 = (int *)(malloc(n1 * sizeof(int)));
    v2 = (int *)(malloc(n2 * sizeof(int)));

    printf("\n Primeiro vetor: \n");

    srand(time(NULL));
    for (int i = 0; i < n1; i++)
    {
        v1[i] = rand() % 30;
        printf("%d \n", v1[i]);
    }

    printf("\n Segundo vetor: \n");
    for (int i = 0; i < n2; i++)
    {
        v2[i] = rand() % 30;
        printf("%d \n", v2[i]);
    }

    int *v3 = uniao(v1, v2, n1, n2);

    printf("Terceiro vetor: \n");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d\n", v3[i]);
    }

    free(v1);
    free(v2);
    free(v3);

    return 0;
}
