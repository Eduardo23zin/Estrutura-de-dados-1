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
}
int InserirOrdenada(Lista *L, tipo_elem v){
	int i = L->nelem;
	
	if(Cheia (L)){
		return 0;
	}
	
	while(i>0 && v.chave < L->A[i-1].chave){
		//se ascondições forem verdade, L->A[i-1] é maior que v e tem que se deslocar para a direita
		L->A[i] = L->A[i-1];
		i--; //movendo o espaço vazio uma posição para a esquerda para continuar a verificação
		
	}
	L->A[i] = v; //achou a posição certa
	L->nelem++; //atualizando o tamanho da lista
	return 1;
}

int InserirInicio(Lista *L, tipo_elem v){
	
	if(Cheia(L)){
		return 0;
	}
	
	//reutilizando a função de inserir ordenada para evitar problemas e manter a ordem.
	return(InserirOrdenada(L, v));
	
	//inserir inicio
	/*for(i=L->nelem; i>0; i--){
		L->A[i] = L->A[i-1];
	}
	
	L->A[0] = v;
	L->nelem++;
	return 1; */
}

int InserirFinal(Lista *L,  tipo_elem v){

	if(Cheia(L))
	return 0;
	
	//reutilizando a função de inserir ordenada para evitar problemas e manter a ordem.
	return(InserirOrdenada(L, v));
	
	/*//inserir no final
	L->A[L->nelem] = v;
	L->nelem++;
	return 1;*/
}

int RemoverInicio(Lista *L){
	int i;
	tipo_elem elementoRemovido; //variavel temporaria que guarda a primeira posição do vetor para depois imprimir o valor removido
	if(Vazia(L)){
		return 0;
	}
	elementoRemovido = L->A[0]; //atribuindo o valor da posicao 0
	
	//diminuindo o tamanho da lista	
	L->nelem--;
	for(i=0; i<L->nelem; i++){
	L->A[i] = L->A[i+1];
	}
	printf("O elemento %d foi removido com sucesso\n", elementoRemovido.chave);
	return 1;
	
}

int RemoverFinal(Lista *L){
	if(Vazia(L)){
		return 0;
	}else{
		L->nelem--; //diminuindo o tamanho da lista
		printf("O elemento %d foi removido com sucesso\n", L->A[L->nelem].chave);
		return 1;
	}
}

int Remover(Lista *L, int chave){
	int i, k;
	k = Busca(L, chave); //reutilizando a função de busca

	if(Vazia(L)){
		return 0;
	}
	
	if(k == -1){
		printf("Elemento não encotrado.\n");
		return 0; // elemento não encontrado
	}else{
		//deslocamento
		for(i=k; i<L->nelem-1; i++){
			L->A[i] = L->A[i+1];
		}
	}
	
	printf("Elemento '%d', removido com sucesso!\n", chave);
	
	L->nelem--; //diminuindo/atualizando o tamanho da lista
	return 1;	
	
}

int Busca(Lista *L, int chave){
	int i;
	
	for(i=0; i<L->nelem && L->A[i].chave!= chave; i++);
	
	if(i<L->nelem){
		return i; //ecnontrou a chave e retorna a posição;
	}else{
		return -1; //não encontrou a chave
	}

}


int Destruir(Lista *L){
	L->nelem = 0;
	printf("A lista foi destruida\n");
	return 1;
}
void Exibir(Lista *L){
	int i;
	
	if(Vazia(L)){
		printf("Lista vazia, nada para exibir. \n");
	}else{
		for(i=0; i<L->nelem; i++){
			printf("%d ", L->A[i].chave);
		}
	}
	
}

int Tamanho(Lista *L){
	printf("A lista contem %d elementos \n", L->nelem);
	return (L->nelem);
}

int BuscaBinaria(Lista *L, int chave){
	int inicio = 0, fim = L->nelem-1;
	int meio;
	
	while(fim>=inicio){
		meio =(fim+inicio)/2;
		
		//encontrou, fim da função
		if(L->A[meio].chave==chave){
			return 1;
		}
		
		if(L->A[meio].chave>chave){
			fim = meio-1; //descarta a metade direita do vetor
		}else{
			inicio = meio+1; //descarta a metade esquerda do vetor
		}
	}
	
	return 0;
}
