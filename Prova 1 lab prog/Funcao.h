typedef struct listagen ListaGen;

ListaGen *lgen_insere(ListaGen *l, void *p);
void lgen_percorre(ListaGen *l, void (*cb)(void *));
void busca(ListaGen *l, void (*cb)(void *, void *), void *dado);
void lgen_verifica(ListaGen *l, void (*cb)(void *));
void vazia(ListaGen *l, void (*cb)(void *));
