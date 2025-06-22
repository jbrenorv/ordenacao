#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include "utils.h"

#define _10e9 1000000000

// Bolha
void Bolha(int n, int *v);
void Bolha_CD(int n, int *v, Dados *dados);

// BolhaFlag
void BolhaFlag(int n, int *v);
void BolhaFlag_CD(int n, int *v, Dados *dados);

// Coquetel
void Coquetel(int n, int *v);
void Coquetel_CD(int n, int *v, Dados *dados);

// Selecao
void Selecao(int n, int *v);
void Selecao_CD(int n, int *v, Dados *dados);

// Insercao
void Insercao(int n, int *v);
void Insercao_CD(int n, int *v, Dados *dados);

// Shellsort
void Shellsort(int n, int *v);
void Shellsort_CD(int n, int *v, Dados *dados);

// Mergesort
void Mergesort(int n, int *v);
void MergesortRec(int l, int r, int *v, int *aux);
void Merge(int l, int m, int r, int *v, int *aux);
void Mergesort_CD(int n, int *v, Dados *dados);
void MergesortRec_ColetaDados(int l, int r, int *v, int *aux, Dados *dados);
void Merge_ColetaDados(int l, int m, int r, int *v, int *aux, Dados *dados);

// Quicksort
void Quicksort(int n, int *v);
void QuicksortRec(int l, int r, int *v);
void ParticionaAleatorioDuplo(int l, int r, int *i, int *j, int *v);
void Quicksort_CD(int n, int *v, Dados *dados);
void QuicksortRec_ColetaDados(int l, int r, int *v, Dados *dados);
void ParticionaAleatorioDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, Dados *dados);

// Heapsort
void Heapsort(int n, int *v);
void ConstroiHeap(int n, int *v);
void Heapify(int i, int n, int *v);
void Heapsort_CD(int n, int *v, Dados *dados);
void ConstroiHeap_ColetaDados(int n, int *v, Dados *dados);
void Heapify_ColetaDados(int i, int n, int *v, Dados *dados);

// Contagem
void Contagem(int n, int *v);
void Contagem_CD(int n, int *v, Dados *dados);

// Balde
void Balde(int n, int *v);
void InsereOrdenado(int valor, Celula** l);
void Balde_CD(int n, int *v, Dados *dados);
void InsereOrdenado_ColetaDados(int valor, Celula** cabeca, Dados* dados);

// Radixsort
void RadixsortC(int n, int *v);
void RadixsortB(int n, int *v);
void ContagemDigital(int p, int n,  int* v);
void BaldeDigital(int p, int n, int *v);
int d(int p, int valor);
void RadixsortC_CD(int n, int *v, Dados *dados);
void RadixsortB_CD(int n, int *v, Dados *dados);
void ContagemDigital_ColetaDados(int p, int n,  int* v, Dados *dados);
void BaldeDigital_ColetaDados(int p, int n, int *v, Dados *dados);

#endif
