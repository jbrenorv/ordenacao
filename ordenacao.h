#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

typedef long long int64;

typedef enum tipo_vetor {
    CRESCENTE = 1,
    DECRESCENTE,
    ALEATORIO
} tipo_vetor;

typedef struct __dados_execucao {
    int64 comparacoes;
    int64 movimentacoes;
    double tempo_ms;
} dados_execucao;

typedef struct __algoritmo {
    char *nome;
    int tamanho_maximo;
    void (* alg)(int, int *);
    void (* alg_coleta_dados)(int, int *, dados_execucao *);
} algoritmo;

typedef struct __noh {
    int valor;
    struct __noh* prox;
} noh;

// funcoes de lista ligada
void InsereOrdenado(int valor, noh** cabeca);
void ApagaLista(noh* cabeca);

// funcoes utilitarias
void ImprimeErro_E_FinalizaExecucao(const char *mensagem);
void Troca(int* a, int* b);
int* AlocaVetor(int n);
int* AlocaVetorLimpo(int n);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
void GeraVetorCrescente(int n, int* v);
void GeraVetorDecrescente(int n, int* v);
void GeraVetorAleatorio(int n, int* v);
int *CriaVetor(int n, tipo_vetor tipo);
void CopiaVetor(int n, int *origem, int* destino);
void ImprimeVetor(int n, int *v, const char* prefixo);
int min(int a, int b);
int max(int a, int b);
int ObterMenorElemento(int n, int *v);
int ObterMaiorElemento(int n, int *v);
dados_execucao ObterDadosExecucao(int n, int* v, algoritmo* a);

// algoritmos de ordenacao
void Bolha       (int n, int* v);
void BolhaComFlag(int n, int* v);
void Coquetel    (int n, int* v);
void Selecao     (int n, int* v);
void Insercao    (int n, int* v);

void ShellSort   (int n, int* v);
void MergeSort   (int n, int* v);
void QuickSortD  (int n, int* v);
void QuickSortP  (int n, int* v);
void HeapSort    (int n, int* v);

void Contagem    (int n, int* v);
void Balde       (int n, int* v);
void RadixSort   (int n, int* v);

// algoritmos de ordenacao com contagem de movimentos e comparacoes
void Bolha_ColetaDados       (int n, int* v, dados_execucao* dados);
void BolhaComFlag_ColetaDados(int n, int* v, dados_execucao* dados);
void Coquetel_ColetaDados    (int n, int* v, dados_execucao* dados);
void Selecao_ColetaDados     (int n, int* v, dados_execucao* dados);
void Insercao_ColetaDados    (int n, int* v, dados_execucao* dados);

void ShellSort_ColetaDados   (int n, int* v, dados_execucao* dados);
void MergeSort_ColetaDados   (int n, int* v, dados_execucao* dados);
void QuickSortD_ColetaDados  (int n, int* v, dados_execucao* dados);
void QuickSortP_ColetaDados  (int n, int* v, dados_execucao* dados);
void HeapSort_ColetaDados    (int n, int* v, dados_execucao* dados);

void Contagem_ColetaDados    (int n, int* v, dados_execucao* dados);
void Balde_ColetaDados       (int n, int* v, dados_execucao* dados);
void RadixSort_ColetaDados   (int n, int* v, dados_execucao* dados);

#endif
