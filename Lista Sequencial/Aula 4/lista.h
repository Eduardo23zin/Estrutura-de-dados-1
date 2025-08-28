#define MAX 50
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int chave;
}tipo_elem;

typedef struct{
	tipo_elem A[MAX];
	int nelem; //numero de elementos
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
int BuscaBinaria(Lista *L, int chave);

