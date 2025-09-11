#define MAX 50
#define NIL -1
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int chave;
}tipo_elem;

typedef struct{
	tipo_elem info; //dado
	int *prox; //próximo elemento
}No;
//Estrutura de dados

typedef struct{
	No A[MAX];
	int inicio, dispo;
}Lista;

int Criar(Lista *L);
int Cheia(Lista *L);
int Vazia(Lista *L);
int InserirOrdenada(Lista *L, tipo_elem v);
int InserirInicio(Lista *L, tipo_elem v);
int InserirFinal(Lista *L,  tipo_elem v);
int RemoverInicio(Lista *L);
int RemoverFinal(Lista *L);
int Remover(Lista *L, int chave);
int Busca(Lista *L, int chave);
int Destruir(Lista *L);
void Exibir(Lista *L);
int Tamanho(Lista *L);
//int BuscaBinaria(Lista *L, int chave);

