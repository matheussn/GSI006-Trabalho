/*
	Este arquivo implementa as funções especificadas no arquivo lista.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


// === declaracoes ===

struct itemL
{
    Item m;
    struct itemL *prox;
};

typedef struct itemL ItemL;

struct lista
{
	char *lb;
	int qd;
	ItemL *primeroItem;
	struct lista *prox;
};

typedef struct lista Lista;

struct d
{
	Lista *p;
	Lista *u;
};

typedef struct d Dir;

// === globais ===
	Dir D;						// Diretorio
	Lista *L = NULL;		// Lista
	ItemL *I   = NULL;		// Itens


// count
// -----
// Return the quantity of items in l;
// or return -1, if l is not found.

int
count (void * l)
{
	Lista *aux;

	aux = idl (l);
	if (aux == NULL)
		return -1;

	return aux->qd;
}


// create
// ------
// Return a pointer to the created list, whose label is s;
// or return NULL, if the list was not created

void *
create (char *s)
{
	Lista *aux;

	if (idl(s) != NULL)
		return NULL; // Lista com nome repetido

	aux = (Lista *) malloc (sizeof(Lista));

    if(aux == NULL)
        return NULL;

	aux->lb = s;
	aux->qd = 0;
	aux->prox = NULL;
	aux->primeroItem = NULL;

	if(L == NULL)	//Diretorio vazio
		L = D.p = D.u = aux;
	else 				//Diretorio cheio
		D.u->prox = D.u = aux;

	return L;
}


// destroy
// -------
// Return NULL if l was destroyed; return l otherwise.
// Destroying l implies in deallocating all nodes of l.

void *
destroy (void *l)
{

}


// find
// ----
// Return a pointer to the item whose id is m;
// or return NULL, if no item with id m was found.

Item *
find (void *l, int m)
{

}


// idl
// ---
// Return a pointer to list of items whose label is s;
// or return NULL, if does not exist a list with label s.

void *
idl (char *s)
{
	Lista *aux = L;

	while(aux != NULL)
	{
		if(strcmp(aux->lb,s) == 0)
			return aux;

		else
			aux = aux->prox;
	}

	return NULL;
}


// insert
// ------
// Return l, if m is inserted into l; or return NULL, if
// either l was not found or space for m was not allocated.
// m is inserted into l in ascending order.

void *
insert (void *l, Item m)
{

}


// label
// -----
// Return the label of l; or return NULL, if l is not found.

char *
label (void *l)
{

}


// showAll
// -------
// Present all items of l.
// Return l; or return NULL, if l was not found.

void *
showAll (void *l)
{

}

// showDir
// -------
// Present all lists in the directory and the respective
// number of items in each list.

void
showDir()
{
	Lista *aux = D;

	if(aux==NULL)
	{
		fprintf(stderr, "erro: Nao ha nenhuma lista no diretorio.\n");
	}

	while(aux != NULL)
	{
		printf("Lista: %s Quantidade: %d\n", aux->lb, aux->qd);
		aux = aux->prox;
	}

}
