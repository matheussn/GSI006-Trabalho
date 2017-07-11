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

		scanf("%c %s %d %s", &fn, rl, &c1, c2);

		switch(fn)
		{
			case 'c' :
				dir = create(rl);
				if(dir == NULL)
					fprintf (stderr, "Erro ao criar a lista %s\n",rl);
				else
					printf("\nLista %s criada com sucesso!\n", rl);

				break;

			case 's' :
				showDir();
				break;

            case 'w' :
                c1 = count (rl);

                if(c1 == -1)
                    fprintf (stderr, "Lista %s nao existe.\n",rl);

                else
                    printf("Quantidade de itens na lista %s: %d", rl, c1);

                break;

			default :
				fprintf (stderr,"Funcao invalida!\n");
				break;
		}

		setbuf(stdin,NULL);
	}

	return 0;
}

