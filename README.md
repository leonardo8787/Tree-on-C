<h1>Tree-on-C</h1>

A binary tree is a more general data structure than a linked list.<br>

A binary tree (= binary tree) is a set of records that satisfies certain conditions. 
Conditions will not be given explicitly, but they will be implicitly clear in context. 
The records will be called nodes (could also be called cells). 
Each node has an address. 
Let's assume for now that each node has only three fields: an integer and two pointers to us. 
Nodes can then be defined as follows:

~~~
   typedef struct reg {
      int  conteudo; // conteúdo
      noh *esq;
      noh *dir;
   } noh; // nó
~~~

The content field is the node's payload; 
the other two fields only serve to structure the tree. 
The left field of each node contains NULL or the address of another node. 
An analogous hypothesis holds for the dir field.


If the left field of a node P is the address of a node E, we will say that E is the left child of P. Similarly, if P.dir is equal to andD, we will say that D is the right child of P. If a node F is a child (left or right) of P, let's say that P is the parent of F. A leaf (= leaf) is a node that has no children at all.


It is very convenient to verbally confuse each node with its address. 
Thus, if x is a pointer to a node (that is, if x is of type *noh), we say consider node x rather than consider node whose address is x.


The figure below shows two examples of binary trees. 
On the left side, we have a curious binary tree in nature. 
On the right side, a schematic representation of a binary tree whose nodes contain the numbers 2, 7, 5, etc.

<p>
	<img src="https://www.ime.usp.br/~pf/algoritmos/xfig/Binary_tree.png" width="220" height="300">
</p>
