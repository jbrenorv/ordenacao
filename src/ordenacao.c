#include "ordenacao.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void Bolha(int n, int *v) {
    char trocou;
    for (int i = n - 1; i > 0; i--) {
        trocou = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                Troca(v + j, v + j + 1);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}


void Bolha_CD(int n, int *v, Dados *dados) {
    char trocou;
    for (int i = n - 1; i > 0; i--) {
        trocou = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                Troca(v + j, v + j + 1);
                trocou = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
        if (!trocou) break;
    }
}


void Coquetel(int n, int *v) {
    int i = 0, j = n - 1, trocou = 1;
    while (trocou) {
        trocou = 0;
        for (int k = i; k < j; k++)
            if (v[k] > v[k + 1]) {
                Troca(v + k, v + k + 1);
                trocou = 1;
            }
        if (!trocou) return;
        trocou = 0, j--;
        for (int k = j - 1; k >= i; k--)
            if (v[k] > v[k + 1]) {
                Troca(v + k, v + k + 1);
                trocou = 1;
            }
        i++;
    }
}


void Coquetel_CD(int n, int *v, Dados *dados) {
    int i = 0, j = n - 1, trocou = 1;
    while (trocou) {
        trocou = 0;
        for (int k = i; k < j; k++) {
            if (v[k] > v[k + 1]) {
                Troca(v + k, v + k + 1);
                trocou = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
        if (!trocou) return;
        trocou = 0, j--;
        for (int k = j - 1; k >= i; k--) {
            if (v[k] > v[k + 1]) {
                Troca(v + k, v + k + 1);
                trocou = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
        i++;
    }
}


void Selecao(int n, int *v) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (v[j] > v[k])
                j = k;
        if (j > i) Troca(v + i, v + j);
    }
}


void Selecao_CD(int n, int *v, Dados *dados) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (v[j] > v[k])
                j = k;
            dados->comparacoes++;
        }
        if (j > i) {
            Troca(v + i, v + j);
            dados->movimentacoes += 3;
        }
    }
}


void Insercao(int n, int *v) {
    H_Ordenacao(n, 1, v);
}


void Insercao_CD(int n, int *v, Dados *dados) {
    H_Ordenacao_CD(n, 1, v, dados);
}


void H_Ordenacao(int n, int h, int *v) {
    int chave, j;
    for (int i = h; i < n; i++) {
        chave = v[i];
        for (j = i; j >= h && v[j - h] > chave; j -= h)
            v[j] = v[j - h];
        v[j] = chave;
    }
}


void H_Ordenacao_CD(int n, int h, int *v, Dados *dados) {
    int chave, j;
    for (int i = h; i < n; i++) {
        chave = v[i];
        for (j = i; j >= h && v[j - h] > chave; j -= h) {
            v[j] = v[j - h];
            dados->comparacoes++;
            dados->movimentacoes++;
        }
        v[j] = chave;
        if (j >= h) dados->comparacoes++;
        dados->movimentacoes += 2;
    }
}


// [Artigo] Marcin Ciura 2001: Best Increments for the Average Case of Shellsort
// [ PDF  ] https://web.archive.org/web/20180923235211/http://sun.aei.polsl.pl/~mciura/publikacje/shellsort.pdf
// CiuraOriginalSeq = 1, 4, 10, 23, 57, 132, 301, 701, 1750
// CiuraSeq[i] = (i < 10 ? CiuraOriginalSeq[i] : 2.25 * Ciura[i - 1])
// Os 15 primeiros elementos invertidos:
int const CiuraSeq[] = { 227095, 100931, 44858, 19937, 8861, 3938, 1750, 701, 301, 132, 57, 23, 10, 4, 1 };


void Shellsort(int n, int *v) {
    for (int i = 0; i < 15; i++)
        H_Ordenacao(n, CiuraSeq[i], v);
}


void Shellsort_CD(int n, int *v, Dados *dados) {
    for (int i = 0; i < 15; i++)
        H_Ordenacao_CD(n, CiuraSeq[i], v, dados);
}


void Mergesort(int n, int *v) {
    int *v_aux = AlocaVetor(n);
    MergesortRec(0, n, v, v_aux);
    free(v_aux);
}


void MergesortRec(int l, int r, int *v, int *v_aux) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergesortRec(l, m, v, v_aux);
        MergesortRec(m, r, v, v_aux);
        Merge(l, m, r, v, v_aux);
    }
}


