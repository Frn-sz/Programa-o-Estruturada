/*Crie um programa para manipular vetores. O seu programa deve implementar uma função que
receba um vetor de inteiros V e retorne um outro vetor de inteiros alocado dinamicamente com
todos os valores de V que estejam entre o valor mínimo e máximo (que também são passados
como parâmetro para a função).
A função deve obedecer ao seguinte protótipo:
int* valores_entre(int *v, int n, int min, int max, int *qtd);
A função recebe:
• v: vetor de números inteiros;
• n: a quantidade de elementos do vetor v;
• min: valor mínimo a ser buscado;
• max: valor máximo a ser buscado;
• *qtd: valor passado por referencia para armazenar a quantidade de elementos
encontrados.
A função deve:
• Verificar a quantidade de elementos do vetor que sejam maiores do que min e menores
que max;
• Caso a quantidade seja maior do que 0 (zero), alocar dinamicamente uma área do exato
tamanho necessário para armazenar os valores;
• Copiar os elementos do vetor que sejam maiores do que min e menores que max para a
área alocada dinamicamente.
A função retorna:
• O endereço da área alocada dinamicamente, preenchida com os números maiores do que
min e menores que max, ou NULL, caso essa relação de números não tenha sido criada;
• A quantidade de números carregados na área alocada dinamicamente, através do
parâmetro qtd.

Em seguida, crie a função principal do programa para criar um vetor de inteiros dinamicamente,
o usuário deverá informar o tamanho do vetor, o programa deverá preencher o vetor com
número aleatórios entre 0 e 500, exibir esses valores na tela e pedir para o usuário digitar o
valor mínimo e máximo a ser buscado. Em seguida o programa deverá chamar a função
valores_entre e exibir na tela os valores resultantes. Lembre-se de exibir uma mensagem de
erro caso nenhum valor seja encontrado. Não se esqueça de liberar a memória alocada
dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *func(int *vetor, int tam, int min, int max, int *qnt)
{
    int i, x = 0;
    int *v_n;

    // Descobrir quantos elementos estao entre o min e o max
    for (i = 0; i < tam; i++)
        if (vetor[i] >= min && vetor[i] <= max)
            (*qnt)++;

    // Criar um vetor com o tamanho de *qtd
    v_n = (int *)(malloc((*qnt) * sizeof(int)));

    for (i = 0; i < tam; i++)

        if (vetor[i] >= min && vetor[i] <= max)
        {
            v_n[x] = vetor[i];
            x++;
        }

    return v_n;
}

int main(int argc, char const *argv[])
{

    int tamanho, min, max;
    int qtd = 0, *vetor_entre;

    printf("Informe o tamanho do vetor a ser criado: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)(malloc(tamanho * sizeof(int)));

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 500;
        printf("%d \n", vetor[i]);
    }

    printf("Informe o valor mínimo e o valor máximo: \n");

    scanf("%d %d", &min, &max);

    vetor_entre = func(vetor, tamanho, min, max, &qtd);

    printf("O número de elementos entre %d e %d é: %d \n", min, max, qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("%d \n", vetor_entre[i]);
    }
    free(vetor);
    free(vetor_entre);
    return 0;
}
