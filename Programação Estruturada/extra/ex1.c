#include <stdio.h>

int main(int argc, char const *argv[])
{
    int soma = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                soma += j;
            }
        }

        if (soma == i)
        {
            printf("%d\n", soma);
        }
        soma = 0;
    }

    return 0;
}

/*
i = 1
j = 1

1 <= 1 V



*/