void Merge(int l, int m, int r, int *v, int *v_aux) {
    CopiaVetor(r - l, v+l, v_aux+l);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (v_aux[i] <= v_aux[j]) v[k++] = v_aux[i++];
        else v[k++] = v_aux[j++];
    }
    while (i < m) v[k++] = v_aux[i++];
}


void Mergesort_CD(int n, int *v, Dados *dados) {
    int *v_aux = AlocaVetor(n);
    MergesortRec_CD(0, n, v, v_aux, dados);
    free(v_aux);
}


void MergesortRec_CD(int l, int r, int *v, int *v_aux, Dados *dados) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergesortRec_CD(l, m, v, v_aux, dados);
        MergesortRec_CD(m, r, v, v_aux, dados);
        Merge_CD(l, m, r, v, v_aux, dados);
    }
}


void Merge_CD(int l, int m, int r, int *v, int *v_aux, Dados *dados) {
    CopiaVetor(r - l, v+l, v_aux+l);
    dados->movimentacoes += r - l;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (v_aux[i] <= v_aux[j]) v[k++] = v_aux[i++];
        else v[k++] = v_aux[j++];
        dados->comparacoes++;
        dados->movimentacoes++;
    }
    while (i < m) {
        v[k++] = v_aux[i++];
        dados->movimentacoes++;
    }
}


void Quicksort(int n, int *v) {
    QuicksortRec(0, n - 1, v);
}


void QuicksortRec(int l, int r, int *v) {
    while (l < r) {
        int i = Particiona(l, r, v);
        if (i - l < r - i) {
            QuicksortRec(l, i - 1, v);
            l = i + 1;
        } else {
            QuicksortRec(i + 1, r, v);
            r = i - 1;
        }
    }
}


void Quicksort_CD(int n, int *v, Dados *dados) {
    QuicksortRec_CD(0, n - 1, v, dados);
}


void QuicksortRec_CD(int l, int r, int *v, Dados *dados) {
    while (l < r) {
        int i = Particiona_CD(l, r, v, dados);
        if (i - l < r - i) {
            QuicksortRec_CD(l, i - 1, v, dados);
            l = i + 1;
        } else {
            QuicksortRec_CD(i + 1, r, v, dados);
            r = i - 1;
        }
    }
}


void QuicksortI(int n, int *v) {
    QuicksortIRec(0, n - 1, v);
    Insercao(n, v);
}


void QuicksortIRec(int l, int r, int *v) {
    while (r - l > QS_LIMITE) {
        int i = Particiona2(l, r, v);
        if (i - l < r - i) {
            QuicksortIRec(l, i, v);
            l = i + 1;
        } else {
            QuicksortIRec(i, r, v);
            r = i - 1;
        }
    }
}


void QuicksortI_CD(int n, int *v, Dados *dados) {
    QuicksortIRec_CD(0, n - 1, v, dados);
    Insercao_CD(n, v, dados);
}


void QuicksortIRec_CD(int l, int r, int *v, Dados *dados) {
    while (r - l > QS_LIMITE) {
        int i = Particiona2_CD(l, r, v, dados);
        if (i - l < r - i) {
            QuicksortIRec_CD(l, i, v, dados);
            l = i + 1;
        } else {
            QuicksortIRec_CD(i, r, v, dados);
            r = i - 1;
        }
    }
}


void Introsort(int n, int *v) {
    IntrosortRec(0, n - 1, log2(n) * 2, v);
    Insercao(n, v);
}


void IntrosortRec(int l, int r, int d, int *v) {
    while (r - l > QS_LIMITE) {
        if (d == 0) {
            Heapsort(r - l + 1, v + l);
            return;
        }
        --d;
        int i = Particiona2(l, r, v);
        IntrosortRec(i, r, d, v);
        r = i - 1;
    }
}


void Introsort_CD(int n, int *v, Dados *dados) {
    IntrosortRec_CD(0, n - 1, log2(n) * 2, v, dados);
    Insercao_CD(n, v, dados);
}


void IntrosortRec_CD(int l, int r, int d, int *v, Dados *dados) {
    while (r - l > QS_LIMITE) {
        if (d == 0) {
            Heapsort_CD(r - l + 1, v + l, dados);
            return;
        }
        --d;
        int i = Particiona2_CD(l, r, v, dados);
        IntrosortRec_CD(i, r, d, v, dados);
        r = i - 1;
    }
}


