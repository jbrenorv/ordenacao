#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

typedef struct timespec tempo;

typedef struct parametros {
    char* arquivo_saida;
    int tamanho;
    int tipo;
    int execucao;
} parametros;

typedef enum tipo_vetor {
    CRESCENTE = 1,
    DECRESCENTE,
    ALEATORIO
} tipo_vetor;

typedef struct dados_execucao {
    long long comparacoes;
    long long movimentacoes;
    double tempo_ms;
} dados_execucao;

typedef struct algoritmo {
    char *nome;
    int tamanho_maximo;
    void (* alg)(int, int *);
    void (* alg_coleta_dados)(int, int *, dados_execucao *);
} algoritmo;

typedef struct celula {
    int valor;
    struct celula* prox;
} celula;

parametros ResolveParametros(int argc, char **argv);
void ImprimeErro_E_FinalizaExecucao(const char *mensagem);
void Troca(int* a, int* b);
int* AlocaVetor(int n);
int* AlocaVetorLimpo(int n);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
int *CriaVetor(int n, tipo_vetor tipo);
void CopiaVetor(int n, int *origem, int* destino);
void ImprimeVetor(int n, int *v, const char* prefixo);
int min(int a, int b);
int max(int a, int b);
int ObterMaiorElemento(int n, int *v);
int ObterMaiorElemento_ColetaDados(int n, int *v, dados_execucao* dados);
celula* CriaCelula(int valor);
void Verifica_Ordenacao(int n, int* v, algoritmo* a);
dados_execucao ObterDadosExecucao(int n, int* v, algoritmo* a);

#endif
