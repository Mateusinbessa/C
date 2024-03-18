#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 10
#define SUCESS 1
#define ERROR 0

typedef struct aluno
{
    int matricula;
    char nome[101];
    float nota;
} Aluno;

void inicializaVetor(Aluno **alunos);
void imprimeVetor(Aluno **alunos);
int cadastraAluno(Aluno **alunos);
int excluir(Aluno **alunos, int matricula);

int main(void)
{
    // Meu array é um array de ponteiros que apontam para um lugar memoria onde existem estruturas do tipo ALUNO
    Aluno *alunos[10];
    inicializaVetor(alunos);
    imprimeVetor(alunos);
    if (cadastraAluno(alunos) == SUCESS)
    {
        printf("Aluno cadastrado com sucesso\n");
    }
    else
    {
        printf("Problema ao cadastrar\n");
    }
    if (cadastraAluno(alunos) == SUCESS)
    {
        printf("Aluno cadastrado com sucesso\n");
    }
    else
    {
        printf("Problema ao cadastrar\n");
    }
    imprimeVetor(alunos);
    if (excluir(alunos, 2) == SUCESS)
    {
        printf("Aluno excluido\n");
    }
    else
    {
        printf("Aluno não encontrado\n");
    }
    imprimeVetor(alunos);
    return 0;
}

void inicializaVetor(Aluno **alunos)
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        alunos[i] = NULL;
    }
}

void imprimeVetor(Aluno **alunos)
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (alunos[i] != NULL) // TODO: Eu poderia depois de checar se a referência de memória existe, checar se a matricula é != 0 !!!
        {
            printf("Matricula: %d\n", alunos[i]->matricula);
            printf("Nome: %s\n", alunos[i]->nome);
            printf("Nota: %f\n\n", alunos[i]->nota);
        }
    }
}

int cadastraAluno(Aluno **alunos)
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (alunos[i] == NULL) // Essa checagem é extremamente necessária, eu só quero cadastrar novos alunos onde existe memória livre.
        {
            alunos[i] = (Aluno *)malloc(sizeof(Aluno)); // Alocando a memória dinâmicamente para um novo aluno.
            printf("Digite a Matricula: ");
            scanf("%d", &alunos[i]->matricula);
            printf("Digite a Nota: ");
            scanf("%f", &alunos[i]->nota);
            printf("Digite o Nome: ");
            scanf(" %100[^\n]", alunos[i]->nome);
            return SUCESS;
        }
    }
    return ERROR;
}

int excluir(Aluno **alunos, int matricula)
{
    for (int i = 0; i < ARR_SIZE; i++)
    {
        if (alunos[i]->matricula == matricula)
        {
            free(alunos[i]);
            alunos[i] = NULL;
            return SUCESS;
        }
    }
    return ERROR;
}