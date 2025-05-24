# include "../ordenacao.h"

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
