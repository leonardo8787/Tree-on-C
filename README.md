<h1>Árvores binárias</h1>

Uma árvore binária é uma estrutura de dados mais geral que uma lista encadeada.  Este capítulo introduz algumas operações básicas sobre árvores binárias. O capítulo seguinte, Árvores binárias de busca, trata de uma aplicação fundamental.<br>

<h2>Nós e filhos</h2>

Uma árvore binária (= binary tree) é um conjunto de registros que satisfaz certas condições.  As condições não serão dadas explicitamente, mas elas ficarão implicitamente claras no contexto.  Os registros serão chamados nós (poderiam também ser chamados células).  Cada nó tem um endereço.  Suporemos por enquanto que cada nó tem apenas três campos:  um número inteiro e dois ponteiros para nós.  Os nós podem, então, ser definidos assim:

~~~
   typedef struct reg {
      int  conteudo; // conteúdo
      noh *esq;
      noh *dir;
   } noh; // nó
~~~

O campo conteudo é a carga útil do nó;  os dois outros campos servem apenas para dar estrutura à árvore.  O campo esq de cada nó contém NULL ou o endereço de outro nó.  Uma hipótese análoga vale para o campo dir.

Se o campo esq de um nó P é o endereço de um nó E, diremos que E é o filho esquerdo de P.  Analogamente, se P.dir é igual a &D, diremos que D é o filho direito de P.  Se um nó F é filho (esquerdo ou direito) de P, diremos que P é o pai de F.  Uma folha (= leaf) é um nó que não tem filho algum.

É muito conveniente confundir, verbalmente, cada nó com seu endereço.  Assim, se x é um ponteiro para um nó (ou seja, se x é do tipo *noh), dizemos  considere o nó x  em lugar de  considere o nó cujo endereço é x.

A figura abaixo mostra dois exemplos de árvores binárias. Do lado esquerdo, temos uma curiosa árvore binária na natureza. Do lado direito, uma representação esquemática de uma árvore binária cujos nós contêm os números 2, 7, 5, etc.

<p>
	<img src="https://www.ime.usp.br/~pf/algoritmos/xfig/Binary_tree.png" width="220" height="300">
</p>

<h2>Árvores e subárvores</h2>

Suponha que x é um nó.  Um descendente de x é qualquer nó que possa ser alcançado pela iteração das instruções  x = x->esq  e  x = x->dir  em qualquer ordem.  (É claro que essas instruções só podem ser iteradas enquanto x for diferente de NULL. Estamos supondo que NULL é de fato atingido mais cedo ou mais tarde.)

Um nó x juntamente com todos os seus descendentes é uma árvore binária.  Dizemos que x é a raiz (= root) da árvore.  Se x tiver um pai, essa árvore é subárvore de alguma árvore maior.  Se x é NULL, a árvore é vazia.

Para qualquer nó x, o nó  x->esq  é a raiz da subárvore esquerda de  x  e  x->dir  é a raiz da subárvore direita de x.

<h2>Endereço de uma árvore e definição recursiva</h2>

O endereço de uma árvore binária é o endereço de sua raiz.  É conveniente confundir, verbalmente, árvores com seus endereços:  dizemos  considere a árvore r  em lugar de  considere a árvore cuja raiz tem endereço r.  Essa convenção sugere a introdução do nome alternativo arvore para o tipo-de-dados ponteiro-para-nó:

typedef noh *arvore; // árvore
A convenção permite formular a definição de árvore binária de maneira recursiva:  um ponteiro-para-nó r é uma árvore binária se

r é NULL    ou
r->esq  e  r->dir  são árvores binárias.
Muitos algoritmos sobre árvores ficam mais simples quando escritos em estilo recursivo.

<h2>Varredura esquerda-raiz-direita</h2>

Uma árvore binária pode ser percorrida de muitas maneiras diferentes. Uma maneira particularmente importante é a esquerda-raiz-direita, ou e-r-d, também conhecida como inorder traversal, ou varredura infixa, ou varredura central.  A varredura e-r-d visita

