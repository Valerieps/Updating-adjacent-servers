/* 
===========================================
Universidade Federal de Minas Gerais
Departamento de Ciência da Computação
AEDS 3
TP 3 - Atualizações Problemáticas - FORÇA BRUTA
Valéria Pereira de Souza 2016/118541
===========================================
*/

#include<stdio.h>
#include<stdlib.h>
#include"coloracaofb.h"


int main(){

   int i,j,v=4, e, a;

   a=scanf("%d %d", &v,&e);
   if(a<0)
      printf("Erro\n");


  //=== 1. Cria estruturas e inicializa ===============================  
  int **grafo = criaGrafo(v, e);
  int *corEfetiva = criaVetor(v);


  //=== 2. Calcula Alocações ==========================================

   int m = 1;
      
   for(i=0; i<v; i++, m++){ 
      if (buscaColoracao(grafo, m, corEfetiva, 0, v) != 0){
         imprimeResultado(corEfetiva, m, v);
         return 0;
      }
   }   
   return 0;
}