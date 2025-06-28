#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

typedef struct timespec Tempo;

typedef enum Tipo {
    CRESCENTE = 1,
    DECRESCENTE,
    ALEATORIO
} Tipo;

typedef struct Parametros {
    char *arquivo_saida;
    int tamanho;
    int execucao;
    Tipo tipo;
} Parametros;

typedef struct Dados {
    long long comparacoes;
    long long movimentacoes;
    double tempo_ms;
} Dados;

typedef struct Algoritmo {
    char *nome;
    int tamanho_maximo;
    void (*alg)(int, int *);
    void (*alg_coletor)(int, int *, Dados *);
} Algoritmo;

typedef struct Celula {
    int valor;
    struct Celula *prox;
} Celula;

Parametros ResolveParametros(int argc, char **argv);
void ImprimeErro_E_FinalizaExecucao(const char *mensagem);
void Troca(int *a, int *b);
int *AlocaVetor(int tamanho);
int *AlocaVetorLimpo(int tamanho);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
int *CriaVetor(int tamanho, Tipo tipo);
void CopiaVetor(int tamanho, int *origem, int *destino);
int min(int a, int b);
int max(int a, int b);
int ObterMaiorElemento(int tamanho, int *vetor);
int ObterMaiorElemento_ColetaDados(int tamanho, int *vetor, Dados *dados);
Celula *CriaCelula(int valor);
void Verifica_Ordenacao(int tamanho, int *vetor, Algoritmo *algoritmo);
Dados ObterDados(int tamanho, int *vetor, Algoritmo *algoritmo);

#endif
