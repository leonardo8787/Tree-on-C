#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

/*

Árvore básica: árvore binária
	-> tem um nó pai -> 2 filhos (direito >, esquerdo <)

	Input: {10,8,5,9,12,17}  log_n = log6 # 2.14

		  10 <- root
		/    \
	   NULL  NULL  <- *t

		 10  <- root (nível 0) 
		/  \
	   8    12  <- nível 1
	  / \    \
	 5   9    17  <- nível 2 (folhas)

O pior caso para usar a árvore é quando os dados já estão ordenados

*/

struct Record{
	int value;
	int key;
};
typedef struct Record Record;

struct Tree{
	Record reg;
	Tree *esq, *dir;
};
typedef struct Tree Tree;

Tree* createTree();
void insertItem(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record  r);
void removeItem(Tree **t, Record r);
void antecessor(Tree **t, Tree *aux);
void inordem(Tree *t);
void posordem(Tree *t);
void preordem(Tree *t);

#endif