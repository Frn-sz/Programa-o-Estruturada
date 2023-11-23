#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct
{
    int numero;
    char naipe[8];
} carta;

carta *montar_baralho()
{
    carta *baralho = (carta *)malloc(52 * sizeof(carta));

    char *naipes[] = {"paus", "ouro", "espadas", "copas"};
    int x = 0;
    int naipeCounter = 1; // Começando em 1 para representar as cartas de 1 a 13

    for (int i = 0; i < 52; i++)
    {
        baralho[i].numero = naipeCounter;
        strcpy(baralho[i].naipe, naipes[x]);

        naipeCounter++;

        if (naipeCounter > 13)
        {
            naipeCounter = 1;
            x++;
        }
    }

    return baralho;
}

void embaralhar(carta *baralho)
{
    srand(time(NULL));
    for (int i = 0; i < 52; i++)
    {
        int random = rand() % 52;

        carta temp = baralho[i];      // temp = 1 carta
        baralho[i] = baralho[random]; // 1 carta = 10 carta
        baralho[random] = temp;       // 10 carta = 1 carta anterior
    }
}

int main(int argc, char const *argv[])
{
    carta *p = montar_baralho();
    embaralhar(p);
    int n;

    printf("Digite quantas cartas cada jogador deve ter:\n");
    scanf("%d", &n);

    printf("Cartas do primeiro jogador\n\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("Número da carta: %d\n", p[i].numero);
        printf("Naipe da carta: %s\n", p[i].naipe);
    }

    printf("Cartas do segundo jogador\n\n\n");
    for (int i = n; i < n * 2; i++)
    {
        printf("Número da carta: %d\n", p[i].numero);
        printf("Naipe da carta: %s\n", p[i].naipe);
    }

    printf("Cartas restantes:\n\n\n");
    for (int i = n * 2; i < 52; i++)
    {
        printf("Número da carta: %d\n", p[i].numero);
        printf("Naipe da carta: %s\n", p[i].naipe);
    }

    free(p);

    return 0;
}
