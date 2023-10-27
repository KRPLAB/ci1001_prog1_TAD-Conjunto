/*
 * Testes para a libconjunto.c
 * Disciplina CI1001 - Programacao I
 * Autor: Marcos Castilho
 * Data: 18/08/2022
*/

#include <stdio.h>
#include "conjunto.h"
#define TAM 20

int main (void) {
    struct conjunto *a, *b, *u, *i, *d, *d1, *copia, *sub;
    int k, ex;

    /* Teste para conjunto vazio */
    printf ("---> Teste 1\n");
    if (! (a= cria_cjt (TAM))) {
        printf ("falha na criacao do conjunto\n");
        return 1;
    }
    if (! vazio_cjt (a)) {
            printf("ERRO: criou conjunto nao vazio\n");
            return 1;
    }
    printf("OK: conjunto vazio\n");

    /* Teste de insercao de elementos no conjunto */
    printf ("---> Teste 2\n");
    for (k=1; k <= 10; k++){
        ex= insere_cjt (a, 2*k);
        if (ex == 0) {
            printf ("acabou espaco ao tentar inserir %d! Pode aumentar se quiser\n",2*k);
        }
    }
    printf ("Inseriu todos os elementos corretamente em a\n");

    /* Teste de impressao em conjunto com segundo teste de conjunto vazio */
    printf ("---> Teste 3\n");
    if (vazio_cjt (a)) {
        printf ("ERRO: conjunto a misteriosamente ficou vazio\n");
        return 1;
    }
    imprime_cjt (a);
    printf ("A saida deve ter sido os números pares de 2 a 20, senao esta errado\n");
    printf ("Lembrando que a impressao eh sempre em ordem crescente, pelo enunciado\n");

    /* Criando conjunto para testes de uniao, interseccao e diferenca */
    printf ("---> Teste 4\n");
    if (! (b= cria_cjt (TAM))) {
        printf ("falha na criacao do conjunto\n");
        return 1;
    }
    for (k=1; k <= 20; k++){
        ex= insere_cjt (b, k);
        if (ex == 0) {
            printf ("acabou espaco ao tentar inserir %d!\n",k);
        }
    }
    imprime_cjt (b);
    printf ("A saida deve ter sido todos os números de 1 a 20, senao esta errado\n");

    /* Teste para uniao de dois conjuntos */
    printf ("---> Teste 5\n");
    if (! (u= uniao_cjt (a, b))) {
            printf ("falha na uniao de dois conjuntos\n");
            return 1;
    }
    imprime_cjt (u);
    printf ("uniao: A saida deve ter sido todos os números de 1 a 20, senao esta errado\n");

    /* Teste para intersecao de dois conjuntos */
    printf ("---> Teste 6\n");
    if (! (i= interseccao_cjt (a, b))) {
            printf ("falha na interseccao de dois conjuntos\n");
            return 1;
    }
    imprime_cjt (i);
    printf ("intersec: A saida deve ter sido os números pares de 2 a 20, senao esta errado\n");

    /* Teste para diferenca de dois conjuntos */
    printf ("---> Teste 7\n");
    if (! (d= diferenca_cjt (a, b))) {
            printf ("falha na diferenca de dois conjuntos\n");
            return 1;
    }
    imprime_cjt (d);
    printf ("A saida deve ter sido o conjunto vazio, senao esta errado\n");
    if (! (d1= diferenca_cjt (b, a))) {
            printf ("falha na diferenca de dois conjuntos\n");
            return 1;
    }
    imprime_cjt (d1);
    printf ("diferenca: A saida deve ter sido os impares entre 1 e 19, senao esta errado\n");

    /* Teste de estar contido e contem */
    printf ("---> Teste 8\n");
    if (! contido_cjt (a, b)) {
        printf("ERRO: o conjunto a esta garantidamente contido no conjunto b e o programa falhou\n");
        return 1;
    }
    printf("OK: conjunto a esta contido no conjunto b\n");

    if (contido_cjt (b, a)) {
        printf("ERRO: o conjunto b nao esta contido no conjunto a e o programa falhou\n");
        return 1;
    }
    printf("OK: conjunto b nao esta contido no conjunto a\n");

    /* Teste de igualdade de conjunto */
    printf ("---> Teste 9\n");
    if (! sao_iguais_cjt (a, i)) {
        printf ("ERRO: estes conjuntos sao iguais e o programa falhou\n");
        return 1;
    }
    printf("OK: conjuntos iguais\n");

    if (sao_iguais_cjt (a, b)) {
        printf ("ERRO: estes conjuntos nao sao iguais e o programa falhou\n");
        return 1;
    }
    printf("OK: conjuntos diferentes\n");
    
    /* Testes de remocao, retira do inicio do meio e do fim */
    printf ("---> Teste 10\n");
    if (! retira_cjt (a, 20))
        printf("ERRO: nao retirou %d\n",20);
    printf ("OK: retirou 20\n");

    if (! retira_cjt (a, 2))
        printf("ERRO: nao retirou %d\n",2);
    printf ("OK: retirou 2\n");

    if (! retira_cjt (a, 10))
        printf("ERRO: nao retirou %d\n",10);
    printf ("OK: retirou 10\n");

    imprime_cjt (a);
    printf ("Esta impressao deve ter resultado nos números pares de 4 a 18, menos o 10, senao esta errado\n");

    for (k=1; k <= 20; k++) {
        if (! retira_cjt (a, k))
            printf("OK: nao retirou %d\n",k);
        else
            printf("OK: retirou %d\n",k);
    }
    printf ("Removeu todos os elementos? \n");
    imprime_cjt (a);
    printf ("Em caso afirmativo a linha anterior contem conjunto vazio\n");

    /* Teste de copia de conjuntos */
    printf ("---> Teste 11\n");
    if (! (copia=copia_cjt (b))) {
        printf ("ERRO: copia falhou\n");
        return 1;
    }
    imprime_cjt (copia);
    destroi_cjt (copia);
    printf("se a copia deu certo foram impressos os numeros de 1 a 20\n");

    /* Teste de subconjuntos */
    printf ("---> Teste 12\n");
    for (k=0; k <= cardinalidade_cjt (b); k++){
        if (! (sub=cria_subcjt_cjt (b, k))) {
            printf ("ERRO: criar subconjunto falhou\n");
            return 1;
        }
        imprime_cjt (sub);
        destroi_cjt (sub);
        printf("deve ter impresso um subconjunto de tamanho %d\n",k);
    }

    /* Teste do iterador */
    printf ("---> Teste 14\n");
    inicia_iterador_cjt (b);
    while (incrementa_iterador_cjt (b, &ex) != 0)
        printf ("%d ", ex);
    printf("\n");
    printf("Teste do iterador, tem que ter impresso todos numeros de 1 a 20\n");

    /* Teste do retira elemento */
    printf ("---> Teste 15\n");
    while (! vazio_cjt (b)){
        ex= retira_um_elemento_cjt (b);
        printf("%d ", ex);
    }
    printf("\n");
    printf("Teste do retirar, tem que ter impresso todos numeros de 20 ate 1 que estao no conjunto, em alguma ordem definida por voce\n");
    printf("depois tem que imprimir a mensagem 'conjunto vazio' logo abaixo\n");
    imprime_cjt(b);

    /* Destroi todos os conjuntos criados */
    destroi_cjt (a);
    destroi_cjt (b);
    destroi_cjt (u);
    destroi_cjt (i);
    destroi_cjt (d);
    destroi_cjt (d1);

    return 0;
}
