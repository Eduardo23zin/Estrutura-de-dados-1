
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int chave;
}tipo_elem;

typedef struct no{
	tipo_elem info; //dado
	struct no *prox; //próximo elemento
}No;
//Estrutura de dados

typedef struct{
	No *head;
}Lista;

int Criar(Lista *L);
//int Cheia(Lista *L);
int Vazia(Lista *L);
int InserirOrdenada(Lista *L, tipo_elem v);
int InserirInicio(Lista *L, tipo_elem v);
int InserirFinal(Lista *L,  tipo_elem v);
int RemoverInicio(Lista *L);
int RemoverFinal(Lista *L);
//int RemoverFinalRec(Lista *L, No** q, No** p);
int Remover(Lista *L, int chave);
int Busca(Lista *L, int chave);
int Destruir(Lista *L);
//void Destruir(Lista *L);
//void DestruirRec(No **p);
void Exibir(Lista *L);
int Tamanho(Lista *L);

//int BuscaBinaria(Lista *L, int chave);

