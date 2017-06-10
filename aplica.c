#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

#define MAXDESCR 30

int
main ()
{
	char fn; //Uma letra que representa uma das funções
	char *rl; //Rótulo da lista.
	int c1; //Um número.
	char *c2; //cadeia de caracteres
    	Lista *dir;

	c2= (char*) malloc(MAXDESCR);
	if(rl == NULL)
        {
		fprintf (stderr, "Erro na alocacao de c2");
		return -15;
	}

	printf("Digite uma operacao.\n");
	while(EOF)
    	{
		rl = (char*) malloc(MAXDESCR);
		if(rl == NULL)
        	{
		fprintf (stderr, "Erro na alocacao de rl");
		return -15;
		}
		
        setbuf(stdin,NULL);
        scanf("%c %s %d %s", &fn, rl, &c1, c2);
        switch(fn)
        {
            case 'c' :
                dir = create(rl);
                if(dir == NULL)
                	fprintf (stderr, "Erro ao criar a lista %s\n",rl);
				
		else
			printf("Lista %s criada com sucesso!\n", rl);
			
            break;

            case 's' :
                showDir();
                break;

            default :
                fprintf (stderr,"Funcao invalida!\n");
        }
    }

    return 0;
}
