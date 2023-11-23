#include <stdio.h>

int main(int argc, char const *argv[])
{

    FILE *arquivo;
    char letra;
    char letra2;
    int contador;

    arquivo = fopen("texto.txt", "r");

    printf("Qual letra você quer contar? ");
    scanf("%c", &letra);

    do
    {
        letra2 = fgetc(arquivo);

        if (letra2 == letra)
            contador++;

    } while (letra2 != EOF);

    fclose(arquivo);

    printf("N: %d\n", contador);
    return 0;
}
