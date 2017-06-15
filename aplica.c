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
	
	Lista *dir;

	printf("Digite uma operacao.\n");
	setbuf(stdin,NULL);
	
	while(scanf("%c ", &fn) != EOF)
	{
		c2 = (char *) malloc(MAXDESCR);
		if(c2 == NULL)
		{
			fprintf (stderr, "Erro na alocacao de c2");
			return -15;
		}

		rl = (char *) malloc(MAXDESCR);
		if(c2 == NULL)
		{
			fprintf (stderr, "Erro na alocacao de c2");
			return -15;
		}

		scanf("%s %d %s", rl, &c1, c2);

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
			default :
				fprintf (stderr,"Funcao invalida!\n");
		}

		printf("Digite uma operacao.\n");
		setbuf(stdin,NULL);
	}

	return 0;
}
