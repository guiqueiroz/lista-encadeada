#ifndef lista_H
#define lista_H

void * createLista();
int length(void *lista);
void * insert(void *lista, void *item);
void remover(void *lista, int posic);
void * get(void *lista, int posic);
void * insertBefore(void *lista, int posic, void * item);
void * insertAfter(void *lista, int posic, void * item);
void * getLast(void *lista);
void * getPrevious(void *lista, int posic);
void * getNext(void *lista, int posic);
int listaVazia(void *lista);
int tamanhoLista(void *lista);
void esvazia(void *lista);

#endif

