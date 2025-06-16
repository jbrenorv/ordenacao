#include "ordenacao.h"

void Bolha(int n, int *v) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1])
                Troca(&v[j], &v[j + 1]);
}

void Bolha_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                Troca(&v[j], &v[j + 1]);
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
}

void BolhaFlag(int n, int *v) {
    for (int i = 0, flag = 1; i < n - 1 && flag; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                Troca(&v[j], &v[j + 1]);
                flag = 1;
            }
        }
    }
}

void BolhaFlag_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int i = 0, flag = 1; i < n - 1 && flag; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                Troca(&v[j], &v[j + 1]);
                flag = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
}

void Coquetel(int n, int *v) {
    int flag = 1, i = 0, j = n - 1;
    while (flag) {
        flag = 0;
        for (int k = i; k < j; k++)
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
            }
        if (!flag) return;
        flag = 0, j--;
        for (int k = j - 1; k >= i; k--)
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
            }
        i++;
    }
}

void Coquetel_ColetaDados(int n, int *v, dados_execucao *dados) {
    int flag = 1, i = 0, j = n - 1;
    while (flag) {
        flag = 0;
        for (int k = i; k < j; k++) {
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
            dados->iteracoes++;
        }
        if (!flag) return;
        flag = 0, j--;
        for (int k = j - 1; k >= i; k--) {
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
            dados->iteracoes++;
        }
        i++;
        dados->iteracoes++;
    }
}

void Selecao(int n, int *v) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (v[j] > v[k])
                j = k;
        if (j > i) Troca(&v[i], &v[j]);
    }
}

void Selecao_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (v[j] > v[k])
                j = k;
            dados->comparacoes++;
            dados->iteracoes++;
        }
        if (j > i) Troca(&v[i], &v[j]);
        dados->movimentacoes += 3;
        dados->iteracoes++;
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

void Insercao_ColetaDados(int n, int *v, dados_execucao *dados) {
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = v[i];
        for (j = i; j > 0 && v[j - 1] > chave; j--) {
            v[j] = v[j - 1];
            dados->comparacoes++;
            dados->movimentacoes++;
            dados->iteracoes++;
        }
        v[j] = chave;
        if (j > 0) dados->comparacoes++;
        dados->movimentacoes += 2;
        dados->iteracoes++;
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

void Shellsort_ColetaDados(int n, int *v, dados_execucao *dados) {
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
                dados->iteracoes++;
            }
            v[j] = chave;
            if (j >= h) dados->comparacoes++;
            dados->movimentacoes += 2;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
}

void Mergesort(int n, int *v) {
    int* aux = AlocaVetor(n);
    MergesortRec(0, n, v, aux);
    free(aux);
}

void MergesortRec(int l, int r, int *v, int *aux) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergesortRec(l, m, v, aux);
        MergesortRec(m, r, v, aux);
        Merge(l, m, r, v, aux);
    }
}

void Merge(int l, int m, int r, int *v, int *aux) {
    CopiaVetor(r - l, v+l, aux+l);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (aux[i] <= aux[j]) v[k++] = aux[i++];
        else v[k++] = aux[j++];
    }
    while (i < m) v[k++] = aux[i++];
}

void Mergesort_ColetaDados(int n, int *v, dados_execucao *dados) {
    int* aux = AlocaVetor(n);
    MergesortRec_ColetaDados(0, n, v, aux, dados);
    free(aux);
}

void MergesortRec_ColetaDados(int l, int r, int *v, int *aux, dados_execucao *dados) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergesortRec_ColetaDados(l, m, v, aux, dados);
        MergesortRec_ColetaDados(m, r, v, aux, dados);
        Merge_ColetaDados(l, m, r, v, aux, dados);
    }
}

void Merge_ColetaDados(int l, int m, int r, int *v, int *aux, dados_execucao *dados) {
    CopiaVetor(r - l, v+l, aux+l);
    dados->movimentacoes += r - l;
    dados->iteracoes += r - l;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (aux[i] <= aux[j]) v[k++] = aux[i++];
        else v[k++] = aux[j++];
        dados->comparacoes++;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    while (i < m) {
        v[k++] = aux[i++];
        dados->movimentacoes++;
        dados->iteracoes++;
    }
}

void Quicksort(int n, int *v) {
    QuicksortRec(0, n - 1, v);
}

