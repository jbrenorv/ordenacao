#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__

#include "utils.h"

#define _10e9 1000000000
#define QS_LIMITE 16

// Bolha
void Bolha(int n, int *v);
void Bolha_CD(int n, int *v, Dados *dados);

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
void MergesortRec(int l, int r, int *v, int *v_aux);
void Merge(int l, int m, int r, int *v, int *v_aux);
void Mergesort_CD(int n, int *v, Dados *dados);
void MergesortRec_CD(int l, int r, int *v, int *v_aux, Dados *dados);
void Merge_CD(int l, int m, int r, int *v, int *v_aux, Dados *dados);

// Quicksort
void Quicksort(int n, int *v);
void QuicksortRec(int l, int r, int *v);
void Quicksort_CD(int n, int *v, Dados *dados);
void QuicksortRec_CD(int l, int r, int *v, Dados *dados);

// QuicksortPF
void QuickSortPF(int n, int *v);
void QuickSortPFRec(int p, int r, int *v);
int Separa(int p, int r, int *v);
void QuickSortPF_CD(int n, int *v, Dados *dados);
void QuickSortPFRec_CD(int p, int r, int *v, Dados *dados);
int Separa_CD(int p, int r, int *v, Dados *dados);

// Quicksort - Insercao
void QuicksortI(int n, int *v);
void QuicksortIRec(int l, int r, int *v);
void QuicksortI_CD(int n, int *v, Dados *dados);
void QuicksortIRec_CD(int l, int r, int *v, Dados *dados);

// Introsort
void Introsort(int n, int *v);
void IntrosortRec(int l, int r, int d, int *v);
void Introsort_CD(int n, int *v, Dados *dados);
void IntrosortRec_CD(int l, int r, int d, int *v, Dados *dados);

// Particiona
void MoveMedianaFim(int l, int r, int *v);
void MoveMedianaFim_CD(int l, int r, int *v, Dados *dados);
int Particiona(int l, int r, int *v);
int Particiona_CD(int l, int r, int *v, Dados *dados);
int Particiona2(int l, int r, int *v);
int Particiona2_CD(int l, int r, int *v, Dados *dados);

// Heapsort
void Heapsort(int n, int *v);
void ConstroiHeap(int n, int *v);
void Heapify(int i, int n, int *v);
void Heapsort_CD(int n, int *v, Dados *dados);
void ConstroiHeap_CD(int n, int *v, Dados *dados);
void Heapify_CD(int i, int n, int *v, Dados *dados);

// Contagem
void Contagem(int n, int *v);
void Contagem_CD(int n, int *v, Dados *dados);

// Balde
void Balde(int n, int *v);
void InsereOrdenado(int valor, Celula **cabeca);
void Balde_CD(int n, int *v, Dados *dados);
void InsereOrdenado_CD(int valor, Celula **cabeca, Dados *dados);

// Radixsort
void RadixsortC(int n, int *v);
void RadixsortB(int n, int *v);
void ContagemDigital(int posicao, int n,  int *v);
void BaldeDigital(int posicao, int n, int *v);
int ObterDigito(int posicao, int valor);
void RadixsortC_CD(int n, int *v, Dados *dados);
void RadixsortB_CD(int n, int *v, Dados *dados);
void ContagemDigital_CD(int posicao, int n,  int *v, Dados *dados);
void BaldeDigital_CD(int posicao, int n, int *v, Dados *dados);

void Troca(int *a, int *b);

#endif
