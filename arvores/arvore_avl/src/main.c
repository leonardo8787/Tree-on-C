#include "avl.h"
#include "avl.h"

int main(){

	system("cls || clear");
	
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int num;

	printf("\nÁrvore AVL em C\n\n");
	printf("autor: Leonardo Campos\n");
	
	do{
	    printf("Escolha uma opção: \n");
	    printf("0 - sair\n");
	    printf("1 - inserir valor\n");
	    printf("2 - remover\n");
	    printf("3 - imprimir árvore\n");
	    printf("4 - limpar tela\n");
	    scanf("%d", &num);
	    switch(num){
	        case 0:
	            printf("\nSaindo...\n");
	            return 0;
	            break;
	        case 1:
	            printf("\nDigite um valor: ");
	            scanf("%d", &num);
	            r.key = num;
	            r.value = 1;
	            insertTree(&raiz, r);
	            break;
	        case 2:
	            printf("\nDigite um número para remover: \n");
	            scanf("%d", &num);
	            r.key = num;
	            removeTree(&raiz, r);
	            break;
	        case 3:
	            printf("\nÁrvore\n");
	            printf("[");
	            showTreeInOrder(raiz);
	            printf("]");
	            showTreeInOrder(aux);
	            printf("\n");
	            break;
	        case 4:
	           	system("cls || clear");
	        default:
	            printf("\nEscolha uma opção válida!\n");
	            break;
	    }
	}while(num);

    return 0;
}