void QuicksortRec(int l, int r, int *v) {
    while (l < r) {
        int i, j;
        ParticionaAleatorioDuplo(l, r, &i, &j, v);
        if (i - l < r - j) {
            QuicksortRec(l, i - 1, v);
            l = j + 1;
        } else {
            QuicksortRec(j + 1, r, v);
            r = i - 1;
        }
    }
}

void ParticionaAleatorioDuplo(int l, int r, int *i, int *j, int *v) {
    Troca(&v[GeraNumeroAleatorioNoIntervalo(l, r)], &v[r]);
    int pivo = v[r], k = l;
    *i = l, *j = r;
    while (k <= *j) {
        if (v[k] < pivo) Troca(&v[(*i)++], &v[k++]);
        else if (v[k] > pivo) Troca(&v[(*j)--], &v[k]);
        else k++;
    }
}

void Quicksort_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuicksortRec_ColetaDados(0, n - 1, v, dados);
}

void QuicksortRec_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    while (l < r) {
        int i, j;
        ParticionaAleatorioDuplo_ColetaDados(l, r, &i, &j, v, dados);
        if (i - l < r - j) {
            QuicksortRec_ColetaDados(l, i - 1, v, dados);
            l = j + 1;
        } else {
            QuicksortRec_ColetaDados(j + 1, r, v, dados);
            r = i - 1;
        }
        dados->iteracoes++;
    }
}

void ParticionaAleatorioDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, dados_execucao *dados) {
    Troca(&v[GeraNumeroAleatorioNoIntervalo(l, r)], &v[r]);
    dados->movimentacoes += 3;
    int pivo = v[r], k = l;
    dados->movimentacoes++;
    *i = l, *j = r;
    while (k <= *j) {
        if (v[k] < pivo) {
            Troca(&v[*i], &v[k]);
            (*i)++, k++;
            dados->movimentacoes += 3;
            dados->comparacoes += 1;
        } else if (v[k] > pivo) {
            Troca(&v[*j], &v[k]);
            (*j)--;
            dados->movimentacoes += 3;
            dados->comparacoes += 2;
        } else {
            k++;
            dados->comparacoes += 2;
        }
        dados->iteracoes++;
    }
}

void Heapsort(int n, int *v) {
    ConstroiHeap(n, v);
    for (int i = n - 1; i > 0; i--) {
        Troca(&v[0], &v[i]);
        Heapify(0, i, v);
    }
}

void ConstroiHeap(int n, int *v) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(i, n, v);
}

void Heapify(int i, int n, int *v) {
    int j = i, k;
    while (2 * j + 1 < n) {
        k = 2 * j + 1;
        if (k < n - 1 && v[k] < v[k+1]) k++;
        if (v[j] >= v[k]) break;
        else {
            Troca(&v[j], &v[k]);
            j = k;
        }
    }
}

void Heapsort_ColetaDados(int n, int *v, dados_execucao *dados) {
    ConstroiHeap_ColetaDados(n, v,dados);
    for (int i = n - 1; i > 0; i--) {
        Troca(&v[0], &v[i]);
        Heapify_ColetaDados(0, i, v,dados);
        dados->movimentacoes += 3;
        dados->iteracoes++;
    }
}

void ConstroiHeap_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        Heapify_ColetaDados(i, n, v,dados);
        dados->iteracoes++;
    }
}

void Heapify_ColetaDados(int i, int n, int *v, dados_execucao *dados) {
    int j = i, k;
    while (2 * j + 1 < n) {
        k = 2 * j + 1;
        if (k < n - 1 && v[k] < v[k+1]) k++;
        if (v[j] >= v[k]) break;
        else {
            Troca(&v[j], &v[k]);
            dados->movimentacoes += 3;
            j = k;
        }
        dados->comparacoes += 2;
        dados->iteracoes++;
    }
}

void Contagem(int n, int *v) {
    int M = ObterMaiorElemento(n, v);
    int* cnt = AlocaVetorLimpo(M + 1);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) cnt[v[i]]++;
    for (int i = 1; i <= M; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) aux[i] = v[i];
    for (int i = n - 1; i >= 0; i--) {
        v[cnt[aux[i]] - 1] = aux[i];
        cnt[aux[i]]--;
    }
    free(cnt);
    free(aux);
}

