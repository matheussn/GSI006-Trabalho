/*
	Este arquivo implementa as funções especificadas no arquivo lista.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


// === declaracoes ===

struct le
{
    Item m;
    struct le *prox;
};

typedef struct le LE;

struct d
{
	char *lb;
	int qd;
	LE *primeroItem;
	struct d *prox;
};

typedef struct d Dir;

struct c
{
	struct d *p;
	struct d *u;
};

typedef struct c Con;

// === globais ===
	Con *C 	= NULL;		// Controle do Diretorio
	Dir *DIR = NULL;		// Diretorio de itens
	LE  *L 	= NULL;		// Lista de itens


// count
// -----
// Return the quantity of items in l;
// or return -1, if l is not found.

int
count (void * l)
{
	Dir *aux;

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
	Dir *aux;

	if (idl(s) != NULL)
	{
		fprintf(stderr, "Erro: Ja existe uma lista com o nome %s\n", s);
		return NULL; // Lista com nome repetido
	}
	aux = (Dir *) malloc (sizeof(Dir));

	aux->lb = s;
	aux->qd = 0;
	aux->prox = NULL;
	aux->primeroItem = NULL;

	if(C == NULL)	//Diretorio vazio
		DIR = C->p = C->u = aux;
	else 				//Diretorio cheio
		C->u->prox = C->u = aux;

	fprintf(stdout, "Lista %s criada com sucesso!\n", s);

	return DIR;
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
	Dir *aux = DIR;

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
	Dir *aux = DIR;

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
