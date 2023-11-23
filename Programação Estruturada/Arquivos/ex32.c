
/*
Faça um programa em C que receba o nome de um arquivo de entrada e o nome de um
arquivo de saída. Cada linha do arquivo de entrada possui colunas de tamanho de 30 e possui
no máximo 30 linhas. No arquivo de saída deverá ser escrito o arquivo de entrada de forma
inversa.
Veja um exemplo:
Arquivo de entrada:
hoje e dia de prova de pe
a prova esta muito facil
Arquivo de saída:
licaf otium atse avorp a
pe ed avorp ed aid e ejoh
*/

#include <stdio.h>

int main()
{

    FILE *arq;

    arq = fopen("input.txt", "r");

    FILE *out;

    out = fopen("output.txt", "w");

    char caractere;
    int tam = 0;

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if ((caractere = fgetc(arq)) != EOF)
            {
                tam++;
            }
            else
            {
                break;
            }
        }
    }

    rewind(arq);
    char texto_arr[tam];

    int index = 0;
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if ((caractere = fgetc(arq)) != EOF)
            {
                texto_arr[index] = caractere;
                index++;
            }
            else
            {
                break;
            }
        }
    }

    for (int i = 0; i < tam; i++)
    {
        printf("%c", texto_arr[i]);
    }

    for (int i = tam; i >= 0; i--)
    {
        fputc(texto_arr[i], out);
    }

    fclose(arq);
    return 0;
}
