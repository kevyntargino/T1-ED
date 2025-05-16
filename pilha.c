/**************************************************
*
* Nome dos(as) estudantes: Kevyn Thiago Freitas Targino
* Trabalho 1
* Disciplina: Estruturas de Dados
* Objetivo: Receber expressão completamente parentizada, imprimir pos ordem e avaliar
*/
#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>

Pilha* pilha_criar(void) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_empilhar(Pilha* p, int val) {
    NoPilha* no = (NoPilha*)malloc(sizeof(NoPilha));
    no->valor = val;
    no->prox = p->topo;
    p->topo = no;
}

int pilha_desempilhar(Pilha* p) {
    if (pilha_vazia(p)) {
        fprintf(stderr, "Pilha vazia\n");
        exit(1);
    }
    NoPilha* no = p->topo;
    int val = no->valor;
    p->topo = no->prox;
    free(no);
    return val;
}

int pilha_vazia(Pilha* p) {
    return p->topo == NULL;
}

void pilha_liberar(Pilha* p) {
    while (!pilha_vazia(p)) {
        pilha_desempilhar(p);
    }
    free(p);
}
