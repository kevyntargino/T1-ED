#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>


Arv* arv_criavazia (void){
return NULL;
}

//Cria nó raiz com informafção das daus subárvores
Arv* arv_cria (char c, Arv* sae, Arv* sad){
    Arv* p=(Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

//Indica se uma arvore é vazia
int arv_vazia (Arv* a){
    return a==NULL;
}

//Libera memória alocada pela arvore e retorna NULL
Arv* arv_libera (Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq); /* libera sae */
        arv_libera(a->dir); /* libera sad */
        free(a); /* libera raiz */
    }
    return NULL;
}

//Verifica se um caractere C está na arovre e retorna booleano
int arv_pertence (Arv* a, char c){
    if (arv_vazia(a))
        return 0; /* árvore vazia: não encontrou */
    else
        return a->info==c ||
        arv_pertence(a->esq,c) ||
        arv_pertence(a->dir,c);
}

//Percorre a árvore imprimindo
void arv_imprime (Arv* a){
    if (!arv_vazia(a)){
        printf("%c ", a->info); /* mostra raiz */
        arv_imprime(a->esq); /* mostra sae */
        arv_imprime(a->dir); /* mostra sad */
    }
}

//Imprime pré ordem
void arv_preordem (Arv* a){
    if (!arv_vazia(a))  {
        printf("%c", a->info);
        arv_preordem(a->esq);
        arv_preordem(a->dir);
    }
}

//Imprime in ordem
void arv_inordem (Arv* a){
    if (!arv_vazia(a)){
        arv_inordem (a->esq);
        printf("%c", a->info);
        arv_inordem (a->dir);
    }
}

//Imprime pós ordem
void arv_posordem (Arv* a){
    if (!arv_vazia(a)){
        arv_posordem (a->esq);
        arv_posordem (a->dir);
        processa (a); // por exemplo imprime
    }
}