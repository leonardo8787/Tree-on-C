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

void pesquisa(Tree **t, Tree **aux, Record r){
	if(*t == NULL){
		printf("[Erro]: No não encontrado!\n");
		return; //quebra a recursão
	}
	if((*t)->reg.key > r.key){
		pesquisa(&(*t)->esq,aux, r); return;
	}
	if((*t)->reg.key < r.key){
		pesquisa(&(*t)->dir,aux, r); return;
	}
	*aux = *t;
}

int main(Tree **aux){

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
		pesquisa(&t, &aux, r);

	}while(num != 0);

	printf("\nFim...\n");
	return 0;
	
}





// método interativo
/*
void pesquisa(Tree **t, Tree **aux, Record r){
	while((*t)->reg.key > r.key || (*t)->reg.key < r.key || (*t)->reg.key != NULL){
		if((*t)->reg.key > r.key){
			(*t) = (*t)->esq;
		}
		if((*t)->reg.key < r.key){
			(*t) = (*t)->dir;
		}
	}
	if(*t != NULL){
		*aux = *t;
	}
}*/