#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define false -1
#define true 1
typedef int bool;
typedef struct registro{
	int eli;
	struct registro *prox;
}ELEMENTO;
typedef struct {
	ELEMENTO *inicio;
}LISTA;
void incializar(LISTA *l){
	l->inicio = NULL;
}
int tamanho(LISTA *l){
	ELEMENTO *end = l->inicio;
	int tam=0;
	while(end != NULL){
		tam++;
		end = end->prox;
	}
	return tam;
}
void imprime(LISTA *l){
	ELEMENTO *end = l->inicio;
	printf("lista : ");
	while (end != NULL){
		printf("%i", end->eli);
		end = end->prox;
	}
}
ELEMENTO* buscaAux(LISTA *l, int e ,ELEMENTO **ant){
	*ant = NULL;
	ELEMENTO *i = l->inicio;
	while(i != NULL && i->eli < e){
		if(i->eli == e) return i;
		*ant = i;
		i = i->prox;
	}
	return NULL;
}
int inserir(LISTA *l, int e){
	ELEMENTO *ant;
	int eliabe = e;
	ELEMENTO *i = buscaAux(l,eliabe,&ant);
	if(i !=NULL) return false;
	i = (ELEMENTO*)malloc(sizeof(ELEMENTO));
	i->eli = e;
	if(ant == NULL){
		i->prox = l->inicio;
		l->inicio = i;
	}
	else {
		i->prox = ant->prox;
		ant->prox = i;
	}
	return true;
}
bool exclui(LISTA *l, int e){
	ELEMENTO *ant;
	ELEMENTO *i = buscaAux(l,e,&ant);
	if(i==NULL)return false;
	if(ant == NULL){
		l->inicio = i->prox;
	}
	else ant->prox = i->prox;
	free(i);
}
void reiniciar(LISTA *l){
	ELEMENTO *i = l->inicio;
	while(i != NULL){
		ELEMENTO *apaga = i;
		i = i->prox;
		free(apaga);
	}



}
int main (){

	return 0;
}













