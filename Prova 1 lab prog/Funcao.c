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

void lgen_percorre(ListaGen* l, void (*cb)(void*, void*), void* dado){
ListaGen *p;
for(p=l;p!=NULL;p=p->prox){
cb(p->info, dado);
}
}

