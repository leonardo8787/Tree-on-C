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
	int peso;
};

Tree* CreateTree(){
	return NULL;
}

int getPeso(Tree **t){
	if(*t == NULL)
		return -1;
	return (*t)->peso;
}

int getMaxPeso(int left, int rigth){
	if(left > rigth)
		return left;
	return rigth;
}


//acredito que o erro esteja aqui!
rotacaoSimplesParaDireita(Tree **t, Record r){
	(*t)->esq = (*t)->dir;
}

rotacaoSimplesParaEsquerda(Tree **t, Record r){
	(*t)->dir = (*t)->esq;
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
      if(getPeso(&(*t)->esq - getPeso(&(*t)->dir)) == 2){
      	//rotação simples
      	if(r.key < (*t)->esq->reg.key)
      		rotacaoSimplesParaDireita(t);
      	//rotação dupla
				else
					rotacaoSimplesParaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
      if(getPeso(&(*t)->esq - getPeso(&(*t)->dir)) == 2){
      	//rotação simples
      	if(r.key > (*t)->esq->reg.key)
      		rotacaoSimplesParaEsquerda(t);
      	//rotação dupla
				else
					rotacaoSimplesParaEsquerda(t);
      }
    }
  
  }

  //printf("%d\t", (*t)->reg.key);
  (*t)->peso = getMaxPeso(getPeso(&(*t)->esq), getPeso(&(*t)->dir)) + 1;
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
	
	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int num;

	printf("\nÁrvore binária em C\n\n");
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
	            break;
	        case 1:
	            printf("\nDigite um valor: \n");
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
	            showTreeInOrder(raiz);
	            showTreeInOrder(aux);
	            printf("\n");
	            break;
	        case 4:
	           	system("cls || clear");
	        default:
	            printf("\nEscolha uma opção válida!\n");
	            break;
	    }
	}while(num != 0);

    return 0;
}