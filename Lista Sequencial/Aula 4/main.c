#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int op;
	Lista L;
	tipo_elem v;
	int chave;
	
	
	Criar(&L);
	do{
		system("cls");
		printf("1- Inserir no inicio\n");
		printf("2- Inserir no final\n");
		printf("3- Inserir ordenado\n");
		printf("4- Exibir\n");
		printf("5- Destruir\n");
		printf("6- Para verificar se a lista esta vazia\n");
		printf("7- Para verifica se esta cheia\n");
		printf("8- Para buscar elemento desejado\n");
		printf("9- Busca Binaria\n");
		printf("10- Para remover no inicio\n");
		printf("11- Para remover no final\n");
		printf("12- Para remover elemento desejado\n");
		printf("0-'' Sair\n");
		
		printf("Digite a opcao: ");
		scanf("%d",&op);
		
		switch(op){
			case 1: //Inserir inicio
			printf("Digite o valor: ");
			scanf("%d", &v.chave);
			
			if(InserirInicio(&L, v))
			printf("Elemento inserido com sucesso \n");
			else
			printf("Nao foi possivel inserir \n");
			break;
			
			case 2: //Inserir final
			printf("Digite o valor: ");
			scanf("%d", &v.chave);
			if(InserirFinal(&L, v))
			printf("Elemento inserido com sucesso\n");
			else
			printf("Nao foi possivel inserir \n");
			break;
			
			case 4: //Exibir
			Exibir(&L);
			break;
			
			case 5: //Destruir
			Destruir(&L);
			break;
			
			case 6: //Vazia
			if(Vazia(&L))
			printf("Vazia\n");
			else
			printf("Nao esta vazia\n");
			break;
			
			case 7: //Cheia
			if(Cheia(&L))
			printf("Lista cheia\n");
			else
			printf("Nao esta cheia\n");
			break;
			
			case 8:
				BuscaBinaria(&L, chave);
				break;
				
			case 9:
			RemoverFinal(&L);
			break;	
		}
		
		printf("\n\n");
		system("pause");
	}while(op!=0);
	
	Destruir(&L);
	
	
	return 0;
}
