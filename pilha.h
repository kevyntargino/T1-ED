//arquivo de cabeçalho com a definição de estruturas e prototipos da pilha
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
    char caractere;
    pilha* next;
}pilha;

