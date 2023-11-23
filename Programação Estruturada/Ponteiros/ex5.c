/*
2) Crie um programa que implemente o jogo “Bingo de PE”. Nesse jogo, o jogador deve
selecionar a quantidade de números que ele gostaria de apostar (entre 1 e 20), e em seguida,
informar os números escolhidos (valores entre 0 e 100). Após receber a aposta, o computador
sorteia 20 números (entre 0 e 100) e compara os números sorteados com os números
apostados, informando ao apostador a quantidade de acertos e os números que ele acertou.
O seu programa deverá implementar as funções ler_aposta, sorteia_valores e compara_aposta.
A função ler_aposta deve receber como parâmetro a quantidade de números que serão
apostados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata
de números apostados. A função deve pedir para o usuário digitar os números apostados e
armazená-los no vetor, garantindo que somente números dentro do intervalo de 0 a 100 sejam
digitados. A função deve seguir o seguinte protótipo:
void ler_aposta(int *aposta, int n);
A função sorteia_valores deve receber como parâmetro a quantidade de números que serão
sorteados e um vetor previamente alocado dinamicamente para armazenar a quantidade exata
de números sorteados. A função deve sortear aleatoriamente os números (entre 0 e 100) e
armazená-los no vetor. A função deve seguir o seguinte protótipo:
void sorteia_valores(int *sorteio, int n);

A função compara_aposta deve receber como parâmetro o vetor com os números apostados
(aposta), o vetor com os números sorteados (sorteio), juntamente com os seus respectivos
tamanhos (na e ns) e um ponteiro para uma variável inteira (qtdacertos), onde deve ser
armazenada a quantidade de acertos. A função deve retornar o ponteiro para um vetor alocado
dinamicamente contendo os números que o apostador acertou. A função deve seguir o seguinte
protótipo:
int* compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns);
Em seguida, crie a função principal do programa utilizado as funções criadas anteriormente
para implementar o jogo “Bingo de PE”. Lembre-se que os vetores aposta, sorteio e acertos
devem ser alocados dinamicamente e a memória*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_aposta(int *aposta, int n)
{
    printf("Digite %d números para apostar: \n", n);
    int num;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &aposta[i]);

        if (aposta[i] < 0 || aposta[i] > 100)
        {
            i--;
            printf("Digite um número entre 0 e 100!");
        }
    }

    printf("Números apostados: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", aposta[i]);
    }
}

void sortear_valores(int *valores_sorteados, int qtd)
{
    srand(time(NULL));

    printf("Valores sorteados: \n");
    for (int i = 0; i < qtd; i++)
    {
        valores_sorteados[i] = rand() % 10;
        printf("%d\n", valores_sorteados[i]);
    }
}

int *compara_valores(int *valores_sorteados, int *valores_apostados, int n_apostados, int n_sorteados, int *qtdacertos)
{
    for (int i = 0; i < n_sorteados; i++)
    {
        for (int j = 0; j < n_apostados; j++)
        {
            if (valores_sorteados[i] == valores_apostados[j])
            {
                (*qtdacertos)++;
            }
        }
    }

    int *acertos = (int *)(malloc(*qtdacertos * sizeof(int)));
    int x = 0;
    for (int i = 0; i < n_sorteados; i++)
    {
        for (int j = 0; j < n_apostados; j++)
        {
            if (valores_sorteados[i] == valores_apostados[j])
            {
                acertos[x] = valores_apostados[j];
                x++;
            }
        }
    }

    return acertos;
}

int main(int argc, char const *argv[])
{
    int n_to_gamble, n_sortear, qtdAcertos = 0;
    int *acertos;
    do
    {
        printf("Digite a quantidade de números que você deseja apostar (entre 1 e 20): \n");
        scanf("%d", &n_to_gamble);
    } while (n_to_gamble < 1 || n_to_gamble > 20);

    do
    {
        printf("Digite a quantidade de números a serem sorteados: \n");
        scanf("%d", &n_sortear);
    } while (n_sortear < n_to_gamble);

    int *aposta = (int *)(malloc(n_to_gamble * sizeof(int)));

    int *valores_sorteados = (int *)(malloc(n_sortear * sizeof(int)));

    ler_aposta(aposta, n_to_gamble);
    sortear_valores(valores_sorteados, n_sortear);
    acertos = compara_valores(valores_sorteados, aposta, n_to_gamble, n_sortear, &qtdAcertos);

    printf("A quantidade de acertos foi: %d \n\n\n Números acertados: \n", qtdAcertos);

    for (int i = 0; i < qtdAcertos; i++)
    {
        printf("%d\n", acertos[i]);
    }

    free(valores_sorteados);
    free(aposta);
    free(acertos);
    return 0;
}
