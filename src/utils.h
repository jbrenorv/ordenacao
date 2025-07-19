#ifndef __UTILS_H__
#define __UTILS_H__

#define MIN_EL 0
#define MAX_EL 100000000
#define MAX_TAM 100000000

typedef enum VTipo {
    CRE,                // Vetor em ordem crescente
    DEC,                // Vetor em ordem decrescente
    ALE,                // Vetor gerado de forma pseudo-aleatoria
    M3K                 // Median-of-3 Killer (https://webpages.charlotte.edu/rbunescu/courses/ou/cs4040/introsort.pdf pagina 3)
} VTipo;

typedef enum ATipo {
    INF,                // Metodos inferiores
    SUP,                // Metodos superiores
    LIN                 // Metodos lineares
} ATipo;

typedef struct Parametros {
    char *arquivo_saida;
    int tamanho;
    int execucao;
    VTipo tipo;
} Parametros;

typedef struct Dados {
    long long comparacoes;
    long long movimentacoes;
    double tempo;
} Dados;

typedef struct Algoritmo {
    char *nome;
    int tamanho_maximo;
    void (*alg)(int, int *);
    void (*alg_coletor)(int, int *, Dados *);
    ATipo tipo;
} Algoritmo;

typedef struct Celula {
    int valor;
    struct Celula *prox;
} Celula;

Parametros ResolveParametros(int argc, char **argv);
void FinalizaExecucao(const char *mensagem);
int *AlocaVetor(int tamanho);
int *AlocaVetorLimpo(int tamanho);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
int *CriaVetor(int tamanho, VTipo tipo);
void CopiaVetor(int tamanho, int *origem, int *destino);
int Min(int a, int b);
int Max(int a, int b);
int ObterMaiorElemento(int tamanho, int *vetor);
int ObterMaiorElemento_CD(int tamanho, int *vetor, Dados *dados);
Celula *CriaCelula(int valor);
void Verifica_Ordenacao(int tamanho, int *vetor, Algoritmo *algoritmo);
Dados ObterDados(int tamanho, int *vetor, Algoritmo *algoritmo);

#endif
