#include <stdio.h>

typedef struct
{
    int tempo_servico;
    char profissao[30];
} Colaborador;

int main(int argc, char const *argv[])
{

    FILE *arquivo = fopen("emp.txt", "w");

    for (int i = 0; i < 3; i++)
    {
        Colaborador colaborador;
        printf("Digite o nome do colaborador %d: ", i + 1);
        scanf("%s", colaborador.profissao);

        printf("Digite o tempo de colaboração (em anos) do colaborador: ");

        scanf("%d", &colaborador.tempo_servico);

        fprintf(arquivo, "%s %d", colaborador.profissao, colaborador.tempo_servico);
    }

    fclose(arquivo);

    arquivo = fopen("emp.txt", "r");

    if (arquivo == NULL)
    {
        return 0;
    }

    for (int i = 0; i < 3; i++)
    {
        Colaborador colaborador;

        fscanf(arquivo, "%s %d", colaborador.profissao, &colaborador.tempo_servico);

        printf("Profissão: %s\nTempo de serviço:%d\n", colaborador.profissao, colaborador.tempo_servico);
    }
    fclose(arquivo);
}
