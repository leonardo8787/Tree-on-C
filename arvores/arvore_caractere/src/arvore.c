#include "arvore.h"

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
    printf("%s ", t->reg.key);
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

void pesquisa(Tree **t, Tree **aux, Record r, int *quantArvore){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}
	//(*cont)++;
	(*quantArvore)++;
	if(strcmp((*t)->reg.key , r.key)>0){ pesquisa(&(*t)->esq, aux, r, quantArvore); return;}
	if(strcmp((*t)->reg.key , r.key)<0){ pesquisa(&(*t)->dir, aux, r, quantArvore); return;}

	*aux = *t;
}

void preordem(Tree *t) {
	if(!(t == NULL)) {
		printf("%s ", t->reg.key);
		preordem(t->esq);
		preordem(t->dir);
	}
}

void meio(Tree *t) {
	if(!(t == NULL)) {
		meio(t->esq);
		printf("%s ", t->reg.key);
		meio(t->dir);
	}
}

void posordem(Tree *t) {
	if(!(t == NULL)) {
		posordem(t->esq);
		posordem(t->dir);
		printf("%s ", t->reg.key);
	}
}
