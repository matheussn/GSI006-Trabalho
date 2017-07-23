#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#define MAXDESCR 30

int
main ()
{
	char fn;  // Caractere que representa as funções.
	char *rl; // Rótulo da lista.
	char *c2; // nome do item da lista.
	int c1;   // Id do item da lista.

	void *dir;
	Item m;
	Item *n;

	while(!feof(stdin))
	{
		c2 = (char *) malloc(MAXDESCR);
		if(c2 == NULL)
		{
			fprintf (stderr, "Erro na alocacao de c2");
			return -15;
		}

		rl = (char *) malloc(MAXDESCR);
		if(rl == NULL)
		{
			fprintf (stderr, "Erro na alocacao de rl");
			return -15;
		}

		scanf("%c %s %d %s ", &fn, rl, &c1, c2);

		switch(fn)
		{
			case 'c' :
				fprintf(stdout, "\nFunção create:\n");
				dir = create(rl);
				if(dir == NULL)
					fprintf (stderr, "Erro ao criar a lista %s\n",rl);
				else
					printf("Lista %s criada com sucesso!\n", rl);
                free(c2);

				break;

			case 's' :
				fprintf(stdout, "\nFunção showDir:\n");
				showDir();
				free(rl);
				free(c2);
				break;

         case 'u' :
				fprintf(stdout, "\nFunção count:\n");
				dir = idl(rl);

				if(dir == NULL)
				{
				  fprintf (stderr, "Lista %s nao existe.\n",rl);
				  break;
				}

				c1 = count(dir);

				printf("Quantidade de itens na lista %s: %d\n", rl, c1);

				free(rl);
				free(c2);
				break;

         case 'i' :
				fprintf(stdout, "\nFunção insert:\n");
				dir = idl(rl);
				if(dir == NULL)
				{
				  fprintf (stderr,"Lista %s nao existe.\n",rl);
				  break;
				}
				m.id = c1;
				m.nome = c2;
				dir = insert(dir,m);

				if(dir == NULL)
				{
					fprintf(stderr,"Ocorreu um erro na insercao do item: %d %s\n", m.id, m.nome);
				}
				else
				{
					fprintf(stdout,"Item %s com id %d, inserido com sucesso na lista %s\n", m.nome, m.id, rl);
				}
				free(rl);
				break;

         case 'w' :
				fprintf(stdout, "\nFunção showAll:\n");
				dir = idl(rl);
				if(dir == NULL)
				{
				  fprintf (stderr,"Lista %s nao existe.\n",rl);
				  break;
				}
				showAll(dir);
				free(rl);
				free(c2);
				break;

			case 'f' :
				fprintf(stdout, "\nFunção find:\n");
				dir = idl(rl);
				if(dir == NULL)
				{
					fprintf(stderr,"Lista %s nao existe.\n", rl);
					break;
				}
				n = find(dir, c1);

				if(n->id == -1)
				{
					fprintf(stderr, "A lista %s nao possui itens com id %d\n", rl, c1);
				}
				else
				{
					printf("Lista: %s\n\tID: %d  Nome: %s\n", rl, n->id, n->nome);
				}
				free(rl);
				free(c2);
				break;

			case 'd' :
				fprintf(stdout, "\nFunção destroy:\n");
				dir = idl(rl);
				if(dir == NULL)
				{
					fprintf(stderr,"Lista %s nao existe.\n", rl);
					break;
				}

				void * t = destroy(dir);

				if(t == NULL)
				{
					fprintf(stdout, "Lista %s destruida com sucesso\n", rl);
				}
				else
				{
					fprintf(stderr, "Erro ao destruir a lista %s\n", rl);
				}
				free(rl);
				free(c2);
				break;

			default :
				fprintf (stderr,"Funcao invalida!\n");
				break;
		}

		setbuf(stdin,NULL);
	}

	return 0;
}
