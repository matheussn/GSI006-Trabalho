#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDESCR 30

struct item
{
	int i;
	char *nome;
	struct item *proxItem;
};

typedef struct item Item;


struct lista
{
	char *lb;
	Item dados;
	struct item *primeroItem;
	struct lista *proxLista;
};

typedef struct lista Lista;

Lista *L = NULL;

//PROTOTIPOS
Lista* create (char *s);
Lista * insert (Lista *L, Item m, char *desc);


int
main(int argc, char * argv[])
{

	FILE *f;
	Item i;
	char fn;
	char *desc;
	int id;
	char *nome1;

	f = fopen("arquivo.txt","r");
    if (f == NULL)
    {
		fprintf (stderr, "Arquivo nao encontrado\n");
        return -10;
    }

	while(!feof(f))
    {
		nome1 = (char *) malloc (MAXDESCR);
		if (nome1 == NULL)
		{
			fprintf (stderr, "%s: m.nome1 not allocated\n", argv[0]);
			return -15;
		}

		desc = (char *) malloc (MAXDESCR);
		if (desc == NULL)
		{
			fprintf (stderr, "%s: m.lb not allocated\n", argv[0]);
			return -15;
		}

		fscanf (f, "%c %s %d %s ", &fn, desc, &id, nome1);

		if(fn == 'c')
			L = create(desc);

		if(fn == 'i')
		{
            i.i = id;
			i.nome = nome1;
			L = insert(L, i, desc);
		}


    }

	return 0;
}

Lista*
create (char *s)
{
	Lista *aux;

	if(L == NULL)
	{
		L = (Lista*) malloc (sizeof(Lista));
		L->primeroItem = NULL;
		L->proxLista = NULL;
		L->lb = s;
		return L;
	}
	else
	{
	    Lista *no = L;

		while(no != NULL)
		{
			if(strcmp(no->lb, s) == 0)
			{
				fprintf(stderr, "Lista com nome repetido");
				return NULL;
			}

        no = no->proxLista;
      }

		aux =(Lista*) malloc (sizeof(Lista));
		aux->lb = s;
		aux->primeroItem = NULL;
		aux->proxLista = L->proxLista;
		return aux;

	}
}

Lista *
insert (Lista *L, Item i, char *s)
{
	Item *x = (Item*) malloc(sizeof(Item));
	int j;
    Lista *no = L;

	if(x == NULL)
	{
		fprintf (stderr, "erro ao tentar alocar x\n");
		return NULL;
	}
	while( no != NULL)
    {
        if(strcmp(no->lb, s) == 0)
        {
            x->i = i.i;
            x->nome = i.nome;
            x->proxItem = L->primeroItem;
            L->primeroItem = x;
            return L;
        }

    no = no->proxLista;

    }

}
