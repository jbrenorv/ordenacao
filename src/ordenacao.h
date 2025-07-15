#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include "utils.h"

#define _10e9 1000000000

// Bolha
void Bolha(int tamanho, int *vetor);
void Bolha_CD(int tamanho, int *vetor, Dados *dados);

// BolhaFlag
void BolhaFlag(int tamanho, int *vetor);
void BolhaFlag_CD(int tamanho, int *vetor, Dados *dados);

// Coquetel
void Coquetel(int tamanho, int *vetor);
void Coquetel_CD(int tamanho, int *vetor, Dados *dados);

// Selecao
void Selecao(int tamanho, int *vetor);
void Selecao_CD(int tamanho, int *vetor, Dados *dados);

// Insercao
void Insercao(int tamanho, int *vetor);
void Insercao_CD(int tamanho, int *vetor, Dados *dados);

// Shellsort
void Shellsort(int tamanho, int *vetor);
void Shellsort_CD(int tamanho, int *vetor, Dados *dados);

// Mergesort
void Mergesort(int tamanho, int *vetor);
void MergesortRec(int l, int r, int *vetor, int *vetor_aux);
void Merge(int l, int m, int r, int *vetor, int *vetor_aux);
void Mergesort_CD(int tamanho, int *vetor, Dados *dados);
void MergesortRec_CD(int l, int r, int *vetor, int *vetor_aux, Dados *dados);
void Merge_CD(int l, int m, int r, int *vetor, int *vetor_aux, Dados *dados);

// Quicksort
void Quicksort(int tamanho, int *vetor);
void QuicksortRec(int l, int r, int *vetor);
void Quicksort_CD(int tamanho, int *vetor, Dados *dados);
void QuicksortRec_CD(int l, int r, int *vetor, Dados *dados);
int Particiona(int l, int r, int *vetor);
int Particiona_CD(int l, int r, int *vetor, Dados *dados);

// Introsort
void Introsort(int tamanho, int *vetor);
void IntrosortRec(int l, int r, int d, int *vetor);
void Introsort_CD(int tamanho, int *vetor, Dados *dados);
void IntrosortRec_CD(int l, int r, int d, int *vetor, Dados *dados);

// Heapsort
void Heapsort(int tamanho, int *vetor);
void ConstroiHeap(int tamanho, int *vetor);
void Heapify(int i, int tamanho, int *vetor);
void Heapsort_CD(int tamanho, int *vetor, Dados *dados);
void ConstroiHeap_CD(int tamanho, int *vetor, Dados *dados);
void Heapify_CD(int i, int tamanho, int *vetor, Dados *dados);

// Contagem
void Contagem(int tamanho, int *vetor);
void Contagem_CD(int tamanho, int *vetor, Dados *dados);

// Balde
void Balde(int tamanho, int *vetor);
void InsereOrdenado(int valor, Celula **cabeca);
void Balde_CD(int tamanho, int *vetor, Dados *dados);
void InsereOrdenado_CD(int valor, Celula **cabeca, Dados *dados);

// Radixsort
void RadixsortC(int tamanho, int *vetor);
void RadixsortB(int tamanho, int *vetor);
void ContagemDigital(int posicao, int tamanho,  int *vetor);
void BaldeDigital(int posicao, int tamanho, int *vetor);
int ObterDigito(int posicao, int valor);
void RadixsortC_CD(int tamanho, int *vetor, Dados *dados);
void RadixsortB_CD(int tamanho, int *vetor, Dados *dados);
void ContagemDigital_CD(int posicao, int tamanho,  int *vetor, Dados *dados);
void BaldeDigital_CD(int posicao, int tamanho, int *vetor, Dados *dados);

#endif
