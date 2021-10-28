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

void antecessor(Tree **t, Tree *aux){
	if((*t)->dir != NULL){
		antecessor(&(*t)->dir, aux);
		return;
	}
	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->esq;
}

void removeItem(Tree **t, Record r){
	if(*t == NULL){
		printf("Erro!!!");
		return;
	}

	if((*t)->reg.key > r.key){
		removeItem(&(*t)->esq, r); return;
	}
	if((*t)->reg.key < r.key){
		removeItem(&(*t)->dir, r); return;
	}

	if((*t)->dir == NULL){
		aux = *t;
		*t = (*t)->esq;
		free(aux);
		return;
	}

	if((*t)->esq != NULL){
		antecessor(&(*t)->esq, *t);
	}
}

void inordem(Tree *t){
	inordem(t->esq);
	printf("%d", t->reg.key);
	inordem(t->dir);
}

void preordem(Tree *t){
	printf("%d", t->reg.key);
	preordem(t->esq);
	preordem(t->dir);
}

void posordem(Tree *t){
	posordem(t->esq);
	posordem(t->dir);
	printf("%d", t->reg.key);
}

int main(){

	int num;
	Tree *t, *aux;
	Record r;

	printf("\n\n===Árvore====\n");
	printf("autor: Leonardo Campos\n\n\n");

	do{

		printf("Digite um valor, ou 0 para sair: \n");
		scanf("%d", &num);
		r.value = num;
		t = CreateTree();
		insertItem(&t, r);
		

	}while(num != 0);

	inordem();
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