void Contagem_ColetaDados(int n, int *v, dados_execucao *dados) {
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    int* cnt = AlocaVetorLimpo(M + 1);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
        dados->iteracoes++;
    }
    for (int i = 1; i <= M; i++) {
        cnt[i] += cnt[i - 1];
        dados->iteracoes++;
    }
    for (int i = 0; i < n; i++) {
        aux[i] = v[i];
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = n - 1; i >= 0; i--) {
        v[cnt[aux[i]] - 1] = aux[i];
        cnt[aux[i]]--;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    free(cnt);
    free(aux);
}

void Balde(int n, int *v) {
    celula** baldes = (celula**) calloc(n, sizeof(celula*));
    int M = ObterMaiorElemento(n, v);
    for (int i = n - 1; i >= 0; i--) {
        int index = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[index]);
    }
    for (int i = 0, k = 0; i < n; i++) {
        celula* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}

void InsereOrdenado(int valor, celula** balde) {
    celula* cel = CriaCelula(valor);
    if (*balde == NULL || (*balde)->valor >= valor) {
        cel->prox = *balde;
        *balde = cel;
    } else {
        celula* atual = *balde;
        while (atual->prox && atual->prox->valor < valor)
            atual = atual->prox;
        cel->prox = atual->prox;
        atual->prox = cel;
    }
}

void Balde_ColetaDados(int n, int *v, dados_execucao *dados) {
    celula** baldes = (celula**) calloc(n, sizeof(celula*));
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    for (int i = n - 1; i >= 0; i--) {
        int index = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[index]);
        dados->iteracoes++;
    }
    for (int i = 0, k = 0; i < n; i++) {
        celula* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
    free(baldes);
}

void InsereOrdenado_ColetaDados(int valor, celula** balde, dados_execucao* dados) {
    celula* cel = CriaCelula(valor);
    dados->movimentacoes++;
    dados->comparacoes++;
    if (*balde == NULL || (*balde)->valor >= valor) {
        cel->prox = *balde;
        *balde = cel;
        dados->movimentacoes += 2;
    } else {
        celula* atual = *balde;
        while (atual->prox && atual->prox->valor < valor) {
            atual = atual->prox;
            dados->movimentacoes++;
            dados->comparacoes++;
            dados->iteracoes++;
        }
        cel->prox = atual->prox;
        atual->prox = cel;
        dados->movimentacoes += 2;
    }
}

void RadixsortContagem(int n, int *v) {
    for (int p = 1; p < _10e9; p *= 10)
        ContagemDigital(p, n, v);
}

void RadixsortBalde(int n, int *v) {
    for (int p = 1; p < _10e9; p *= 10)
        BaldeDigital(p, n, v);
}

void ContagemDigital(int p, int n,  int* v) {
    int* count = AlocaVetorLimpo(10);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) count[d(p, v[i])]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        aux[count[d(p, v[i])] - 1] = v[i];
        count[d(p, v[i])]--;
    }
    for (int i = 0; i < n; i++) v[i] = aux[i];
    free(count);
    free(aux);
}

void BaldeDigital(int p, int n, int *v) {
    celula** baldes = (celula**) calloc(10, sizeof(celula*));
    for (int i = n - 1; i >= 0; i--) {
        celula* cel = CriaCelula(v[i]);
        cel->prox = baldes[d(p, v[i])];
        baldes[d(p, v[i])] = cel;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        celula* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}

int d(int p, int valor) {
    return (valor / p) % 10;
}

void RadixsortContagem_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int p = 1; p < _10e9; p *= 10) {
        ContagemDigital_ColetaDados(p, n, v, dados);
        dados->iteracoes++;
    }
}

void RadixsortBalde_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int p = 1; p < _10e9; p *= 10) {
        BaldeDigital_ColetaDados(p, n, v, dados);
        dados->iteracoes++;
    }
}

void ContagemDigital_ColetaDados(int p, int n,  int* v, dados_execucao *dados) {
    int* count = AlocaVetorLimpo(10);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) {
        count[d(p, v[i])]++;
        dados->iteracoes++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        dados->iteracoes++;
    }
    for (int i = n - 1; i >= 0; i--) {
        aux[count[d(p, v[i])] - 1] = v[i];
        count[d(p, v[i])]--;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    free(count);
    free(aux);
}

void BaldeDigital_ColetaDados(int p, int n, int *v, dados_execucao *dados) {
    celula** baldes = (celula**) calloc(10, sizeof(celula*));
    for (int i = n - 1; i >= 0; i--) {
        celula* cel = CriaCelula(v[i]);
        cel->prox = baldes[d(p, v[i])];
        baldes[d(p, v[i])] = cel;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        celula* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
    free(baldes);
}
