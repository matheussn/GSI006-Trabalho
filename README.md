Trabalho da matéria GSI006 - Estrutura de dados 1, sobre lista encadeada em C 


Alunos:
***Guilherme Eustaquio Moreira Santana**
Inscrição: 11621BSI229
***Matheus Santiago Neto** 
Inscrição: 11621BSI252 
***Rodrigo Souza Rezende** 
Inscrição: 11621BSI245 

Como utilizar:

No momento, as funções disponíveis do software são: create(char *s), id1(char *s) e showDir().

create(char *s): A função retorna NULL se a Lista estiver com um nome repetido ou, caso contrário, retorna o ponteiro para a lista criada, cujo rótulo é s.

showDir(): A função mostra todas as listas presentes no diretório. Em caso
de não houver nenhuma lista, uma mensagem de erro aparecerá.

id1(char *s): A função tem o objetivo de obter em qual parte
do diretório está a lista que possui o rótulo s. Se encontrado, retorna
o ponteiro para a lista de itens cujo rótulo é s. Caso contrário, retorna-se
NULL.