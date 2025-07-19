#include "ordenacao.h"

#include <stdlib.h>
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
    int i = 0, j = n - 1;
    char trocou = 1;
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
    int i = 0, j = n - 1;
    char trocou = 1;
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
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = v[i];
        for (j = i; j > 0 && v[j - 1] > chave; j--)
            v[j] = v[j - 1];
        v[j] = chave;
    }
}

void Insercao_CD(int n, int *v, Dados *dados) {
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = v[i];
        for (j = i; j > 0 && v[j - 1] > chave; j--) {
            v[j] = v[j - 1];
            dados->comparacoes++;
            dados->movimentacoes++;
        }
        v[j] = chave;
        if (j > 0) dados->comparacoes++;
        dados->movimentacoes += 2;
    }
}

int const ciura[] = { 1699086440, 755149529, 335622013, 149165339, 66295706, 29464758, 
    13095448, 5820199, 2586755, 1149669, 510964, 227095, 100931, 44858, 
    19937, 8861, 3938, 1750, 701, 301, 132, 57, 23, 10, 4, 1 };

void Shellsort(int n, int *v) {
    int chave, j, h;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= n) continue;
        h = ciura[k];
        for (int i = h; i < n; i++) {
            chave = v[i];
            for (j = i; j >= h && v[j - h] > chave; j -= h)
                v[j] = v[j - h];
            v[j] = chave;
        }
    }
}

void Shellsort_CD(int n, int *v, Dados *dados) {
    int chave, j, h;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= n) continue;
        h = ciura[k];
        for (int i = h; i < n; i++) {
            chave = v[i];
            for (j = i; j >= h && v[j - h] > chave; j -= h) {
                v[j] = v[j - h];
                dados->movimentacoes++;
                dados->comparacoes++;
            }
            v[j] = chave;
            if (j >= h) dados->comparacoes++;
            dados->movimentacoes += 2;
        }
    }
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

void QuickSortPF(int n, int *v) {
    QuickSortPFRec(0, n - 1, v);
}

void QuickSortPFRec(int p, int r, int *v) {
    int j;
    while (p < r) {
        j = Separa(p, r, v);
        if (j - p < r - j) {
            QuickSortPFRec(p, j - 1, v);
            p = j + 1;
        } else {
            QuickSortPFRec(j + 1, r, v);
            r = j - 1;
        }
    }
}

void QuickSortPF_CD(int n, int *v, Dados *dados) {
    QuickSortPFRec_CD(0, n - 1, v, dados);
}

void QuickSortPFRec_CD(int p, int r, int *v, Dados *dados) {
    int j;
    while (p < r) {
        j = Separa_CD(p, r, v, dados);
        if (j - p < r - j) {
            QuickSortPFRec_CD(p, j - 1, v, dados);
            p = j + 1;
        } else {
            QuickSortPFRec_CD(j + 1, r, v, dados);
            r = j - 1;
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

int Separa(int p, int r, int *v) {
    int c, j, k;
    c = v[r]; j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            Troca(v + j, v + k);
            j++;
        }
    }
    v[r] = v[j], v[j] = c;
    return j;
}

int Separa_CD(int p, int r, int *v, Dados *dados) {
    int c, j, k;
    c = v[r]; j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            Troca(v + j, v + k);
            j++;
            dados->movimentacoes += 3;
        }
        dados->comparacoes++;
    }
    v[r] = v[j], v[j] = c;
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
    int m = l + (r - l) / 2;
    if (v[l] < v[m]) Troca(v + l, v + m);
    if (v[r] < v[m]) Troca(v + r, v + m);
    if (v[l] < v[r]) Troca(v + l, v + r);
}

void MoveMedianaFim_CD(int l, int r, int *v, Dados *dados) {
    int m = l + (r - l) / 2;
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
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify_CD(i, n, v, dados);
    }
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

// void HeapsortPF(int n, int *v) {
//     for (int i = 1; i < n; i++)
//         InsereEmHeap(i, v);
//     for (int i = n; i > 1; i--) {
//         Troca(v + 1, v + i);
//         SacodeHeap(i - 1, v);
//     }
// }

// void InsereEmHeap(int i, int *v) {
//     int j = i + 1;
//     while (j > 0 && v[j / 2] < v[j]) {
//         Troca(v + j, v + (j / 2));
//         j = j / 2;
//     }
// }

// void SacodeHeap(int i, int *v) {
//     int j = 2;
//     while (j <= i) {
//         if (j < i && v[j] < v[j + 1]) ++j;
//         if (v[j / 2] >= v[j]) break;
//         Troca(v + j, v + (j / 2));
//         j *= 2;
//     }
// }

// void HeapsortPF_CD(int n, int *v, Dados *dados) {
//     for (int i = 1; i < n; i++)
//         InsereEmHeap_CD(i, v, dados);
//     for (int i = n; i > 1; i--) {
//         Troca(v + 1, v + i);
//         SacodeHeap_CD(i - 1, v, dados);
//         dados->movimentacoes += 3;
//     }
// }

