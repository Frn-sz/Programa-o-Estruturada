/*
Faça um programa que receba e imprima um vetor com o seu nome (nome completo) e o total
de letras que ele possui.
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char nome[20];

    printf("Digite seu nome:\n");
    fgets(nome, 20, stdin);

    int tam = strlen(nome);
    int tam_r = tam;
    for (int i = 0; i < tam; i++)
    {
        if (nome[i] == '\n' || nome[i] == ' ')
        {
            tam_r--;
        }
    }
    printf("O tamanho do seu nome é: %d\n", tam_r);

    return 0;
}
