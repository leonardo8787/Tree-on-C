#include "aula.hpp"

Tree* CreateTree(){
	return NULL;
}

void insertItem(Tree **t, Record r){

	if(*t == NULL){

		*t = (Tree*)malloc(sizeof(Tree)); // record + filho esquerdo + filho direito
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->reg = r;
		printf("NULL\n");

	} else {

		if(r.value < (*t)->reg.value){
			insertItem(&(*t)->esq, r);
			//printf("esquerda: %d\n",r.value);
		} else if(r.value > (*t)->reg.value){
			insertItem(&(*t)->dir, r);
			//printf("direita: %d\n",r.value);
		}
	}
}

void pesquisa(Tree **t, Tree **aux, Record  r){
	printf(&(*t)->esq, r);
	printf(&(*t)->dir, r);
}

int main(){

	int num;
	Tree *t;
	Record r;

	printf("\n\n===Árvore====\n");
	printf("autor: Leonardo Campos\n\n\n");

	do{

		printf("Digite um valor, ou 0 para sair: \n");
		scanf("%d", &num);
		r.value = num;
		t = CreateTree();
		insertItem(&t, r);
		pesquisa();

	}while(num != 0);

	printf("\nFim...\n");
	return 0;
	
}