// void InsereEmHeap_CD(int i, int *v, Dados *dados) {
//     int j = i + 1;
//     while (j > 1 && v[j / 2] < v[j]) {
//         Troca(v + j, v + (j / 2));
//         j = j / 2;
//         dados->comparacoes++;
//         dados->movimentacoes += 3;
//     }
//     dados->comparacoes++;
// }

// void SacodeHeap_CD(int i, int *v, Dados *dados) {
//     int j = 2;
//     while (j <= i) {
//         if (j < i && v[j] < v[j + 1]) ++j;
//         if (j - 1 < i) dados->comparacoes++;
//         if (v[j / 2] >= v[j]) {
//             dados->comparacoes++;
//             break;
//         }
//         Troca(v + j, v + (j / 2));
//         j *= 2;
//         dados->comparacoes++;
//         dados->movimentacoes += 3;
//     }
// }

void Contagem(int n, int *v) {
    int M = MaxEl(n, v);
    int *contagem = AlocaVetorLimpo(M + 1);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[v[i]]++;
    for (int i = 1; i <= M; i++) contagem[i] += contagem[i - 1];
    for (int i = 0; i < n; i++) v_aux[i] = v[i];
    for (int i = n - 1; i >= 0; i--) {
        v[contagem[v_aux[i]] - 1] = v_aux[i];
        contagem[v_aux[i]]--;
    }
    free(contagem);
    free(v_aux);
}

void Contagem_CD(int n, int *v, Dados *dados) {
    int M = MaxEl_CD(n, v, dados);
    int *contagem = AlocaVetorLimpo(M + 1);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[v[i]]++;
    for (int i = 1; i <= M; i++) contagem[i] += contagem[i - 1];
    for (int i = 0; i < n; i++) {
        v_aux[i] = v[i];
        dados->movimentacoes++;
    }
    for (int i = n - 1; i >= 0; i--) {
        v[contagem[v_aux[i]] - 1] = v_aux[i];
        contagem[v_aux[i]]--;
        dados->movimentacoes++;
    }
    free(contagem);
    free(v_aux);
}

void Balde(int n, int *v) {
    Celula **baldes = (Celula **) calloc(n, sizeof(Celula*));
    int M = MaxEl(n, v);
    for (int i = n - 1; i >= 0; i--) {
        int index = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[index]);
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

void Balde_CD(int n, int *v, Dados *dados) {
    Celula **baldes = (Celula**) calloc(n, sizeof(Celula*));
    int M = MaxEl_CD(n, v, dados);
    for (int i = n - 1; i >= 0; i--) {
        int index = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado_CD(v[i], &baldes[index], dados);
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

void RadixsortC(int n, int *v) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10)
        ContagemDigital(posicao, n, v);
}

void RadixsortB(int n, int *v) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10)
        BaldeDigital(posicao, n, v);
}

void ContagemDigital(int posicao, int n,  int *v) {
    int *contagem = AlocaVetorLimpo(10);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[ObterDigito(posicao, v[i])]++;
    for (int i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        v_aux[contagem[ObterDigito(posicao, v[i])] - 1] = v[i];
        contagem[ObterDigito(posicao, v[i])]--;
    }
    for (int i = 0; i < n; i++) v[i] = v_aux[i];
    free(contagem);
    free(v_aux);
}

void BaldeDigital(int posicao, int n, int *v) {
    Celula **baldes = (Celula**) calloc(10, sizeof(Celula*));
    for (int i = n - 1; i >= 0; i--) {
        Celula *celula = CriaCelula(v[i]);
        celula->prox = baldes[ObterDigito(posicao, v[i])];
        baldes[ObterDigito(posicao, v[i])] = celula;
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

int ObterDigito(int posicao, int valor) {
    return (valor / posicao) % 10;
}

void RadixsortC_CD(int n, int *v, Dados *dados) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10) {
        ContagemDigital_CD(posicao, n, v, dados);
    }
}

void RadixsortB_CD(int n, int *v, Dados *dados) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10) {
        BaldeDigital_CD(posicao, n, v, dados);
    }
}

void ContagemDigital_CD(int posicao, int n,  int *v, Dados *dados) {
    int *contagem = AlocaVetorLimpo(10);
    int *v_aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) contagem[ObterDigito(posicao, v[i])]++;
    for (int i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        v_aux[contagem[ObterDigito(posicao, v[i])] - 1] = v[i];
        contagem[ObterDigito(posicao, v[i])]--;
        dados->movimentacoes++;
    }
    for (int i = 0; i < n; i++) {
        v[i] = v_aux[i];
        dados->movimentacoes++;
    }
    free(contagem);
    free(v_aux);
}

void BaldeDigital_CD(int posicao, int n, int *v, Dados *dados) {
    Celula **baldes = (Celula **) calloc(10, sizeof(Celula *));
    for (int i = n - 1; i >= 0; i--) {
        Celula *celula = CriaCelula(v[i]);
        celula->prox = baldes[ObterDigito(posicao, v[i])];
        baldes[ObterDigito(posicao, v[i])] = celula;
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

void Troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
