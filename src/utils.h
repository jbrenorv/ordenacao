#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

typedef struct timespec Tempo;

typedef struct Parametros {
    char* arquivo_saida;
    int tamanho;
    int tipo;
    int execucao;
} Parametros;

typedef enum Tipo {
    CRESCENTE = 1,
    DECRESCENTE,
    ALEATORIO
} Tipo;

typedef struct Dados {
    long long comparacoes;
    long long movimentacoes;
    double tempo_ms;
} Dados;

typedef struct Algoritmo {
    char *nome;
    int tamanho_maximo;
    void (* alg)(int, int *);
    void (* alg_coletor)(int, int *, Dados *);
} Algoritmo;

typedef struct Celula {
    int valor;
    struct Celula* prox;
} Celula;

Parametros ResolveParametros(int argc, char **argv);
void ImprimeErro_E_FinalizaExecucao(const char *mensagem);
void Troca(int* a, int* b);
int* AlocaVetor(int n);
int* AlocaVetorLimpo(int n);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
int *CriaVetor(int n, Tipo tipo);
void CopiaVetor(int n, int *origem, int* destino);
void ImprimeVetor(int n, int *v, const char* prefixo);
int min(int a, int b);
int max(int a, int b);
int ObterMaiorElemento(int n, int *v);
int ObterMaiorElemento_ColetaDados(int n, int *v, Dados* dados);
Celula* CriaCelula(int valor);
void Verifica_Ordenacao(int n, int* v, Algoritmo* a);
Dados ObterDados(int n, int* v, Algoritmo* a);

#endif
