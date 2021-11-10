#include "arvore.h"

int main(){

	Tree *raiz = CreateTree();
	Tree *aux = CreateTree();
	Record r;
	int *cont=0;
	int tamBusca=10, quantVetor=0, tamPalavra=30, quantArvore=0;
	int controle;

	char *palavra[] = {"ab","bc","c","d","e","f","g","h","i","j","k","l","m","n","o","p","k","r","s","t","u","v","w","x","y","z","a1","b1","c1","d1","e1","f1"};
	char *busca[] = {"ab","k","l","bc","c","d","r","f","m","e"};

	tamPalavra = sizeof(palavra)/sizeof(palavra[0]);
	tamBusca = sizeof(busca)/sizeof(busca[0]);

	system("clear || cls");

	printf("\nBusca binária com palavras\n");
	printf("autor: Leonardo de Oliveira Campos\n\n\n");

	printf("\nElementos da árvore binária: ");
	printf("\n{");
	for(int i=0; i<30; i++){
		
		r.key = palavra[i];
		r.value = 1;
		printf("%s ", r.key);
		insertTree(&raiz, r);
	}
	printf("}\n");

	printf("Pré-ordem");
	printf("\n{");
	preordem(raiz);
	printf("}");

	printf("\nMeio");
	printf("\n{");
	meio(raiz);
	printf("}\n");

	printf("Pós-ordem");
	printf("\n{");
	posordem(raiz);
	printf("}\n");

	printf("\nPalavras");
	printf("{");
	for(int i=0; i<30; i++){
		printf(" %s ",palavra[i]);
	}
	printf("}\n");
	
	printf("\nPesquisa palavra: ");
	printf("\n{");
	for(int i=0; i<tamBusca; i++) {
		printf("%s ", busca[i]);
	}
	printf("}\n\n");

	for(int i=0; i < tamBusca; i++) {
		r.key = busca[i];
		pesquisa(&raiz, &aux, r, &quantArvore);
		
		printf("encontrado: %s\n", busca[i]);
	}

	for(int i=0; i < tamBusca; i++) {
		for(int j=0; j < tamPalavra; j++) {
			quantVetor++;
			controle = strcmp(busca[i], palavra[j]);
			if(controle == 0) {
				controle = 1;
				break;
			}
		}
	}

	printf("\n\n");
	printf("acessos na arvore: %d\n", quantArvore);
	printf("acessos medio na arvore: %d\n", (quantArvore / tamBusca));
	printf("acessos no vetor: %d\n", quantVetor);
	printf("acessos medio no vetor: %d\n", (quantVetor / tamBusca));
	printf("\n\n");

  return 0;
}
