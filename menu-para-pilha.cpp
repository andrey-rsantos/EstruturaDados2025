#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO 5


int tamanho = 5;
int stack[TAMANHO];
int top = -1;



bool isEmpty(){
	/*bool isEmpty;

	 if(top == -1){
		isEmpty = true;
	} else{
		isEmpty = false;
	}

	return isEmpty;*/

	return top == -1;

}

// data = 10
void push(int data){

	if(top == TAMANHO - 1){
		printf("Pilha Cheia!");
		return;
	}

	top++;
	stack[top] = data;
}


int imprime_pilha(){

	if(isEmpty()){
		printf("Pilha Vazia");
		return 0;
	}
	int i;

	for(i = 0; i <= top; i++){
		printf("%d -> ", stack[i]);
	}

	printf("topo");
	return 1;
}


void topo(){
	if(isEmpty()){
		printf("Pilha Vazia!");
		return;
	}

	printf("\n\nTopo => %d", stack[top]);
}


int pop(){
	if(isEmpty()){
		printf("Pilha Vazia!");
		return -1; // Valor de erro para indicar que nada foi removido
	}

	int temp = stack[top];
	top--;
	return temp;
}



int main(){
	int opcao;
	int dado;
	int removido;

	while(1){
		printf("\n--- MENU PILHA ---\n");
		printf("1 - Empilhar (push)\n");
		printf("2 - Desempilhar (pop)\n");
		printf("3 - Imprimir pilha\n");
		printf("4 - Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);

		if(opcao == 1){
			printf("Informe um valor para empilhar: ");
			scanf("%d", &dado);
			push(dado);
			printf("Valor %d empilhado com sucesso!\n", dado);
		}
		else if(opcao == 2){
			// Guarda o estado da pilha antes de desempilhar
			bool eraVazia = isEmpty();
			removido = pop();

			// Só exibe o valor removido se a pilha não estava vazia antes
			if(!eraVazia){
				printf("Valor removido da pilha: %d\n", removido);
			}
		}
		else if(opcao == 3){
			imprime_pilha();
		}
		else if(opcao == 4){
			printf("Encerrando o programa...\n");
			break;
		}
		else{
			printf("Opcao invalida! Tente novamente.\n");
		}
	}
	return 0;
}
