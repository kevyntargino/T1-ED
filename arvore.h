/**************************************************
*
* Nome dos(as) estudantes: Kevyn Thiago Freitas Targino
* Trabalho 1
* Disciplina: Estruturas de Dados
* Objetivo: Receber expressão completamente parentizada, imprimir pos ordem e avaliar
*/
#ifndef ARVORE_H
#define ARVORE_H

//Definição da estrutura da árovre
typedef struct Arv {
    char info[10];//vetor de caracteres para suportar numeros de até 10 digitos
    struct Arv* esq;
    struct Arv* dir;
} Arv;
//Cria arevore vazia
Arv* arv_criavazia(void);
//Cria nó raiz entre duas subárvores
Arv* arv_cria(const char* c, Arv* e, Arv* d);
//Libera memória alocada para árvore
Arv* arv_libera(Arv* a);
//Verifica se a arvore é vazia
int arv_vazia(Arv* a);
//Verifica a ocorrencia de uma infomração na árvore
int arv_pertence(Arv* a, char c);
//imprime árvore
void arv_imprime(Arv* a);
//imprime em pre ordem
void arv_preordem(Arv* a);
//imprime in ordem
void arv_inordem(Arv* a);
//imprime pos ordem
void arv_posordem(Arv* a);
//constriu árvore a partir da expressão
Arv* construir_arvore(const char** expr);
//avalia arvore usando tad pilha
int arv_avaliar_pilha(Arv* a);


#endif 
