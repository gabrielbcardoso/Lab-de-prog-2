#include <stdio.h>
#include <stdlib.h>
#include "Funcao.h"

typedef struct aluno
{
    int matricula;
    char nome[50];
} Aluno;

Aluno *ponteiro = NULL;

static ListaGen *insere_aluno(ListaGen *l, int x, char y[50])
{
    Aluno *p = (Aluno *)malloc(sizeof(Aluno));
    p->matricula = x;
    p->nome[50] = y;
    return lgen_insere(l, p);
}

void buscar(void *info, void *dado)
{
    Aluno *A = (Aluno *)info;
    Aluno *A2 = (Aluno *)dado;
    if (A->matricula == A2->matricula)
    {
        printf("O aluno existe \n");
        printf("Nome do aluno: %s\n", A->nome[50]);
        printf("Matricula do aluno: %i\n", A->matricula);
    }
    else
    {
        printf("O aluno nao existe");
    }
}

static void imprimir(void *info)
{
    Aluno *p = (Aluno *)info;
    printf("%i", p->matricula);
    printf("%s", p->nome[50]);
}

void estavazia(void *info)
{
    if (info == NULL)
    {
        printf("---Lista vazia---");
    }
    else
    {
        printf("---Lista possui alunos---");
    }
}

int main()
{
    int opcao, m, m1, l;
    char n[50];
    while (opcao != 6)
    {
        printf("---Menu---\n");
        printf("1. Inserir aluno. \n");
        printf("2. Buscar aluno (por matricula). \n");
        printf("3. Imprimir alunos. \n");
        printf("4. Retirar aluno (por matricula). \n");
        printf("5. Verifica se lista esta vazia \n");
        printf("6. Sair. \n");
        scanf("%i", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite a matricula: \n");
            scanf("%i", &m);
            printf("Digite o nome: \n");
            scanf("%s", &n[50]);
            l = insere_aluno(l, m, n[50]);

            break;
        case 2:
            printf("Digite a matricula: \n");
            scanf("%i", &m1);
            busca(l, buscar, &m1);

            break;
        case 3:
            lgen_percorre(ponteiro, imprimir);

            break;
        case 4:
            /* code */
            break;
        case 5:
            vazia(ponteiro, estavazia);
            break;
        case 6:
            printf("Saindo...");
            break;

        default:
            printf("Opcao invalida");
            break;
        }
    }
    return 0;
}