#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int Criar(Lista *L){
	L->head = NULL;
	return 1;
	
}

//não é necessário
/*int Cheia(Lista *L){
}*/

int Vazia(Lista *L){
	return(L->head == NULL);
}

int InserirOrdenada(Lista *L, tipo_elem v){
	if(Vazia(L)){
		return (InserirInicio(L,v));
	}
	
	No *p = L->head;
	No *q = NULL, *k;
	
	while(p!=NULL && p->info.chave< v.chave){
		q = p;
		p = p->prox;
	}
	
	if(q==NULL){
		return(InserirInicio(L,v));
	}
	
	k = (No*)malloc(sizeof(No));
	
	if(!k){
		return 0;
	}
	k->info = v;
	q->prox = k;
	return 1;
	
}

int InserirInicio(Lista *L, tipo_elem v){
	No *p;
	p=(No*)malloc(sizeof(No));
	
	if(!p){
		return 0;
	}
	
	p->info =v;
	p->prox = L->head;
	L->head = p;
	return 1;
	
}

int InserirFinal(Lista *L,  tipo_elem v){
	if(Vazia(L)){
		return(InserirInicio(L,v));
	}
	
	No *p = L->head;
	No *q;
	
	while(p->prox!=NULL){
		p=p->prox;
	}
	
	q=(No*)malloc(sizeof(No));
	
	if(!q){
		return 0;
	} 
	
	q->info = v;
	q->prox =NULL;
	p->prox=q;
	return 1;
}

int RemoverInicio(Lista *L){
	if(Vazia(L)){
		return 0;
	}
	
	No *p = L->head;
	L->head = p->prox;
	free(p);
	
	return 1;
}
//metodo tradicional
int RemoverFinal(Lista *L){
	if(Vazia(L)){
		return 0;
	}
	
	No *p  = L->head;
	No *q = NULL;
	
	while(p->prox!=NULL){
		q = p;
		p = p->prox;
	}
	
	if(q==NULL){
		return(RemoverInicio(L));
	}
	
	q->prox==NULL;
	free(p);
	return 1;
}
		


//Removendo do final de maneira recursiva
/*int RemoverFinalRec(Lista *L, No **q, No **p){
	
	if(*p==NULL){
		return 0;
	}
	
	if((*p)->prox == NULL){
		if(*q!=NULL){
			(*q)->prox=NULL;
		}else{
			L->head=NULL;
		}
		free(*p);
		return 1;
	}
	
	return (RemoverFinalRec(L, &(*p), &(*p)->prox));
}*/

//retornando função inserir no final recursivamente
/*int RemoverFinal(Lista *L){
	No *q, *p;
	
	q = NULL;
	p = L->head;
	
	if(Vazia(L)){
		return 0;
	}
	
	return(RemoverFinalRec(L, &q, &p));
}*/

int Remover(Lista *L, int chave){
	if(Vazia(L)){
		return 0;
	}
	
	No *q = NULL;
	No *p = L->head;
	
	while(p!=NULL && p->info.chave!=chave){
		q=p;
		p=p->prox;
	}
	
	if(p==NULL){
		return 0;
	}
	
	if(q==NULL){
		return(RemoverInicio(L));
		q->prox = p->prox;
		free(p);
		return 1;
	}

}

//Busca Sequencial
int Busca(Lista *L, int chave){
	
}

//método convencional
int Destruir(Lista *L){
	No *p = L->head;
	
	while(p){
		L->head =(L->head->prox);
		free(p);
		p=L->head;
	}
} 

void Exibir(Lista *L){
	No *p;
	
	if(Vazia(L)){
		printf("Lista Vazia\n");
	}else{
		for(p=L->head; p!=NULL; p=p->prox){
			printf("%d ", p->info.chave);
		}
	}//fim do else
}//fim da função exibir


//metodo convencional
int Tamanho(Lista *L){
	int cont;
	No *p;
	
	for(p=L->head, cont=0; p!=NULL; p=p->prox, cont++);
	printf("A lista contem: %d elementos\n", cont);
		return cont;
}

//recursivamente
/*int TamanhoRec(No *p){
	if(p==NULL){
		return 0;
	}
	return (1+TamanhoRec(p->prox));
}*/

//metodo de mostrar o tamanho retornando/chamando a função de tamanho recursivamente
/*int Tam(Lista *L){
	return (TamanhoRec(L->head));
}*/

//metodo recursivo
/*void DestruirRec(No **p){
	if((*p)!=NULL){
		No *q = (*p)->prox;
		free(*p);
		DestruirRec(&q);
	}
}*/


//metodo de detruir retornando/chamando a função de destruir recursivamente
/*void Destruir(Lista *L){
	DestruirRec(&(L->head));
}*/

//int BuscaBinaria(Lista *L, int chave);

