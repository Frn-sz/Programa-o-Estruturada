#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int letra;
    char str_output[30][30] = {};

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            letra = fgetc(input);

            if (letra != EOF)
            {
                str_output[i][j] = letra;
            }
            else
            {
                str_output[i][j] = '\0';
                break;
            }
        }
    }

    for (int i = 29; i >= 0; i--)
    {
        for (int j = 29; j >= 0; j--)
        {
            if (str_output[i][j] != '\0')
            {
                fputc(str_output[i][j], output);
            }
        }
    }

    return 0;
}
