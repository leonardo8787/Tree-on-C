#include<stdio.h>
#include<stdlib.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	int key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree(){
	return NULL;
}

void insertTree(Tree **t, Record r)
{
  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void showTreeInOrder(Tree *t)
{
  if(!(t == NULL)){
    showTreeInOrder(t->esq); 
    printf("%d ", t->reg.key);
    showTreeInOrder(t->dir); 
  }
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  free(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: Record not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	free(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	free(aux);
}

void pesquisa(Tree **t, Tree **aux, Record r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}

	if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

	*aux = *t;
}


int main(){
	int reg[] = {5,3,7,2,4,6,1};
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;

	for(int i=0; i< 7; i++){
		r.key = reg[i];
		r.value = 1;
		insertTree(&raiz, r);
	}

	printf("{ ");
	showTreeInOrder(raiz);
	printf("}\n");

	r.key = 2;
	pesquisa(&raiz, &aux, r);
	
	printf("{ ");
	showTreeInOrder(aux);
	printf("}\n");

	r.key = 3;
	removeTree(&raiz, r);

	printf("{ ");
	showTreeInOrder(raiz);
	printf("}\n");

}
