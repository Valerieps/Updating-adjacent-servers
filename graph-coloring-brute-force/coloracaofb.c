#include <stdio.h>
#include <stdlib.h>
#include "coloracaofb.h"


int **criaGrafo(int v, int e){
   int i, j;

   int **grafo = (int**) malloc (v*sizeof(int*));
   for(i=0; i<v;i++){
      grafo[i]= (int*) malloc (v*sizeof(int));
      for(j=0; j<v; j++)
         grafo[i][j]=0;
   }

   insereAresta(grafo, e);
   return grafo;
}

int *criaVetor (int v){
    int *corEfetiva = (int*) malloc(v*sizeof(int));
    
    for (i = 0; i < v; i++)
        corEfetiva[i] = 0;
    
    return corEfetiva;

}

void insereAresta(int **grafo, int e){

   int i, v1, v2;
   for(i=0; i<e; i++){
      scanf("%d%d", &v1, &v2);
      grafo[v1-1][v2-1]=1;
      grafo[v2-1][v1-1]=1;
   }
}

void imprimeMatriz(int **grafo, int v){
   int i, j;
   for(i=0; i<v; i++){
      for(j=0; j<v; j++)
         printf("%2d", grafo[i][j]);
      printf("\n");
   }
}


int verificaValidade (int vertice, int **grafo, int *corEfetiva, int c, int v){
    for (int i = 0; i < v; i++)
        if (grafo[vertice][i] && c == corEfetiva[i])
            return 0;
    return 1;
}
 
int buscaColoracao(int **grafo, int m, int *corEfetiva, int vertice, int v){
    
    int i;
    if (vertice == v)
        return 1;
 
    for (i = 1; i <= m; i++){
        if (verificaValidade(vertice, grafo, corEfetiva, i, v)){
           corEfetiva[vertice] = i;
 
           if (buscaColoracao (grafo, m, corEfetiva, vertice+1, v) == 1)
             return 1;
          corEfetiva[vertice] = 0;
        }
    }
    return 0;
}



void imprimeResultado(int **corEfetiva, int m, int v){
    
    int i;
    FILE *rodada = fopen("rodada.txt", "w");
    FILE *alocacao = fopen("alocacao.txt", "w");
    
    fprintf(rodada, "%d\n", m);
         
    for (i = 0; i < v; i++)
        fprintf(alocacao, "%d %d\n", j+1, corEfetiva[j]);

}