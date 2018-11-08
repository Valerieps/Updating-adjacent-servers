/* 
===========================================
Universidade Federal de Minas Gerais
Departamento de Ci�ncia da Computa��o
AEDS 3
TP 3 - Atualiza��es Problem�ticas
Val�ria Pereira de Souza 2016/118541
===========================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "coloracaoh.h"


int main(){

    int v, e, i, a;
    a=scanf("%d %d", &v,&e);
    if(a<0)
        printf("Erro\n");

    //=== 1. Cria estruturas e inicializa ===============================  
    Vertice *grafo = criaGrafo(v, e);

    int **coresDisponiveis = criaMatriz(v);

    int *corEfetiva = (int*) malloc(v*sizeof(int));
    for(i=0; i<v; i++)
        corEfetiva[i] = 0;
    corEfetiva[0]=1;


    //=== 2. Calcula Aloca��es ==========================================
    int cor;

    for(i=0; i<v; i++){                        //i controla o vertice (linha da matriz)
        cor = qualCor(coresDisponiveis, v, i); //identifica, na matriz, menor cor n�o previamente utilizada
        corEfetiva[i] = cor; 
        desabilitaCor(grafo, coresDisponiveis, i, cor);//desabilita a cor selecionada para os vizinhos
    }

    //verificaValidade(grafo, corEfetiva, v);
    //imprime(grafo, v);
    imprimeAlocacao(corEfetiva, v);
    imprimeNcromatico(corEfetiva, v); //(Eu sei que n�o � exatamente o num crom�tico)
    limpaGrafo(grafo, v);
    free(corEfetiva);

    for(i=0; i<v; i++)
        free(coresDisponiveis[i]);
    free(coresDisponiveis);

    return 0;

}
