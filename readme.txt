Trabalho sobre lista encadeada.
	Matéria: GSI006 - Estrutura de dados 1
	Professor: Autran Macedo

	Alunos
		- Guilherme Eustáquio Moreira Santana - 11621BSI229
		- Matheus Santiago Neto - 11621BSI252
		- Rodrigo Souza Rezende - 11621BSI245

	Os arquivos enviados:
	. item.h - Este arquivo contém a declaração do item da lista.
	. lista.h - Este arquivo contém os protótipos das funções implementadas no arquivo lista.c.
	. lista.c - Este arquivo contém a implementação das funções especificadas no arquivo lista.h, nessa etapa do trabalho apenas as funções create, idl e showDir estão finalizadas.
	. aplica.c - Este arquivo contém um programa que permite aplicar operações sobre listas.
  
Como utilizar:

No momento, as funções disponíveis do software são: create(char *s), idl(char *s), showDir(), count(void *l), destroy(void *l), find(void *l, int m) e label(void *l).

create(char *s): A função retorna NULL se não for possivel criar a lista, caso contrário, retorna o ponteiro para a lista criada, cujo rótulo é s.

showDir(): A função mostra todas as listas presentes no diretório. Em caso de não houver nenhuma lista, uma mensagem de erro aparecerá.

idl(char *s): Retorna um ponteiro para a lista de itens cujo rótulo é s, ou retorna NULL, se não existir uma lista com o rótulo s

count(void *l): A função tem o objetivo de retornar a quantidade de itens em l. Caso l não seja encontrado, será retornado -1.

destroy(void *l): A função tem a tarefa de destruir a lista l, retornando NULL em caso de sucesso ou 1 em caso de falha. 

find(void *l, int m): A função tem o objetivo de procurar na lista *l o id m, retornando, em caso de sucesso, um ponteiro para o item cujo id é m.É retornado NULL se não houver algum item com o id m. 

label(void *l): A função tem a tarefa de encontrar e retornar o nome do rótulo da lista *l. É retornando NULL se a lista não for encontrada.

Tutorial:
	
	Como compilar o programa:
		Os arquivos lista.c e aplica.c devem ser compilados separadamente, deve utilizar gcc para fazer a compilação. O primeiro comando que deve ser aplicado é “gcc lista.c -c”, o próximo passo será compilar o aplica.c, com o comando “gcc aplica.c”. Com isso serão gerados gerados dois arquivos, o aplica.o e lista.o, com esses arquivos no mesmo diretório deve-se realizar o seguinte comando: “gcc *.o -o aplica.exe”, após esses procedimentos o programa já pode ser executado pelo comando ./aplica.exe.
	
	Como utilizar:
		Essa primeira versão do programa apenas cria lista e informas as listas criadas. Para utilização o usuário deve digitar alguns comandos de criar e mostras as listas criadas. São quatro operações que devem ser passadas para o programa, sempre começando com um caractere uma cadeia de caracteres um número e outra cadeia caracteres.  Caso esse padrão não seja respeitado o funcionamento do programa estará comprometida. Abaixo estão listados os comandos aceitados pelo o programa.
	Exemplo:
	“c aa -1 NULL” -> Com esse comando cria uma lista com nome de “aa”
	“s NULL -1 NULL” -> Com esse comando mostra todas a listas criadas.

	Para encerrar o programa deve-se digitar o comando CTRL + d.
	
	Além de digitar diretamente os comandos, o usauário pode enviar um arquivo com extensão .txt para o programa, com o comando "./aplica.exe < nome-do-arquivo.txt"
	No arquivo .txt as informações devem estar da mesma forma como se fosse digitada diretamente no programa.
	Exemplo:
	c aa -1 NULL
	s NULL -1 NULL