int Particiona(int l, int r, int *v) {
    MoveMedianaFim(l, r, v);
    int pivo = v[r], j = l;
    for (int i = l; i < r; i++) {
        if (v[i] <= pivo) {
            Troca(v + j, v + i);
            j++;
        }
    }
    v[r] = v[j], v[j] = pivo;
    return j;
}


int Particiona_CD(int l, int r, int *v, Dados *dados) {
    MoveMedianaFim_CD(l, r, v, dados);
    int pivo = v[r], j = l;
    for (int i = l; i < r; i++) {   
        if (v[i] <= pivo) {
            Troca(v + j, v + i);
            j++;
            dados->movimentacoes += 3;
        }
        dados->comparacoes++;
    }
    v[r] = v[j], v[j] = pivo;
    dados->movimentacoes += 3;
    return j;
}


int Particiona2(int l, int r, int *v) {
    MoveMedianaFim(l, r, v);
    int pivot = v[r];
    while (1) {
        while (v[l] < pivot) ++l;
        while (pivot < v[r]) --r;
        if (!(l < r)) return l;
        Troca(v + l, v + r);
        ++l;
        --r;
    }
}


int Particiona2_CD(int l, int r, int *v, Dados *dados) {
    MoveMedianaFim_CD(l, r, v, dados);
    int pivot = v[r];
    dados->movimentacoes++;
    while (1) {
        while (v[l] < pivot) {
            ++l;
            dados->comparacoes++;
        }
        dados->comparacoes++;
        while (pivot < v[r]) {
            --r;
            dados->comparacoes++;
        }
        dados->comparacoes++;
        if (!(l < r)) return l;
        Troca(v + l, v + r);
        dados->movimentacoes++;
        ++l;
        --r;
    }
}


void MoveMedianaFim(int l, int r, int *v) {
    int m = (l + r) / 2;
    if (v[l] < v[m]) Troca(v + l, v + m);
    if (v[r] < v[m]) Troca(v + r, v + m);
    if (v[l] < v[r]) Troca(v + l, v + r);
}


void MoveMedianaFim_CD(int l, int r, int *v, Dados *dados) {
    int m = (l + r) / 2;
    if (v[l] < v[m]) {
        Troca(v + l, v + m);
        dados->movimentacoes += 3;
    }
    if (v[r] < v[m]) {
        Troca(v + r, v + m);
        dados->movimentacoes += 3;
    }
    if (v[l] < v[r]) {
        Troca(v + l, v + r);
        dados->movimentacoes += 3;
    }
}


void Heapsort(int n, int *v) {
    ConstroiHeap(n, v);
    for (int i = n - 1; i > 0; i--) {
        Troca(v, v + i);
        Heapify(0, i, v);
    }
}


void ConstroiHeap(int n, int *v) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(i, n, v);
}


void Heapify(int i, int n, int *v) {
    int j = 2 * i + 1;
    while (j < n) {
        if (j < n - 1 && v[j] < v[j + 1]) j++;
        if (v[i] >= v[j]) break;
        else {
            Troca(v + i, v + j);
            i = j;
            j = 2 * j + 1;
        }
    }
}


void Heapsort_CD(int n, int *v, Dados *dados) {
    ConstroiHeap_CD(n, v,dados);
    for (int i = n - 1; i > 0; i--) {
        Troca(v + 0, v + i);
        Heapify_CD(0, i, v, dados);
        dados->movimentacoes += 3;
    }
}


void ConstroiHeap_CD(int n, int *v, Dados *dados) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify_CD(i, n, v, dados);
}


void Heapify_CD(int i, int n, int *v, Dados *dados) {
    int j = 2 * i + 1;
    while (j < n) {
        if (j < n - 1) {
            if (v[j] < v[j + 1]) j++;
            dados->comparacoes++;
        }
        if (v[i] >= v[j]) {
            dados->comparacoes++;
            break;
        }
        else {
            Troca(v + i, v + j);
            i = j;
            j = 2 * j + 1;
            dados->movimentacoes += 3;
            dados->comparacoes++;
        }
    }
}


void Contagem(int n, int *v) {
    int M = MaxEl(n, v);
    int *contagem = AlocaVetorLimpo(M + 1);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[v[i]]++;
    for (int i = 1; i <= M; i++) contagem[i] += contagem[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        v_aux[contagem[v[i]] - 1] = v[i];
        contagem[v[i]]--;
    }
    CopiaVetor(n, v_aux, v);
    free(contagem);
    free(v_aux);
}


