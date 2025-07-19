#ifndef __ORDENACAO_H__
#define __ORDENACAO_H__


#define _10e9 1000000000
#define QS_LIMITE 16
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


typedef struct AlgInfo {
    char *nome;
    int tamanho_maximo;
    void (*impl)(int, int *);
    void (*impl_coletor)(int, int *, Dados *);
    ATipo tipo;
} AlgInfo;


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


// H-ordenacao
void H_Ordenacao(int n, int h, int *v);
void H_Ordenacao_CD(int n, int h, int *v, Dados *dados);


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
int Particiona(int l, int r, int *v);
int Particiona2(int l, int r, int *v);
void MoveMedianaFim(int l, int r, int *v);
int Particiona_CD(int l, int r, int *v, Dados *dados);
int Particiona2_CD(int l, int r, int *v, Dados *dados);
void MoveMedianaFim_CD(int l, int r, int *v, Dados *dados);


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
void Balde_CD(int n, int *v, Dados *dados);


// Radixsort
void RadixsortC(int n, int *v);
void ContagemDigital(int posicao, int n, int *contagem, int *v_aux, int *v);
void RadixsortB(int n, int *v);
void BaldeDigital(int posicao, int n, int *v);
int ObterDigito(int posicao, int valor);
void RadixsortC_CD(int n, int *v, Dados *dados);
void RadixsortB_CD(int n, int *v, Dados *dados);
void ContagemDigital_CD(int posicao, int n,  int *v, Dados *dados);
void BaldeDigital_CD(int posicao, int n, int *v, Dados *dados);


// Lista ligada
typedef struct Celula {
    int valor;
    struct Celula *prox;
} Celula;
Celula *CriaCelula(int valor);
void InsereOrdenado(int valor, Celula **cabeca);
void InsereOrdenado_CD(int valor, Celula **cabeca, Dados *dados);


// Funcoes utilitarias
Parametros ResolveParametros(int argc, char **argv);
void FinalizaExecucao(const char *mensagem);
int *AlocaVetor(int n);
int *AlocaVetorLimpo(int n);
int GeraNumeroAleatorioNoIntervalo(int a, int b);
int *CriaVetor(int n, VTipo tipo);
void CopiaVetor(int n, int *origem, int *destino);
void Troca(int *a, int *b);
int Min(int a, int b);
int Max(int a, int b);
int MaxEl(int n, int *v);
int MaxEl_CD(int n, int *v, Dados *dados);
void Verifica_Ordenacao(int n, int *v, AlgInfo *alg_info);
Dados ObterDados(int n, int *v, AlgInfo *alg_info);


#endif  // __ORDENACAO_H__
