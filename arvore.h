//Arquivo cabeçalho contendo definição de estruturas e prototipos das funções árvore
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore{
    char data;
    arv* esquerda;
    arv* direita;
}arv;

arv* insere_expressão();
