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
		printf("0- Para sair.\n");
		printf("1- Inserir no inicio.\n");
	printf("2- Inserir no final.\n");
	//	printf("3- Inserir ordenado.\n");
		printf("4- Exibir.\n");
		printf("5- Destruir.\n");
		printf("6- Para verificar se a lista esta vazia.\n");
		printf("7- Para verifica se esta cheia.\n");
		printf("8- Para buscar elemento desejado.\n");
		//printf("9- Busca Binaria.\n");
		printf("10- Para remover no inicio.\n");
		//printf("11- Para remover no final.\n");
		//printf("12- Para remover elemento desejado.\n");
		//printf("13- Para ver o tamanho da lista.\n");
		
		
		printf("Digite a opcao: ");
		scanf("%d",&op);
		
		switch(op){
			case 1: //Inserir inicio / funcionando corretamente
			
			printf("Digite o valor: ");
			scanf("%d", &v.chave);
			
			if(InserirInicio(&L, v))
				printf("Elemento inserido com sucesso!\n");
			else
				printf("Nao foi possivel inserir.\n");
			break;
			
			case 2: //Inserir final / funcionando corretamente
			
			printf("Digite o valor: ");
			scanf("%d", &v.chave);
			if(InserirFinal(&L, v))
				printf("Elemento inserido com sucesso!\n");
			else
				printf("Nao foi possivel inserir.\n");
			break;
			
			/*case 3: //Inserir ordenada / funcionando corretamente
			
			printf("Digite o valor: ");
			scanf("%d", &v.chave);
			
			if(InserirOrdenada(&L, v))
				printf("Elemento inserido com sucesso!\n");
			else
				printf("Nao foi  possivel inserir.\n");
			break;*/
			
						
			case 4: //Exibir / funcionando corretamente
			Exibir(&L);
			break;
			
			/* case 5: //Destruir / funcionando corretamente
			if(Vazia(&L)){
				printf("Lista vazia, nada para ser destruido\n");
			}else{
				Destruir(&L);
			}
			break;  */
			
			case 6: //Vazia / funcionando corretamente
			
			if(Vazia(&L))
				printf("Vazia.\n");
			else
				printf("Nao esta vazia.\n");
			break;
			
			case 7: //Cheia / funcionando corretamente
			
			if(Cheia(&L))
				printf("Lista cheia!\n");
			else
				printf("Nao esta cheia.\n");
			break;
			
			case 8: //Busca / funcionando corretamente
			
			if(Vazia(&L)){
				printf("A lista esta vazia, preencha com elementos antes de fazer a busca.\n");
			}else{
				printf("Digite o elemento a ser buscado: ");
				scanf("%d", &chave);
				
				int posicao = Busca(&L, chave);
				
				if(posicao != -1){
					printf("Elemento '%d' encontrado com sucesso!\n", chave);
				}else{
					printf("Elemento nao encontrado.\n");
				}
			}
			break;
			
			 /* //Função extra
			case 9: //Busca binaria / funconando corretamente
			
			if(Vazia(&L)){
				printf("A lista esta vazia, insira elementos para fazer a busca binaria.\n");
			}else{
				printf("Digite o elemento a ser buscado: ");
				scanf("%d", &chave);
				
				if(BuscaBinaria(&L, chave)){
					printf("Elemento '%d' encontrado com sucesso!\n", chave);
				}else{
					printf("Elemento nao encontrado.");
				}
			}
				
			break; */
				
			case 10: //Remove no início / funcionando corretamente
				/*if(Vazia(&L)){
					printf("Lista vazia. Insira elementos para que seja possivel a remocao.\n");*/
				if(RemoverInicio(&L)){
					printf("Elemento removido com sucesso\n");
				}else{
					printf("Elemento não removido\n");
				}
			break;
			
			/*case 11: //Remove no final / funcionando corretamente
			
			if(Vazia(&L)){
				printf("Lista vazia. Insira elementos para que seja possivel a remocao.\n");
			}else{
				RemoverFinal(&L);
			}
			break;
			
			case 12: //Remover elemento específico
			if(Vazia(&L)){
				printf("Lista vazia. Insira elementos para que seja possivel a remocao.\n");
			}else{
				printf("Digite o elemento a ser removido: ");
				scanf("%d", &chave);
				Remover(&L, chave);
			}
			break; 
			
			case 13: //tamanho da lista
			Tamanho(&L);
			break; */
	}
		
		printf("\n\n");
		system("pause");
	}while(op!=0);
	Destruir(&L); 
	
	
	
	return 0;
}
