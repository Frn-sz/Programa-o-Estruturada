#include <stdio.h>

int main(int argc, char const *argv[])
{

    FILE *arquivo;
    char letra;
    char linha[30];
    int contador = 0;

    arquivo = fopen("texto.txt", "r");

    while (fgets(linha, 30, arquivo) != NULL)
    {
        printf("%s", linha);
        contador++;
    }

    printf("\nN: %d\n", contador);
    fclose(arquivo);
}
