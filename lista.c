/*
	Este arquivo implementa as funções especificadas no arquivo lista.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


// === declaracoes ===

struct itemL	// define um item da lista encadeada
{
    Item m;
    struct itemL *prox;
};

typedef struct itemL ItemL;

struct lista				// Define uma lista duplamente encadeada
{
	char *lb;				// Nome da lista
	int qd;					// Quantidade de itens na lista
	ItemL *primeiroItem;	// apontador para o primeiro item da lista
	struct lista *ant;	// Lista anterior
	struct lista *prox;	//	proxima lista
};

typedef struct lista Lista;

struct d
{
	Lista *p;	// apontador para a primeira lista
	Lista *u;	// apontador para a segunda lista
};

typedef struct d Dir;

// === globais ===
	Dir D;					// Diretorio
	Lista *L = NULL;		// Lista
	ItemL *I   = NULL;	// Itens

// count
// -----
// Return the quantity of items in l;
// or return -1, if l is not found.

int
count (void * l)
{
	Lista *aux = (Lista*)l;

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
	aux->ant = D.u;
	aux->prox = NULL;
	aux->primeiroItem = NULL;

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
	Lista * aux;
	ItemL * x = NULL;

	aux = (Lista *) l;
	if(aux == NULL)
		return l;

	x = aux->primeiroItem;

	while(x != NULL)
	{
		aux->primeiroItem = aux->primeiroItem->prox;
		
		if(x->m.nome != NULL)
			free(x->m.nome);

		free(x);
		x = aux->primeiroItem;
	}

	free(aux->lb);

	if(aux->ant == NULL) // caso aux seja a primeira lista
	{
		if(aux->prox == aux->ant) // caso aux seja a unica lista
			L = D.p = D.u = NULL;
		else
		{
			L = D.p = aux->prox;
			D.p->ant = NULL;
		}
	}
	else // caso aux esteja no meio ou no final
	{
		if(D.u == aux) // ultima lista
		{
			D.u = aux->ant;
			D.u->prox = NULL;
		}
		else// no meio
		{
			aux->prox->ant = aux->ant;
			aux->ant->prox = aux->prox;
		}
	}

	free(aux);

	return NULL;
}


// find
// ----
// Return a pointer to the item whose id is m;
// or return NULL, if no item with id m was found.

Item *
find (void *l, int m)
{
	Lista *aux;
	ItemL *y;
	aux = (Lista*) l;
	if(aux == NULL)
		return NULL;	
	
	Item *x = (Item *) malloc(sizeof(Item));

	if(x == NULL)
		return NULL;

	x->id = -1;
	x->nome = NULL;

	y = aux->primeiroItem;

	while(y != NULL)
	{
		if(y->m.id == m)
		{
			x->id = y->m.id;
			x->nome = y->m.nome;
			break;
		}
		y = y->prox;
	}
	
	return x;
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
	Lista *li = (Lista *)l;
	ItemL *aux = NULL;
	ItemL *t;    // ponteiro item corrente
	ItemL *a;    // ponteiro item anterior

	aux = (ItemL*) malloc(sizeof(ItemL));
	if (aux == NULL)
		return NULL;

	aux->m.id = m.id;
	aux->m.nome = m.nome;

	for(a = t = li->primeiroItem; t != NULL; t = t->prox)
	{
		if(t->m.id < aux->m.id)
			a = t;
		else
			break;
	}

	if(a == NULL)
	{ //lista vazia
		aux->prox = NULL;
		li->primeiroItem = aux;
	}
	else if(a == t)
	{
		aux->prox = li->primeiroItem;
		li->primeiroItem = aux;
	}
	else
	{
		aux->prox = t;
		a->prox = aux;
	}

	li->qd++;

	return li;

}

// label
// -----
// Return the label of l; or return NULL, if l is not found.

char *
label (void *l)
{
    Lista *aux = (Lista*)l;

	if (aux == NULL)
		return NULL;

	return aux->lb;
}


// showAll
// -------
// Present all items of l.
// Return l; or return NULL, if l was not found.

void *
showAll (void *l)
{
	Lista *aux = (void *)l;
	ItemL *auxL = aux->primeiroItem;

	if(auxL == NULL)
	{
		fprintf(stderr, "Diretorio vazio\n");
	}

	fprintf(stdout, "Lista: %s\n", aux->lb);

	while(auxL != NULL)
	{
		printf("\tId: %d Nome: %s\n", auxL->m.id, auxL->m.nome);
		auxL = auxL->prox;
	}
}

// showDir
// -------
// Present all lists in the directory and the respective
// number of items in each list.

void
showDir()
{
	Lista *aux = L;

	if(aux==NULL)
	{
		fprintf(stderr, "Diretorio vazio\n");
	}
	
	fprintf(stdout,"Diretório Dir\n");
	while(aux != NULL)
	{
		printf("\tLista: %s\n\tQuantidade de itens: %d\n", aux->lb, aux->qd);
		aux = aux->prox;
	}

}
