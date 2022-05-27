#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    strcpy(p->nome, y);
    return lgen_insere(l, p);
}

void buscar(void *info, void *dado)
{
    Aluno *A = (Aluno *)info;
    Aluno *A2 = (Aluno *)dado;
    if (A->matricula == A2->matricula)
    {

        printf("Nome do aluno: %s\n", A->nome);
        printf("Matricula do aluno: %i\n", A->matricula);
    }
    /*else
    {
        printf("O aluno nao existe");
    }*/
}

static void imprimir(void *info)
{
    Aluno *p = (Aluno *)info;
    printf("Matricula: %i\n", p->matricula);
    printf("Nome: ");
    puts(p->nome);
}

void estavazia(void *info)
{
    if (info == NULL)
    {
        printf("---Lista vazia---\n");
    }
    else
    {
        printf("---Lista possui alunos---\n");
    }
}

static void retirar(void *info, int i){
    Aluno *A = (Aluno *)info;

    if (A->matricula == i){
        free(A);

    }


}

int main()
{
    int opcao = 0, m, m1;
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
            fflush(stdin);
            printf("Digite o nome: \n");
            scanf("%s", &n);
            fflush(stdin);
            ponteiro = insere_aluno(ponteiro, m, n);

            break;
        case 2:
            printf("Digite a matricula: \n");
            scanf("%i", &m1);

            busca(ponteiro, buscar, &m1);
            fflush(stdin);
            break;
        case 3:
            lgen_percorre(ponteiro, imprimir);
            fflush(stdin);

            break;
        case 4:
            /* code */
            break;
        case 5:
            vazia(ponteiro, estavazia);
            fflush(stdin);
            break;
        case 6:
            printf("Saindo...");
            libera(ponteiro);
            break;

        default:
            printf("Opcao invalida");
            break;
        }
    }
    return 0;
}