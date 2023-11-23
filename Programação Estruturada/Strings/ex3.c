/*
Faça um programa que receba um vetor de caracteres, gere e imprima um outro vetor onde as
vogais, do primeiro vetor, sejam substituídas pelo caracter *.*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char const *argv[])
{
    char nome[20];
    int i = 0;
    printf("Digite seu nome:\n");
    fgets(nome, 20, stdin);

    char nome_censurado[20];
    while (nome[i] != '\0')
    {
        char letra = tolower(nome[i]);

        switch (letra)
        {
        case 'a':
            nome_censurado[i] = '*';
            break;
        case 'e':
            nome_censurado[i] = '*';
            break;
        case 'i':
            nome_censurado[i] = '*';
            break;
        case 'o':
            nome_censurado[i] = '*';
            break;
        case 'u':
            nome_censurado[i] = '*';
            break;
        default:
            nome_censurado[i] = nome[i];
        }
        i++;
    }

    puts(nome_censurado);
    return 0;
}
