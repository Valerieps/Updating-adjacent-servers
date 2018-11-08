typedef struct vertice {
    int id;
    struct aresta *p_primeiro;
    struct aresta *p_ultimo;
} Vertice;


typedef struct aresta{
    int viz;
    struct aresta *p_proximo;
}Aresta;

Vertice* criaGrafo (int v, int e);
int** criaMatriz(int v);
void insereAresta(Vertice *grafo, int v, int w);
int qualCor(int **coresDisponiveis, int v, int i);
void desabilitaCor(Vertice *grafo, int **coresDisponiveis, int i, int cor);
void imprime(Vertice *grafo, int v);
void imprimeAlocacao(int *corEfetiva, int v);
void imprimeNcromatico(int *corEfetiva, int v);
void verificaValidade (Vertice *grafo, int *corEfetiva, int v);
void limpaGrafo(Vertice *grafo, int v);
