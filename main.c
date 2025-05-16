/**************************************************
*
* Nome dos(as) estudantes: Kevyn Thiago Freitas Targino
* Trabalho 1
* Disciplina: Estruturas de Dados
* Objetivo: Receber expressão completamente parentizada, imprimir pos ordem e avaliar
*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#define MAXEXP 256 //definição de tamanho máximo da expressão;

int main() {
    char expr[MAXEXP];

    printf("Digite a expressão parentizada:\n");
    while (fgets(expr, sizeof(expr), stdin)) {
        if (expr[0] == '\n') break; 

        const char* p = expr;
        Arv* arv = construir_arvore(&p);

        printf("Expressao: %s", expr);
        printf("Arvore (pos-ordem): ");
        arv_posordem(arv);
        printf("\n");

        int resultado = arv_avaliar_pilha(arv); 

        printf("Resultado: %d\n", resultado);

        arv_libera(arv);

        printf("\nDigite outra expressao ou linha vazia para sair:\n");
    }

    return 0;
}