<p>1 - a subárvore esquerda da raiz, em ordem e-r-d,</p>
<p>2 - a raiz,</p>
<p>3 - a subárvore direita da raiz, em ordem e-r-d,</p>

nessa ordem.  Na seguinte figura, os nós estão numeradas na ordem em que são visitados pela varredura e-r-d.

<p>
	<img src="https://www.ime.usp.br/~pf/algoritmos/aulas/png-from-tex/arvore-binaria-1.png" width="220" height="300">
</p>

Eis uma função recursiva que faz a varredura e-r-d de uma árvore binária r:

~~~
// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.

void erd (arvore r) {
   if (r != NULL) {
      erd (r->esq);
      printf ("%d\n", r->conteudo);
      erd (r->dir); 
   }
}
~~~

É um excelente exercício escrever uma versão iterativa dessa função. A versão abaixo usa uma pilha de nós. A sequência de nós na pilha é uma espécie de roteiro daquilo que ainda precisa ser feito:  cada nó x na pilha é um lembrete de que ainda precisamos imprimir o conteúdo de x e o conteúdo da subárvore direita de x.  O elemento do topo da pilha pode ser um NULL, mas os demais elementos são diferentes de NULL.

~~~
// Recebe a raiz r de uma árvore binária e
// imprime os conteúdos dos seus nós
// em ordem e-r-d.

void erd_i (arvore r) {
   criapilha ();  // pilha de nós 
   empilha (r);
   while (true) {
      x = desempilha ();
      if (x != NULL) {
         empilha (x);
         empilha (x->esq);
      }
      else {
         if (pilhavazia ()) break;
         x = desempilha ();
         printf ("%d\n", x->conteudo);
         empilha (x->dir);
      }
   }
   liberapilha ();
}
~~~

(O código ficaria ligeiramente mais simples — mas um pouco menos legível — se manipulasse a pilha diretamente.)   A figura abaixo dá um exemplo de execução da função erd_i. Cada linha da tabela resume o estado das coisas no início de uma iteração: à esquerda está a pilha e à direita os nós impressos.  O valor NULL é indicado por -.

~~~

          5        
        /   \      
                   
     3         8   
   /   \     /   \ 
  1     4   6     9
 / \         \     
0   2         7    

     pilha           
     5               
     5 3             
     5 3 1           
     5 3 1 0         
     5 3 1 0 -       
     5 3 1 -        0
     5 3 2          1
     5 3 2 -         
     5 3 -          2
     5 4            3
     5 4 -           
     5 -            4
     8              5
     8 6             
     8 6 -           
     8 7            6
     8 -            7
     9              8
     9 -             
     -              9

~~~

Os exercícios abaixo discutem duas outras ordens de varredura de uma árvore binária:  a varredura r-e-d, que percorre a árvore em ordem raiz-esquerda-direita, e a varredura e-d-r, que percorre a árvore em ordem esquerda-direita-raiz.  A primeira também é conhecida como preorder traversal, ou varredura em pré-ordem, ou varredura prefixa.  A segunda também é conhecida como postorder traversal, ou varredura em pós-ordem, ou varredura posfixa. 

<h2>Altura e profundidade</h2>

A altura de um nó x em uma árvore binária é a distância entre x e o seu descendente mais afastado. Mais precisamente, a altura de x é o número de passos no mais longo caminho que leva de x até uma folha. Os caminhos a que essa definição se refere são os obtido pela iteração das instruções x = x->esq e x = x->dir, em qualquer ordem.

A altura (= height) xde uma árvore é a altura da raiz da árvore.  Uma árvore com um único nó tem altura 0. A árvore da figura tem altura 3.

<p>
	<img src="https://www.ime.usp.br/~pf/algoritmos/aulas/png-from-tex/arvore-binaria-letras.png" width="220" height="300">
</p>

Veja como a altura de uma árvore com raiz r pode ser calculada:

