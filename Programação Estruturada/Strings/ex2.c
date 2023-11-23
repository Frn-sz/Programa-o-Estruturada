/*
Faça um programa que receba o vetor nome com o seu nome (nome completo), fornecido via
teclado. Utilize a função fgets para a leitura e em seguida use a função puts para imprimir o
nome. Substitua a função fgets pela função scanf e avalie os resultados.
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char nome[30];

    printf("Digite seu nome:\n");
    // fgets(nome, 30, stdin);
    scanf("%s", nome);

    puts(nome);
    return 0;
}
