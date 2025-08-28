#include "lista.h"
#include <stdio.h>

int Criar(Lista *L){
	L->nelem = 0;
	return 1;
}
int Cheia(Lista *L){
	return(L->nelem == MAX);
}
int Vazia(Lista *L){
	return (L->nelem ==0);
	printf("A lista ta vazia");
	return 1;
}
int InserirOrdenada(Lista *L, tipo_elem v){
	int i;
	
	if(Cheia (L)){
		return 0;
	}
	if(Vazia(L)){
		return(InserirInicio(L, v));
	}
	
	for(i=L->nelem; i>0; i--){
		v.chave<L->A[i-1].chave;
		L->A[i] = L->A[i-1];
		L->A[i] = v;
		L->nelem++;
		return 1;
	}
}

int InserirInicio(Lista *L, tipo_elem v){
	int i;
	
	if(Cheia(L)){
		return 0;
	}
	for(i=L->nelem; i>0; i--){
		L->A[i] = L->A[i-1];
	}
	
	L->A[0] = v;
	L->nelem++;
	return 1;
}

int InserirFinal(Lista *L,  tipo_elem v){
	if(Cheia(L))
	return 0;
	
	L->A[L->nelem] = v;
	L->nelem++;
	return 1;
}
int RemoverInicio(Lista *L){
	int i;
	if(Vazia(L))
	return 0;
	L->nelem--;
	for(i=0; i<L->nelem; i++)
	L->A[i] = L->A[i+1];
	return 1;
	
}
int RemoverFinal(Lista *L){
	int i;
	if(Vazia(L)){
		return 0;
	}else{
		L->nelem--;
		printf("O elemento %d foi removido com sucesso\n", L->A[i].chave);
		return 1;
	}
}

int Remover(Lista *L, int chave){
	int i, k;
	
	if(Vazia(L))
	return 0;
	
	//Buscar o elemento a ser removido
	
	for(k=0; k<L->A[k].chave && chave!=L->A[k].chave; k++);
	if(k==L->nelem)
	return 0; //Não achou
	
	for(i=k; i<L->nelem-1; i++);
	L->A[i] = L->A[i+1];
	L->nelem--;
	return 1;	
	
}

int Busca(Lista *L, int chave){
	int i;
	
	if(Vazia(L))
	return 0;
	for(i=0; i<L->nelem && L->A[i].chave!= chave; i++)
	return (i<L->nelem);
}


int Destruir(Lista *L){
	L->nelem = 0;
	printf("A lista foi destruida\n");
	return 1;
}
void Exibir(Lista *L){
	int i;
	
	if(Vazia(L)){
		printf("Lista vazia\n");
	}else{
		for(i=0; i<L->nelem; i++){
			printf("%d ", L->A[i].chave);
		}
	}
	
}

int Tamanho(Lista *L){
	return (L->nelem);
}

int BuscaBinaria(Lista *L, int chave){
	int inicio = 0, fim = L->nelem-1;
	int meio;
	
	while(fim>=inicio){
		meio =(fim+inicio)/2;
		
		if(L->A[meio].chave==chave)
		return 1;
		
		if(L->A[meio].chave>chave)
		fim = meio-1;
		
		else
			inicio = meio+1;
			return 0;
	}
}
