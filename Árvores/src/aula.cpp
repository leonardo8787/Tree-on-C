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

	} else {

		if(r.value < (*t)->reg.value)
			insertItem(&(*t)->esq, r);

		else if(r.value > (*t)->reg.value)
			insertItem(&(*t)->dir, r);

	}
}

int main(){

	Tree *t;
	Record r;

	t = CreateTree();

	r.value = 10;
	insertItem(&t, r);

	r.value = 8;
	insertItem(&t, r);

	r.value = 10;
	insertItem(&t, r);
	
}