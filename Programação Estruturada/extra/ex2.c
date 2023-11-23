/*2. Implementar a função inverte que recebe um número inteiro como parâmetro e retorna este
número escrito ao contrário. Ex: 431 <-> 134.*/
#include <stdio.h>

void inverter(int num)
{

    int reversed = 0;
    while (num != 0)
    {
        int digito = num % 10;
        reversed = reversed * 10 + digito;
        num /= 10;
    }

    printf("%d\n", reversed);
}
int main(int argc, char const *argv[])
{
    int num;

    printf("Digite um número inteiro: ");
    scanf("%d", &num);
    inverter(num);
    return 0;
}
