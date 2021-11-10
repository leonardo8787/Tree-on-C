#ifndef ARVORE_H
#define ARVORE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	char *key;
	int value;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree();

void insertTree(Tree **t, Record r);
int isInTree(Tree *t, Record r);
void showTreeInOrder(Tree *t);
void antecessor(Tree **t, Tree *aux);
void removeTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r, int *quantArvore);
void preordem(Tree *t);
void meio(Tree *t);
void posordem(Tree *t);

#endif
