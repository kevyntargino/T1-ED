# T1-ED
Resolução de Trabalho T1 disciplina Estrutura de Dados do curso de Engenharia de Software UFMS 2025.1

Avaliação de Expressões Aritméticas
Trabalho 1
Estruturas de Dados — 2025
1 Descrição do Trabalho
Uma expressão completamente parentizada é aquela em que cada operação binária está envolvida por um par de parênteses, indicando de forma explícita a ordem de avaliação da expressão. Por exemplo, a expressão (3 + (2 * 5)) está completamente parentizada, pois todas as
operações estão envoltas por parênteses.
Essas expressões podem ser representadas graficamente por meio de uma árvore binária
conforme visto em sala, onde:
• Cada nó interno representa uma operação (como +, -, *, /),
• Cada nó folha representa um operando inteiro.
A estrutura da árvore determina a ordem em que as operações devem ser realizadas, conforme definido pela hierarquia dos parênteses.
2 Objetivo
Você deverá implementar, utilizando a linguagem C/C++, um programa que:
• Leia um conjunto de k expressões aritméticas completamente parentizadas, compostas
pelas quatro operações básicas (+, -, *, /) e operandos inteiros;
• Construa a árvore binária correspondente a cada expressão;
• Imprima a representação da árvore (por exemplo, usando travessias como pré-ordem ou
forma gráfica);
• Usando uma TAD pilha, avalie a expressão representada pela árvore e imprima o resultado;
• Libere toda a memória alocada para a árvore após a avaliação de cada expressão, deixandoa vazia para a próxima.
1
UNIVERSIDADE FEDERAL DE MATO GROSSO DO SUL
Faculdade de Computação
3 Requisitos da Entrega
O projeto deve estar estruturado em cinco arquivos separados:
• arvore.c – Implementação da TAD (Tipo Abstrato de Dados) Árvore Binária;
• pilha.c - Implementação da TAD (Tipo Abstrato de Dados) Pilha e suas operações;
• pilha.h - Arquivo de cabeçalho contendo a definição das estruturas e protótipos das funções da pilha;
• arvore.h – Arquivo de cabeçalho contendo a definição das estruturas e protótipos das
funções da árvore;
• main.c – Arquivo principal, responsável pela leitura das expressões, chamada das funções
para construção, impressão e avaliação da árvore.
Exemplo de Entrada
(3 + (2 * 5))
((7 - 4) * (6 + 2))
((1 + 2) * ((3 - 4) + 5))
Exemplo de Saída
Expressão: (17 - (2 * 15))
Árvore (pós-ordem): 3 2 15 * -
Resultado: 13
Expressão: ((17 - 5) * (6 + 4))
Árvore (pós-ordem): 17 5 - 6 4 + *
Resultado: 120

