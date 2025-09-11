#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int Criar(Lista *L){
	int i;
	L->inicio = NIL;
	L->dispo = 0;
	
	for(i=0; i<MAX; i++){
		L->A[i].prox = i+1;
	}
	L->A[i].prox = NIL;
	return 1;
}


int Cheia(Lista *L){
	return(L->dispo ==NIL);
}

int Vazia(Lista *L){
	return (L->inicio ==NIL);
	
}

int InserirOrdenada(Lista *L, tipo_elem v){
	int ant, atual, aux;
	
	if(Cheia(L)){
		return 0;
	}
	
	if(Vazia(L)){
		return (InserirInicio(L,v));
	}
	
	ant = NIL;
	atual = L->inicio;
	
	while(atual!=NIL && L->A[atual].info.chave<v.chave){
		ant = atual;
		atual = L->A[atual].prox;
	}
	
	if(ant ==NIL){
		return(InserirInicio(L,v));
	}	
	
	aux = L->dispo;
	L->dispo = L->A[aux].prox;
	L->A[aux].info = v;
	L->A[aux].prox = atual;
	L->A[ant].prox = aux;
	return 1;
	
}

int InserirInicio(Lista *L, tipo_elem v){
	int aux; //posição auxiliar, temporária
	
	if(Cheia(L)){
		return 0;
	}
	
	aux = L->dispo;
	L->dispo = L->A[L->dispo].prox;
	L->A[aux].info = v;
	L->A[aux].prox = L->inicio;
	L->inicio = aux;
	return 1;
	
}

int InserirFinal(Lista *L,  tipo_elem v){
	int p, aux;
	
	if(Cheia(L)){
		return 0;
	}
	
	//Buscar o último elmento
	
	if(Vazia(L)){
		return (InserirInicio(L,v));
	}
	p = L->inicio;
	while(L->A[p].prox!=NIL){
		p = L->A[p].prox;
	}
	aux = L->dispo;
	L->dispo = L->A[L->dispo].prox;
	L->A[aux].info = v;
	L->A[aux].prox = NIL;
	L->A[p].prox = aux;
	return 1;
}

int RemoverInicio(Lista *L){
	int aux;
	if(Vazia(L)){
		return 0;
	}
	
	aux = L->inicio;
	L->inicio = L->A[L->inicio].prox;
	L->A[aux].prox = L->dispo;
	L->dispo = aux;
	return 1;
}

int RemoverFinal(Lista *L){
	int atual, ant;
	
	if(Vazia(L)){
		return 0;
	}
	//Buscar o último elemento guardando o anterior
	ant = NIL;
	atual = L->inicio;
	while(L->A[atual].prox!=NIL){
		ant = atual;
		atual = L->A[atual].prox;
	}
	if(ant == NIL){
		L->inicio = NIL;
	}else{
		L->A[ant].prox = NIL;
	}
	L->A[atual].prox = L->dispo;
	L->dispo = atual;
	return 1;
	

}

int Remover(Lista *L, int chave){
	int ant, atual;
	if (Vazia(L)){
		return 0;
	}
	ant = NIL;
	atual = L->inicio;
	
	while(atual!=NIL && L->A[atual].info.chave!=chave){
		ant = atual;
		atual = L->A[atual].prox;
	}
	
	if(ant == NIL){
		return(RemoverInicio(L));
	}
	
	if(atual==NIL){
		return 0;
	}
	L->A[ant].prox = L->A[atual].prox;
	L->A[atual].prox = L->dispo;
	L->dispo = atual;
	return 1;
}

//Busca Sequencial
int Busca(Lista *L, int chave){
	int p;
	
	if(Vazia(L)){
		return 0;
	}
	
	p=L->inicio;
	while(p!=NIL && L->A[p].info.chave != chave){
		p= L->A[p].prox;
	}
	return (p!=NIL);
}


int Destruir(Lista *L){
	Criar(L);
}

void Exibir(Lista *L){
	int i;
	if(Vazia(L)){
		printf("Lista Vazia\n");
	}else{
		for(i=L->inicio; i!=NIL; i = L->A[i].prox){
			printf("%d ", L->A[i].info.chave);
		}
	}
}

int Tamanho(Lista *L){
	int cont, i;
	
	for(i=L->inicio, cont=0; i!=NIL; i=L->A[i].prox, cont++);
	return cont;
}
//int BuscaBinaria(Lista *L, int chave);

