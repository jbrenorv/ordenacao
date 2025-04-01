# include "../ordenacao.h"

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
