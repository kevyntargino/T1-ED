#indef ARVORE_H
#define ARVORE_H

typedef struct Arv
{
    char info;
    Arv* esq;
    Arv* dir;
}Arv;


arv construir_arvore(arv* i, const char expressao);
//cria arvore vazia
Arv* arv_criavazia (void);
//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char c, Arv* e, Arv* d);
//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);
//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);
//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, char c);
//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);
//Imprime pré ordem
void arv_preordem (Arv* a);
//Imprime in ordem
void arv_inordem (Arv* a);
//Imprime pós ordem
void arv_posordem (Arv* a);

#endif