#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct{
	int matricula;
	char sobrenome[50];
	int ano;
}cadastro;


int main(int argc, char *argv[]) {
	cadastro *a;
	int N, i; //numero de alunos
	
	printf("Cadastro de alunos\n\n");
	printf("Digite o numero de alunos a serem cadastrados: ");
	scanf("%d", &N);
	
	//alocação dinâmica, usando calloc ou malloc
	a = (cadastro *)malloc(N*sizeof(cadastro));	
	
	for(i=0; i<N; i++){
		printf("Aluno %d ", i+1);
		printf("Sobrenome do aluno: ");
		scanf("%s", &a[i].sobrenome);
		printf("Matricula: ");
		scanf("%d", &a[i].matricula);
		printf("Ano: ");
		scanf("%d", &a[i].ano);
	}
	
	for(i=0; i<N; i++){
		printf("Aluno %d, Sobrenome: %s, Matricula: %d, Ano: %d \n", i+1, a[i].sobrenome, a[i].matricula, a[i].ano);
	}
		
	
	system("pause");
	return 0;
}
