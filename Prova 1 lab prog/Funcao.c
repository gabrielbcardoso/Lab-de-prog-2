/* Deve possuir as seguintes funções:
1. Cria Lista;
2. Insere na lista (no início);
3. Percorre a lista (considerando as situações de busca, impressão e retirada de elementos);
4. Verifica se a lista está vazia;
5. Libera a lista (memória alocada); */

#include <stdio.h>
#include <stdlib.h>

struct listagen
{
    void *info;
    struct listagen *prox;
};
typedef struct listagen ListaGen;

ListaGen *lgen_insere(ListaGen *l, void *p)
{
    ListaGen *n = (ListaGen *)malloc(sizeof(ListaGen));
    n->info = p;
    n->prox = l;
    return n;
}

void lgen_percorre(ListaGen *l, void (*cb)(void *))
{
    ListaGen *p;
    for (p = l; p != NULL; p = p->prox)
    {
        cb(p->info);
    }
}

void busca(ListaGen *l, void (*cb)(void *, void *), void *dado)
{
    ListaGen *p;
    for (p = l; p != NULL; p = p->prox)
    {
        cb(p->info, dado);
    }
}

void lgen_verifica(ListaGen *l, void (*cb)(void *))
{
    cb(l);
}

void vazia(ListaGen *l, void (*cb)(void *))
{
    cb(l);
}