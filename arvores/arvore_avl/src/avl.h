#ifndef AVL_H
#define AVL_H
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

Tree* CreateTree();
int getPeso(Tree **t);
int getMaxPeso(int left, int rigth);
void rotacaoSimplesParaDireita(Tree **t);
void rotacaoSimplesParaEsquerda(Tree **t);
void insertTree(Tree **t, Record r);
void showTreeInOrder(Tree *t);
void antecessor(Tree **t, Tree *aux);
void removeTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);

#endif
