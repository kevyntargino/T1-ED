/**************************************************
*
* Nome dos(as) estudantes: Kevyn Thiago Freitas Targino
* Trabalho 1
* Disciplina: Estruturas de Dados
* Objetivo: Receber expressão completamente parentizada, imprimir pos ordem e avaliar
*/
#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    int valor;
    struct NoPilha* prox;
} NoPilha;

typedef struct Pilha {
    NoPilha* topo;
} Pilha;

Pilha* pilha_criar(void);
void pilha_empilhar(Pilha* p, int val);
int pilha_desempilhar(Pilha* p);
int pilha_vazia(Pilha* p);
void pilha_liberar(Pilha* p);

#endif 
