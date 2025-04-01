# include "../ordenacao.h"

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
