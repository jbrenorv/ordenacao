# include "../ordenacao.h"

void Merge(int l, int m, int r, int *v, int *aux) {
    CopiaVetor(r - l, v+l, aux+l);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (v[i] <= v[j]) v[k++] = v[i++];
        else v[k++] = v[i++];
    }
    while (i < m) v[k++] = v[i++];
}

void MergeSortRecursivo(int l, int r, int *v, int *aux) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergeSortRecursivo(l, m, v, aux);
        MergeSortRecursivo(m, r, v, aux);
        Merge(l, m, r, v, aux);
    }
}

void MergeSort(int n, int *v) {
    int* aux = AlocaVetor(n);
    MergeSortRecursivo(0, n, v, aux);
    free(aux);
}

void Merge_ColetaDados(int l, int m, int r, int *v, int *aux, dados_execucao *dados) {
    CopiaVetor(r - l, v+l, aux+l);
    dados->movimentacoes += r - l;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (v[i] <= v[j]) v[k++] = v[i++];
        else v[k++] = v[i++];
        dados->comparacoes++;
        dados->movimentacoes++;
    }
    while (i < m) {
        v[k++] = v[i++];
        dados->movimentacoes++;
    }
}

void MergeSortRecursivo_ColetaDados(int l, int r, int *v, int *aux, dados_execucao *dados) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergeSortRecursivo_ColetaDados(l, m, v, aux, dados);
        MergeSortRecursivo_ColetaDados(m, r, v, aux, dados);
        Merge_ColetaDados(l, m, r, v, aux, dados);
    }
}

void MergeSort_ColetaDados(int n, int *v, dados_execucao *dados) {
    int* aux = AlocaVetor(n);
    MergeSortRecursivo_ColetaDados(0, n, v, aux, dados);
    free(aux);
}
