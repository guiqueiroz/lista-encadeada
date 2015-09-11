#include"lista.h"
#include<stdio.h>
#include<stdlib.h>
#define MAX 5000000

struct node{
	void *elemento;
	int proximo;
};
typedef struct node Node;

struct lista{
	Node conteudo[MAX];
	int cabeca, tamanho, livre;
};
typedef struct lista Lista;

int listaVazia(void *lista){
	Lista *l = lista;
	if(l->tamanho == 0){
		return 1;
	}
	else{
		return 0;
	}

}

int tamanhoLista(void *lista){
	Lista *l = lista;
	return (l->tamanho);
}
int listaCheia(void *lista){
	Lista *l = lista;
	if(l->tamanho == MAX){
		return 1;
	}
	else{
		return 0;
	}

}

void * createLista(){
	Lista *l = malloc(sizeof(Lista));
	if(l == NULL){
		printf("Erro na alocação da lista\n");
		exit(0);
	}
	int i=0;
	while(i<MAX){
		l->conteudo[i].elemento=NULL;
		l->conteudo[i].proximo=i+1;
		i++;
	}
	l->cabeca=-1;
	l->tamanho=0;
	l->livre=0;
	return l;
}

int lenght(void *lista){
	Lista *l = lista;
	return l->tamanho;
}

void * insert(void *lista, void *item){
	Lista *l = lista;
	if(!listaCheia(l)){
        if(listaVazia(l)){
			l->cabeca=l->livre;
		}
		l->conteudo[l->livre].elemento=item;
		l->livre=l->conteudo[l->livre].proximo;
		l->tamanho++;
		return l->conteudo[l->livre-1].elemento;
	}
	else
        return 0;
}

void remover(void *lista, int posic){
	Lista *l = lista;
	int i=0, item, ant;
	ant = l->cabeca;
	if(listaVazia(l)){
		return;
	}
	if(posic==0){
		l->cabeca=l->conteudo[l->cabeca].proximo;
		l->tamanho--;
		l->livre=0;
	}
	else{
		while(i!=posic-1){
			ant=l->conteudo[ant].proximo;
			i++;
		}
	}
	item = l->conteudo[ant].proximo;
	l->conteudo[ant].proximo = l->conteudo[item].proximo;
	l->livre = item;
	l->tamanho--;
}

void * get(void *lista, int posic){
	Lista *l = lista;
	int i=0, aux=l->cabeca;
	while(i<posic){
		aux=l->conteudo[aux].proximo;
		i++;
	}
	return l->conteudo[aux].elemento;
}

void * insertBefore(void *lista,int posic, void *item){
	Lista *l = lista;
	int aux = l->cabeca, i=0, ant, aux2;

	while(i<posic){
		ant = aux;
		aux=l->conteudo[aux].proximo;
		i++;
	}
	if(posic == 0){
		l->cabeca=l->livre;
		l->conteudo[l->livre].elemento = item;
		l->conteudo[l->livre].proximo = aux;
		l->tamanho++;
		return l->conteudo[l->livre].elemento;
	}
	l->conteudo[ant].proximo=l->livre;
	l->conteudo[l->livre].elemento = item;
	aux2=l->conteudo[l->livre].proximo;
	l->conteudo[l->livre].proximo = aux;
	l->livre=aux2;
	l->tamanho++;
	return l->conteudo[l->conteudo[ant].proximo].elemento;
}

void * insertAfter(void *lista, int posic, void *item){
	Lista *l = lista;
	int aux = l->cabeca, i = 0, ant, aux2;

	while(i<posic){
		aux = l->conteudo[aux].proximo;
		i++;
	}
	l->conteudo[l->livre].elemento=item;
	ant = l->conteudo[aux].proximo;
	l->conteudo[aux].proximo = l->livre;
	aux2 = l->livre;
	l->livre = l->conteudo[l->livre].proximo;
	l->conteudo[aux2].proximo=ant;
	l->tamanho++;
	return l->conteudo[aux2].elemento;
}

void * getFirst(void *lista){
	Lista *l = lista;
	if(!listaVazia(l)){
		return l->conteudo[l->cabeca].elemento;
	}
	return NULL;
}

void * getLast(void *lista){
	Lista *l = lista;
	int posic=l->cabeca, ant;
	if(!listaVazia(l)){
		while(l->conteudo[posic].elemento!=NULL){
			ant = posic;
			posic = l->conteudo[posic].proximo;
		}
		return l->conteudo[ant].elemento;
	}
	return NULL;
}

void * getPrevious(void *lista, int posic){
	Lista *l = lista;
	int k=l->cabeca, ant, i=0;
	if(!listaVazia(l)){
		while(i<posic){
			ant = k;
			k=l->conteudo[k].proximo;
			i++;
		}
		return l->conteudo[ant].elemento;
	}
	return NULL;
}

void * getNext(void *lista, int posic){
	Lista *l = lista;
	int k=l->cabeca, i=0;
	if(!listaVazia(l)){
		while(i<=posic){
			k=l->conteudo[k].proximo;
			i++;
		}
		return l->conteudo[k].elemento;
	}
	return NULL;
}

void esvazia(void *lista){
	Lista *l = lista;
	int i;
	for(i=0;i<tamanhoLista(l);i++){
		remover(l,0);
	}
}