void Contagem_CD(int n, int *v, Dados *dados) {
    int M = MaxEl_CD(n, v, dados);
    int *contagem = AlocaVetorLimpo(M + 1);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[v[i]]++;
    for (int i = 1; i <= M; i++) contagem[i] += contagem[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        v_aux[contagem[v[i]] - 1] = v[i];
        contagem[v[i]]--;
    }
    CopiaVetor(n, v_aux, v);
    dados->movimentacoes += 2 * n;
    free(contagem);
    free(v_aux);
}


void Balde(int n, int *v) {
    Celula **baldes = (Celula **) calloc(n, sizeof(Celula*));
    int M = MaxEl(n, v);
    for (int i = n - 1; i >= 0; i--) {
        int j = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[j]);
    }
    for (int i = 0, k = 0; i < n; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}


void Balde_CD(int n, int *v, Dados *dados) {
    Celula **baldes = (Celula**) calloc(n, sizeof(Celula*));
    int M = MaxEl_CD(n, v, dados);
    for (int i = n - 1; i >= 0; i--) {
        int j = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado_CD(v[i], &baldes[j], dados);
    }
    for (int i = 0, k = 0; i < n; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
        }
    }
    free(baldes);
}


void RadixsortC(int n, int *v) {
    int M = MaxEl(n, v);
    for (int p = 1; M / p > 0; p *= 10)
        ContagemDigital(p, n, v);
}


void ContagemDigital(int p, int n,  int *v) {
    int *contagem = AlocaVetorLimpo(10);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[ObterDigito(p, v[i])]++;
    for (int i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int j = ObterDigito(p, v[i]);
        v_aux[contagem[j] - 1] = v[i];
        contagem[j]--;
    }
    for (int i = 0; i < n; i++) v[i] = v_aux[i];
    free(contagem);
    free(v_aux);
}


void RadixsortC_CD(int n, int *v, Dados *dados) {
    int M = MaxEl_CD(n, v, dados);
    for (int p = 1; M / p > 0; p *= 10)
        ContagemDigital_CD(p, n, v, dados);
}


void ContagemDigital_CD(int p, int n,  int *v, Dados *dados) {
    int *contagem = AlocaVetorLimpo(10);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[ObterDigito(p, v[i])]++;
    for (int i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int j = ObterDigito(p, v[i]);
        v_aux[contagem[j] - 1] = v[i];
        contagem[j]--;
    }
    CopiaVetor(n, v_aux, v);
    dados->movimentacoes += 2 * n;
    free(contagem);
    free(v_aux);
}


void RadixsortB(int n, int *v) {
    int M = MaxEl(n, v);
    for (int p = 1; M / p > 0; p *= 10)
        BaldeDigital(p, n, v);
}


void BaldeDigital(int p, int n, int *v) {
    Celula **baldes = (Celula**) calloc(10, sizeof(Celula*));
    for (int i = n - 1; i >= 0; i--) {
        int j = ObterDigito(p, v[i]);
        Celula *celula = CriaCelula(v[i]);
        celula->prox = baldes[j];
        baldes[j] = celula;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}


void RadixsortB_CD(int n, int *v, Dados *dados) {
    int M = MaxEl_CD(n, v, dados);
    for (int p = 1; M / p > 0; p *= 10)
        BaldeDigital_CD(p, n, v, dados);
}


void BaldeDigital_CD(int p, int n, int *v, Dados *dados) {
    Celula **baldes = (Celula **) calloc(10, sizeof(Celula *));
    for (int i = n - 1; i >= 0; i--) {
        Celula *celula = CriaCelula(v[i]);
        celula->prox = baldes[ObterDigito(p, v[i])];
        baldes[ObterDigito(p, v[i])] = celula;
        dados->movimentacoes++;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
        }
    }
    free(baldes);
}


int ObterDigito(int p, int valor) {
    return (valor / p) % 10;
}


Celula *CriaCelula(int valor) {
    Celula *celula = (Celula *) malloc(sizeof(Celula));
    celula->valor = valor;
    celula->prox = NULL;
    return celula;
}


