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
				dir = create(rl);
				if(dir == NULL)
					fprintf (stderr, "Erro ao criar a lista %s\n",rl);
				else
					printf("Lista %s criada com sucesso!\n", rl);
                free(c2);

				break;

			case 's' :
				showDir();
				free(rl);
				free(c2);
				break;

         case 'u' :
             dir = idl(rl);

             if(dir == NULL)
             {
                 fprintf (stderr, "Lista %s nao existe.\n",rl);
                 break;
             }

             else
                 printf("Quantidade de itens na lista %s: %d", rl, c1);

             free(rl);
             free(c2);
             break;

         case 'i' :
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
					fprintf(stdout,"Item %d %s, inserido com sucesso na lista %s\n", m.id, m.nome, rl);
				}
				free(rl);
				break;

         case 'w' :
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
				dir = idl(rl);
				if(dir == NULL)
				{
					fprintf(stderr,"Lista %s nao existe.\n", rl);
					break;
				}
				n = find(dir, c1);

				if(n->id == -1)
				{
					fprintf(stderr, "Nenhum item foi encontrado com o id %d.\n", c1);
				}
				else
				{
					printf("Lista: %s\nID: %d  Descricao: %s\n", rl, n->id, n->nome);
				}
				free(rl);
				free(c2);
				break;

			case 'd' :
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
