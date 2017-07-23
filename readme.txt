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
		Os arquivos lista.c e aplica.c devem ser compilados separadamente, deve utilizar gcc para fazer a compilação. O primeiro comando que deve ser aplicado é “gcc lista.c -c”, o próximo passo será compilar o aplica.c, com o comando “gcc aplica.c”. Com isso serão gerados gerados dois arquivos, o aplica.o e lista.o, com esses arquivos no mesmo diretório deve-se realizar o seguinte comando: “gcc *.o -o aplica.exe”.
	
	Como utilizar:
		Nessa segunda versão do programa, é possível criar uma lista, inserir itens na lista, mostrar o diretório em que constam as listas, procurar um item pelo id dentro de uma certa lista, contar a quantidade de itens dentro de uma determinada lista, e, por fim, destruir uma determinada lista. Para utilização, o usuário deve criar um arquivo ".txt" e incluir nele alguns comandos. São seis operações que devem ser passadas para o programa, sempre começando com um caractere uma cadeia de caracteres um número e outra cadeia caracteres.  Caso esse padrão não seja respeitado, o funcionamento do programa estará comprometido. Abaixo estão listados os comandos aceitados pelo o programa.
	Exemplo de um "arquivo.txt" criado:
	“c aa -1 NULL” -> Cria a lista "aa"
	"i aa 12 Fulano" -> Insere-se na lista "aa" os dados "12 Fulano". 
	"u aa -1 NULL" ->  apresenta a quantidade de dados contidos na lista "aa".
	"s NULL -1 NULL" -> Apresenta todas as listas criadas.
	"d aa -1 NULL" -> Destroi a lista "aa".
	"f aa 10 NULL" -> Busca o item cuja chave é 10 na lista "aa".
	"w aluno -1 NULL" -> Apresenta os dados contidos na lista "aa".
	
	Na execução do programa é necessário enviar o arquivo .txt criado com os comandos demonstrados acima. O programa deverá ser executado pelo comando "./aplica.exe < nome.txt", com o nome correto do arquivo txt.