~~~
// Devolve a altura da árvore binária
// cuja raiz é r.

int altura (arvore r) {
   if (r == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = altura (r->esq);
      int hd = altura (r->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}
~~~

Qual a relação entre a altura, digamos h, e o número de nós de uma árvore binária?  Se a árvore tem n nós então

n−1  ≥  h  ≥  lg (n) ,

onde  lg (n)  denota  ⌊log n⌋,  ou seja, o piso de log n .  Uma árvore binária de altura n−1 é um tronco sem galhos: cada nó tem no máximo um filho.  No outro extremo, uma árvore de altura lg (n) é quase completa: todos os níveis estão lotados exceto talvez o último.

~~~
      n   lg(n)
      4       2
      5       2
      6       2
     10       3
     64       6
    100       6
    128       7
   1000       9
   1024      10
1000000      19
~~~

Uma árvore binária é balanceada (ou equilibrada) se, em cada um de seus nós, as subárvores esquerda e direita tiverem aproximadamente a mesma altura. Uma árvore binária balanceada com n nós tem altura próxima de  log n.  (A árvore do exemplo acima é balanceada).  Convém trabalhar com árvores balanceadas sempre que possível. Mas isso não é fácil se a árvore aumenta e diminui ao longo da execução do seu programa.

Profundidade.  A profundidade (= depth) de um nó s em uma árvore binária com raiz r é a distância de r a s. Mais precisamente, a profundidade de s é o comprimento do único caminho que vai de r até s. Por exemplo, a profundidade de r é 0 e a profundidade de r->esq é 1.

Uma árvore é balanceada se todas as suas folhas têm aproximadamente a mesma profundidade.

<h2>Nós com campo pai</h2>

Em algumas aplicações (veja a seção seguinte) é conveniente ter acesso direto ao pai de qualquer nó. Para isso, é preciso acrescentar um campo pai a cada nó:

~~~
typedef struct reg {
   int         conteudo;
   struct reg *pai;
   struct reg *esq, *dir;
} noh;
~~~

É um bom exercício escrever uma função que preencha o campo pai de todos os nós de uma árvore binária.

<h2>Primeiro e último nós</h2>

Considere o seguinte problema sobre uma árvore binária: encontrar o endereço do primeiro nó da árvore na ordem e-r-d. É claro que o problema só faz sentido se a árvore não é vazia.  Eis uma função que resolve o problema:

~~~
// Recebe uma árvore binária não vazia r
// e devolve o primeiro nó da árvore
// na ordem e-r-d.

noh *primeiro (arvore r) {  
    while (r->esq != NULL) 
       r = r->esq;
    return r;
}
~~~

Não é difícil fazer uma função análoga que encontre o último nó na ordem e-r-d.

<h2>Nó seguinte e anterior (sucessor e predecessor)</h2>

Digamos que x é o endereço de um nó de uma árvore binária. Nosso problema:  calcular o endereço do nó seguinte na ordem e-r-d.

Para resolver o problema, é necessário que os nós tenham um campo pai.  A função a seguir resolve o problema. É claro que a função só deve ser chamada com x diferente de NULL. A função devolve o endereço do nó seguinte a x ou devolve NULL se x é o último nó.

~~~
// Recebe o endereço de um nó x. Devolve o endereço 
// do nó seguinte na ordem e-r-d.
// A função supõe que x != NULL.

noh *seguinte (noh *x) {  
    if (x->dir != NULL) {
       noh *y = x->dir; 
       while (y->esq != NULL) y = y->esq;
       return y;                               // A
    }
    while (x->pai != NULL && x->pai->dir == x) // B 
       x = x->pai;                             // B
    return x->pai;
}
~~~

(Note que a função não precisa saber onde está a raiz da árvore.)  Na linha A, y é o endereço do primeiro nó, na ordem e-r-d, da subárvore cuja raiz é x->dir. As linhas B fazem com que x suba na árvore enquanto for filho direito de alguém.