void InsereOrdenado(int valor, Celula **balde) {
    Celula *celula = CriaCelula(valor);
    if (*balde == NULL || (*balde)->valor >= valor) {
        celula->prox = *balde;
        *balde = celula;
    } else {
        Celula *atual = *balde;
        while (atual->prox && atual->prox->valor < valor)
            atual = atual->prox;
        celula->prox = atual->prox;
        atual->prox = celula;
    }
}


void InsereOrdenado_CD(int valor, Celula **balde, Dados *dados) {
    Celula *celula = CriaCelula(valor);
    dados->movimentacoes++;
    dados->comparacoes++;
    if (*balde == NULL || (*balde)->valor >= valor) {
        celula->prox = *balde;
        *balde = celula;
        dados->movimentacoes += 2;
    } else {
        Celula *atual = *balde;
        while (atual->prox && atual->prox->valor < valor) {
            atual = atual->prox;
            dados->movimentacoes++;
            dados->comparacoes++;
        }
        celula->prox = atual->prox;
        atual->prox = celula;
        dados->movimentacoes += 2;
    }
}


Parametros ResolveParametros(int argc, char **argv) {
    if (argc < 5) {
        FinalizaExecucao("Informe todos os parametros necessarios");
    }

    Parametros parametros;
    parametros.tamanho = atoi(argv[2]);
    parametros.tipo = atoi(argv[3]);
    parametros.arquivo_saida = argv[1];
    parametros.execucao = atoi(argv[4]);

    if (parametros.tamanho < 1 || parametros.tamanho > MAX_TAM)
        FinalizaExecucao("Tamanho invalido");

    if (parametros.tipo < CRE || parametros.tipo > M3K)
        FinalizaExecucao("Tipo invalido");

    if (parametros.tipo == M3K && parametros.tamanho % 4 != 0)
        FinalizaExecucao("Para usar o tipo M3K (3), o tamanho precisa ser multiplo de 4");

    return parametros;
}


void FinalizaExecucao(const char *mensagem) {
    printf("Erro: %s\n", mensagem);
    exit(1);
}


int *AlocaVetor(int n) {
    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return v;
}


int *AlocaVetorLimpo(int n) {
    int *v = (int *)calloc(n, sizeof(int));
    if (v == NULL) {
        FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return v;
}


int GeraNumeroAleatorioNoIntervalo(int a, int b) {
    return a + rand() % (b - a + 1);
}


int *CriaVetor(int n, VTipo tipo) {
    int *v = AlocaVetor(n);
    int k = n / 2;
    for (int i = 0; i < n; ++i) {
        if (tipo == CRE)        v[i] = i;
        if (tipo == DEC)        v[i] = n - i;
        if (tipo == ALE)        v[i] = GeraNumeroAleatorioNoIntervalo(MIN_EL, MAX_EL);
        if (tipo == M3K) {
            if (i < k)
                if (i % 2 == 0) v[i] = i + 1;
                else            v[i] = k + i;
            else                v[i] = 2 * (i - k + 1);
        }
    }
    return v;
}


void CopiaVetor(int n, int *origem, int *destino) {
    for (int i = 0; i < n; ++i)
        destino[i] = origem[i];
}


void Troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int Min(int a, int b) {
    return (a < b ? a : b);
}


int Max(int a, int b) {
    return (a > b ? a : b);
}


int MaxEl(int n, int *v) {
    int res = v[0];
    for (int i = 1; i < n; i++)
        res = Max(res, v[i]);
    return res;
}


int MaxEl_CD(int n, int *v, Dados *dados) {
    int res = v[0];
    for (int i = 1; i < n; i++) {
        dados->comparacoes++;
        if (res < v[i]) {
            res = v[i];
            dados->movimentacoes++;
        }
    }
    return res;
}


void Verifica_Ordenacao(int n, int *v, AlgInfo *alg_info) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            printf("Erro em: %s\n", alg_info->nome);
            FinalizaExecucao("O v nao esta ordenado\n");
        }
    }
}


Dados ObterDados(int n, int *v, AlgInfo *alg_info) {
    Dados dados = (Dados){ 0LL, 0LL, 0.0 };

    int *v_copia = AlocaVetor(n);
    CopiaVetor(n, v, v_copia);
    alg_info->impl_coletor(n, v_copia, &dados);
    Verifica_Ordenacao(n, v_copia, alg_info);
    free(v_copia);

    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    alg_info->impl(n, v);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    dados.tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    Verifica_Ordenacao(n, v, alg_info);

    return dados;
}
