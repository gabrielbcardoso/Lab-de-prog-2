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

int main()
{
    int opcao,m,l;
    char n[50];
    while(opcao !=6){
        printf("---Menu---/n");
        printf("1. Inserir aluno. /n");
        printf("2. Buscar aluno (por matricula). /n");
        printf("3. Imprimir alunos. /n");
        printf("4. Retirar aluno (por matrícula). /n");
        printf("5. Verifica se lista está vazia /n");
        printf("6. Sair. /n");


     switch (opcao)
     {
     case 1:
         printf("Digite a matricula");
         scanf("%i",&m);
         printf("Digite o nome");
         scanf("%s",&n[50]);
         l=insere_aluno(l,m,n[50]);

         break;
    case 2:
         printf();
         break;
    case 3:
         /* code */
         break;
    case 4:
         /* code */
         break;
    case 5:
         /* code */
         break;
    case 6:
         /* code */
         break;



     
     default:
     printf("Opcao invalida");
         break;
     }       






    }
    return 0;
}