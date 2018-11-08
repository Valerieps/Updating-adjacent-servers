#include <stdio.h>
#include <stdlib.h>
#include "coloracaoh.h"

//== Cria vetor de vértices e inicializa campos ====
Vertice* criaGrafo (int v, int e){
    int i, n1, n2, a;
    Vertice *grafo;
    grafo = (Vertice*) malloc(v * sizeof(Vertice));

    for(i=0; i<v; i++){
        grafo[i].id = i;
        grafo[i].p_primeiro =  NULL;
        grafo[i].p_ultimo = NULL;
    }
    
    for (i=0; i<e; i++){
        a=scanf ("%d %d", &n1, &n2);
        if(a<0)
            printf("Erro\n");
        insereAresta(grafo, n1-1, n2-1);
    }



    return grafo;
}

int** criaMatriz(int v){
    int i, j;
 
    int **coresDisponiveis = (int**) malloc (v*sizeof(int*));
    for(i=0; i<v; i++)
        coresDisponiveis[i] = (int*) malloc ((v+1)*sizeof(int));
    
    for(i=0; i<v; i++)
        for(j=0; j<v; j++)
            coresDisponiveis[i][j]=1;//todas as cores estao disponiveis

    return coresDisponiveis;
}

void insereAresta(Vertice *grafo, int v, int w){
        int i, aux;

         for(i=0; i<2; i++){   
            Aresta *novaAresta = (Aresta*) malloc(sizeof(Aresta));

            if(grafo[v].p_primeiro==NULL){    // Se for o primeiro relacionamento do vértice, liga na cabeça da lista
                grafo[v].p_primeiro = novaAresta;
            }
            else                               // Do segundo relacionamento em diante, liga na última Aresta
                grafo[v].p_ultimo->p_proximo = novaAresta;
                
            grafo[v].p_ultimo = novaAresta; //Atualiza cauda da lista
            novaAresta->viz = w;              //Atribui ID à novaAresta
            novaAresta->p_proximo = NULL;     //Aterra último ponteiro

            aux=w; //Espelha o relacionamento
            w=v;
            v=aux;
        }
}

int qualCor(int **coresDisponiveis, int v, int i){

    int j;

    //itera no vetor e identifica o menor i cujo v[i=1]
    for(j=1; j<=v; j++){
        if(coresDisponiveis[i][j]==1){
            return j;
        }
    }
    return -1;
}

void desabilitaCor(Vertice *grafo, int **coresDisponiveis, int i, int cor){
    
    Aresta *crawler = grafo[i].p_primeiro;    
    
    while(crawler !=NULL){
        coresDisponiveis[crawler->viz][cor]=0;
        crawler = crawler->p_proximo; 
    }
}

void verificaValidade (Vertice *grafo, int *corEfetiva, int v){

    int i;

    for(i=0; i<v; i++){    
        Aresta *crawler = grafo[i].p_primeiro;    
        while(crawler !=NULL){
            if (corEfetiva[i] == corEfetiva[crawler->viz])
                printf("deu ruim");
            crawler = crawler->p_proximo;
        }
    }
}

void imprime(Vertice *grafo, int v){
    
    int i;

    for (i=0; i<v; i++){
        Aresta *crawler = grafo[i].p_primeiro;
        printf("ID: %d", grafo[i].id+1);    
        while(crawler !=NULL){
            printf("-> %d", crawler->viz+1);
            crawler = crawler->p_proximo;
        }
        printf("\n");
    }
}

void imprimeAlocacao(int *corEfetiva, int v){
    FILE *alocacao = fopen("alocacao.txt", "w");
    int i;

    for(i=0; i<v; i++){
        fprintf(alocacao,"%d %d\n", i+1, corEfetiva[i]);
    }
}

void imprimeNcromatico(int *corEfetiva, int v){
    FILE *rodada = fopen("rodada.txt", "w");
    int i, max=0;

    for(i=0; i<v; i++){
        if (corEfetiva[i] > max)
            max = corEfetiva[i];
    }

    fprintf(rodada, "%d\n", max);
    printf("%d\n", max);
}

void limpaGrafo(Vertice *grafo, int v){
    int i;
    Aresta *crawler;

    for(i=0; i<v; i++)
        while (grafo[i].p_primeiro != NULL){
            crawler = grafo[i].p_primeiro;
            grafo[i].p_primeiro = crawler->p_proximo;
            free(crawler);
        }

    free(grafo);
}