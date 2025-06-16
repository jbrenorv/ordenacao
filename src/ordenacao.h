#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include "utils.h"

#define _10e9 1000000000

// Bolha
void Bolha(int n, int *v);
void Bolha_ColetaDados(int n, int *v, dados_execucao *dados);

// BolhaFlag
void BolhaFlag(int n, int *v);
void BolhaFlag_ColetaDados(int n, int *v, dados_execucao *dados);

// Coquetel
void Coquetel(int n, int *v);
void Coquetel_ColetaDados(int n, int *v, dados_execucao *dados);

// Selecao
void Selecao(int n, int *v);
void Selecao_ColetaDados(int n, int *v, dados_execucao *dados);

// Insercao
void Insercao(int n, int *v);
void Insercao_ColetaDados(int n, int *v, dados_execucao *dados);

// Shellsort
void Shellsort(int n, int *v);
void Shellsort_ColetaDados(int n, int *v, dados_execucao *dados);

// Mergesort
void Mergesort(int n, int *v);
void MergesortRec(int l, int r, int *v, int *aux);
void Merge(int l, int m, int r, int *v, int *aux);
void Mergesort_ColetaDados(int n, int *v, dados_execucao *dados);
void MergesortRec_ColetaDados(int l, int r, int *v, int *aux, dados_execucao *dados);
void Merge_ColetaDados(int l, int m, int r, int *v, int *aux, dados_execucao *dados);

// Quicksort
void Quicksort(int n, int *v);
void QuicksortRec(int l, int r, int *v);
void ParticionaAleatorioDuplo(int l, int r, int *i, int *j, int *v);
void Quicksort_ColetaDados(int n, int *v, dados_execucao *dados);
void QuicksortRec_ColetaDados(int l, int r, int *v, dados_execucao *dados);
void ParticionaAleatorioDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, dados_execucao *dados);

// Heapsort
void Heapsort(int n, int *v);
void ConstroiHeap(int n, int *v);
void Heapify(int i, int n, int *v);
void Heapsort_ColetaDados(int n, int *v, dados_execucao *dados);
void ConstroiHeap_ColetaDados(int n, int *v, dados_execucao *dados);
void Heapify_ColetaDados(int i, int n, int *v, dados_execucao *dados);

// Contagem
void Contagem(int n, int *v);
void Contagem_ColetaDados(int n, int *v, dados_execucao *dados);

// Balde
void Balde(int n, int *v);
void InsereOrdenado(int valor, celula** l);
void Balde_ColetaDados(int n, int *v, dados_execucao *dados);
void InsereOrdenado_ColetaDados(int valor, celula** cabeca, dados_execucao* dados);

// Radixsort
void RadixsortContagem(int n, int *v);
void RadixsortBalde(int n, int *v);
void ContagemDigital(int p, int n,  int* v);
void BaldeDigital(int p, int n, int *v);
int d(int p, int valor);
void RadixsortContagem_ColetaDados(int n, int *v, dados_execucao *dados);
void RadixsortBalde_ColetaDados(int n, int *v, dados_execucao *dados);
void ContagemDigital_ColetaDados(int p, int n,  int* v, dados_execucao *dados);
void BaldeDigital_ColetaDados(int p, int n, int *v, dados_execucao *dados);

#endif
