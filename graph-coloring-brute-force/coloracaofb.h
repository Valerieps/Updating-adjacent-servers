int **criaGrafo(int v, int e);
int *criaVetor (int v);
void insereAresta(int **grafo, int e);
void imprimeMatriz(int **grafo, int v);
int verificaValidade (int vertice, int **grafo, int *corEfetiva, int c, int v); 
int buscaColoracao(int **grafo, int m, int *corEfetiva, int vertice, int v);
void imprimeResultado(int **corEfetiva, int m, int v);