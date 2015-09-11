#include"lista.h"
#include<stdio.h>
#include<stdlib.h>

struct node{ // no da lista, contem um ponteiro para insercao de um item nao especificado(void) e dois ponteiros para o proximo e para o no anterior
	void * elemento;
	struct node *proximo, *anterior;
};
typedef struct node Node;

struct lista{ // estrutura que controla a Lista, apontando para o primeiro(cabeca) e ultimo(cauda) no da lista.
	Node *cabeca;
	Node *cauda;
	int num;
};
typedef struct lista Lista;

void * createLista(){ //cria uma Lista, todos os ponteiros serao inicializados com valor nulo
	Lista *l = malloc(sizeof(Lista));
	if(l==NULL){
		printf("Erro na alocação da lista.\n");
		exit(0);
	}
	l->cabeca=NULL;
	l->cauda=NULL;
	l->num=0;
	return l;
}

int length(void *lista){
	Lista *l=lista;
	return l->num;
}

void *insert(void *lista, void* item){
	Lista *l = lista;
	Node *novo = malloc(sizeof(Node));
	if(novo == NULL){
		printf("Memoria Insuficiente!!\n");
		exit(0);
	}
	novo->elemento=item;
	novo->proximo=NULL;
	novo->anterior=NULL;
	if(listaVazia(l)){
		l->cabeca=novo;
	}
    else{
    	l->cauda->proximo=novo;
    	novo->anterior=l->cauda;
    }
    l->cauda = novo;
    l->num++;
    return l->cauda->elemento;
}

void remover(void *lista, int posic){
	Lista *l = lista;
	Node *primeiro=l->cabeca;
	int i=0;
	if(!listaVazia(l)){
		while(primeiro!=NULL && i!=posic){
			primeiro=primeiro->proximo;
			i++;
		}
		if(primeiro == NULL){
			return;
		}
		if(primeiro->anterior == NULL){
			l->cabeca=primeiro->proximo;
		}
		else{
			primeiro->anterior->proximo=primeiro->proximo;
		}
		if(primeiro->proximo == NULL){
			l->cauda=primeiro->anterior;
		}
		else{
			primeiro->proximo->anterior=primeiro->anterior;
		}
	}
	l->num--;
	free(primeiro->elemento);
	free(primeiro);
}

void * insertBefore(void *lista, int posic, void * item){
	Lista *l = lista;
	Node *percorre, *novo = malloc(sizeof(Node));
	percorre = l->cabeca;
	int i = 0;
	novo->elemento=item;
	novo->anterior=NULL;
	novo->proximo==NULL;
	if(novo == NULL){
		printf("Memoria Insuficiente!\n");
		exit(0);
	}
	while(percorre!=NULL && i!=posic){
		percorre=percorre->proximo;
		i++;
	}
	if(percorre == NULL){
		return;
	}
	else if (listaVazia(l)){
		l->cabeca=novo;
		l->cauda=novo;
	}
	else if (percorre->anterior == NULL){
		l->cabeca = novo;
	}
	else{
		percorre->anterior->proximo=novo;
		novo->anterior=percorre->anterior;
	}
	percorre->anterior=novo;
	novo->proximo=percorre;
	l->num++;
	return novo->elemento;
}

void * insertAfter(void *lista, int posic, void * item){
	Lista *l = lista;
	Node *percorre, *novo = malloc(sizeof(Node));
	percorre = l->cabeca;
	int i = 0;
	novo->elemento=item;
	novo->anterior=NULL;
	novo->proximo==NULL;
	if(novo == NULL){
		printf("Memoria Insuficiente!\n");
		exit(0);
	}
	while(percorre!=NULL && i!=posic){
		percorre=percorre->proximo;
		i++;
	}
	if(percorre == NULL){
		return;
	}
	if (listaVazia(l)){
		l->cabeca=novo;
		l->cauda=novo;
	}
	if (percorre->proximo == NULL){
		l->cauda = novo;
	}
	else{
		percorre->proximo->anterior=novo;
		novo->proximo=percorre->proximo;
	}
	novo->proximo=percorre->proximo;
	percorre->proximo=novo;
	novo->anterior=percorre;
	l->num++;
	posic = i+1;
	return novo->elemento;
}

void * get(void *lista, int posic){
	Lista *l = lista;
	Node *no = l->cabeca;
	int i=0;
	while(no!=NULL && i!=posic){
		no=no->proximo;
		i++;
	}
	if(no==NULL){
		return;
	}
	return no->elemento;
}

void * getFirst(void *lista){
	Lista *l=lista;
	return l->cabeca->elemento;
}

void * getLast(void *lista){
	Lista *l=lista;
	return l->cauda->elemento;
}

void * getPrevious(void *lista, int posic){
	Lista *l=lista;
	int i=0;
	Node *no=l->cabeca;
	while(no!=NULL && posic!=i){
		i++;
		no=no->proximo;
	}
	return no->anterior->elemento;
}

void * getNext(void *lista, int posic){
	Lista *l=lista;
	Node *no=l->cabeca;
	int i=0;
	while(no!=NULL && posic!=i){
		i++;
		no=no->proximo;
	}
	return no->proximo->elemento;
}

int listaVazia(void *lista)	{
	Lista *l = lista;
	return(l->cabeca == NULL);
}

int tamanhoLista(void *lista){
	Lista *l = lista;
	return (l->num);
}

void esvazia(void *lista){
	Lista *l = lista;
	int i;
	for(i=0;i<tamanhoLista(l);i++){
		remover(l,0);
	}
}
