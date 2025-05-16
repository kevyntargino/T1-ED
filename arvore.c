/**************************************************
*
* Nome dos(as) estudantes: Kevyn Thiago Freitas Targino
* Trabalho 1
* Disciplina: Estruturas de Dados
* Objetivo: Receber expressão completamente parentizada, imprimir pos ordem e avaliar
*/

#include "arvore.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Arv* arv_criavazia(void) {
    return NULL;
}

Arv* arv_cria(const char* c, Arv* sae, Arv* sad) {
    Arv* p = (Arv*)malloc(sizeof(Arv));
    if (!p) {
        fprintf(stderr, "Erro de alocacao\n");
        exit(1);
    }
    strcpy(p->info, c);
    p->esq = sae;
    p->dir = sad;
    return p;
}

int arv_vazia(Arv* a) {
    return a == NULL;
}

Arv* arv_libera(Arv* a) {
    if (!arv_vazia(a)) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_pertence(Arv* a, char c) {
    if (arv_vazia(a))
        return 0;
    else
        return (a->info[0] == c) ||
               arv_pertence(a->esq, c) ||
               arv_pertence(a->dir, c);
}

void arv_imprime(Arv* a) {
    if (!arv_vazia(a)) {
        printf("%s ", a->info);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
}

void arv_preordem(Arv* a) {
    if (!arv_vazia(a)) {
        printf("%s ", a->info);
        arv_preordem(a->esq);
        arv_preordem(a->dir);
    }
}

void arv_inordem(Arv* a) {
    if (!arv_vazia(a)) {
        arv_inordem(a->esq);
        printf("%s ", a->info);
        arv_inordem(a->dir);
    }
}

void arv_posordem(Arv* a) {
    if (!arv_vazia(a)) {
        arv_posordem(a->esq);
        arv_posordem(a->dir);
        printf("%s ", a->info);
    }
}

// Funções auxiliares para a construção da árvore
//Pula os caracteres espações da expressão de entrada
void pular_espacos(const char** expr) {
    while (**expr == ' ') (*expr)++;
}
//Le um numero na exressão
void ler_numero(const char** expr, char* buffer) {
    int i = 0;
    pular_espacos(expr);
    while (isdigit(**expr)) {
        buffer[i++] = **expr;
        (*expr)++;
    }
    buffer[i] = '\0';
}

Arv* construir_arvore(const char** expr) {
    pular_espacos(expr);

    if (**expr == '(') {
        (*expr)++; // pula '('
        Arv* esq = construir_arvore(expr);

        pular_espacos(expr);
        char op[2];
        op[0] = **expr;
        op[1] = '\0';
        (*expr)++;

        Arv* dir = construir_arvore(expr);

        pular_espacos(expr);
        if (**expr == ')') (*expr)++;

        return arv_cria(op, esq, dir);
    } else {
        char num[10];
        ler_numero(expr, num);
        return arv_cria(num, NULL, NULL);
    }
}

//inclususao da biblioteca tad pilha para avaliar árvore
#include "pilha.h"

typedef struct PilhaArv {
    Arv* no;
    int visitado;
    struct PilhaArv* prox;
} PilhaArv;

void empilhar_arv(PilhaArv** topo, Arv* no, int visitado) {
    PilhaArv* novo = malloc(sizeof(PilhaArv));
    novo->no = no;
    novo->visitado = visitado;
    novo->prox = *topo;
    *topo = novo;
}

Arv* desempilhar_arv(PilhaArv** topo, int* visitado) {
    PilhaArv* temp = *topo;
    Arv* no = temp->no;
    *visitado = temp->visitado;
    *topo = temp->prox;
    free(temp);
    return no;
}

int arv_avaliar_pilha(Arv* a) {
    if (arv_vazia(a)) return 0;

    PilhaArv* pilhaArv = NULL;
    Pilha* pilhaVal = pilha_criar();

    empilhar_arv(&pilhaArv, a, 0);

    while (pilhaArv != NULL) {
        int visitado;
        Arv* atual = desempilhar_arv(&pilhaArv, &visitado);

        if (atual == NULL) continue;

        if (visitado) {
            // Operador ou número
            if (atual->esq == NULL && atual->dir == NULL) {
                pilha_empilhar(pilhaVal, atoi(atual->info));
            } else {
                int dir = pilha_desempilhar(pilhaVal);
                int esq = pilha_desempilhar(pilhaVal);
                int res = 0;

                switch (atual->info[0]) {
                    case '+': res = esq + dir; break;
                    case '-': res = esq - dir; break;
                    case '*': res = esq * dir; break;
                    case '/': res = (dir != 0) ? esq / dir : 0; break;
                    default: res = 0; break;
                }
                pilha_empilhar(pilhaVal, res);
            }
        } else {
            
            empilhar_arv(&pilhaArv, atual, 1); 
            empilhar_arv(&pilhaArv, atual->dir, 0);
            empilhar_arv(&pilhaArv, atual->esq, 0);
        }
    }

    int resultado = pilha_desempilhar(pilhaVal);
    pilha_liberar(pilhaVal);
    return resultado;
}

