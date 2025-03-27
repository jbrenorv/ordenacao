# include "../ordenacao.h"

void Quicksort(int n, int *v) {
    QuicksortRec(0, n - 1, v);
}

void QuicksortProb(int n, int *v) {
    QuicksortProbRec(0, n - 1, v);
}

void QuicksortInsercao(int n, int *v) {
    QuicksortLimitado(0, n - 1, 15, v);
    Insercao(n, v);
}

void QuicksortRec(int l, int r, int *v) {
    if (l < r) {
        int j = Particiona(l, r, v);
        QuicksortRec(l, j - 1, v);
        QuicksortRec(j + 1, r, v);
    }
}

void QuicksortProbRec(int l, int r, int *v) {
    while (l < r) {
        int j = ParticionaAleatorio(l, r, v);
        if (j - l < r - j) {
            QuicksortProbRec(l, j - 1, v);
            l = j + 1;
        } else {
            QuicksortProbRec(j + 1, r, v);
            r = j - 1;
        }
    }
}

void QuicksortLimitado(int l, int r, int k, int *v) {
    while (r - l > k) {
        int i, j;
        ParticionaAleatorioDuplo(l, r, &i, &j, v);
        if (i - l < r - j) {
            QuicksortLimitado(l, i - 1, k, v);
            l = j + 1;
        } else {
            QuicksortLimitado(j + 1, r, k, v);
            r = i - 1;
        }
    }
}

int Particiona(int l, int r, int *v) {
    int pivo = v[r], j = l;
    for (int i = l; i < r; i++)
        if (v[i] <= pivo) {
            Troca(&v[j], &v[i]);
            j++;
        }
    v[r] = v[j], v[j] = pivo;
    return j;
}

void ParticionaDuplo(int l, int r, int *i, int *j, int *v) {
    int pivo = v[r], k = l;
    *i = l, *j = r;
    while (k <= *j) {
        if (v[k] < pivo) {
            Troca(&v[*i], &v[k]);
            (*i)++, k++;
        } else if (v[k] > pivo) {
            Troca(&v[*j], &v[k]);
            (*j)--;
        } else {
            k++;
        }
    }
}

int ParticionaAleatorio(int l, int r, int *v) {
    int i = l + rand() % (r - l + 1);
    Troca(&v[i], &v[r]);
    return Particiona(l, r, v);
}

void ParticionaAleatorioDuplo(int l, int r, int *i, int *j, int *v) {
    int k = l + rand() % (r - l + 1);
    Troca(&v[k], &v[r]);
    ParticionaDuplo(l, r, i, j, v);
}

void Quicksort_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuicksortRec_ColetaDados(0, n - 1, v, dados);
}

void QuicksortProb_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuicksortProbRec_ColetaDados(0, n - 1, v, dados);
}

void QuicksortInsercao_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuicksortLimitado_ColetaDados(0, n - 1, 15, v, dados);
    Insercao_ColetaDados(n, v, dados);
}

void QuicksortRec_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    if (l < r) {
        int j = Particiona_ColetaDados(l, r, v, dados);
        QuicksortRec_ColetaDados(l, j - 1, v, dados);
        QuicksortRec_ColetaDados(j + 1, r, v, dados);
    }
}

void QuicksortProbRec_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    while (l < r) {
        int j = ParticionaAleatorio_ColetaDados(l, r, v, dados);
        if (j - l < r - j) {
            QuicksortProbRec_ColetaDados(l, j - 1, v, dados);
            l = j + 1;
        } else {
            QuicksortProbRec_ColetaDados(j + 1, r, v, dados);
            r = j - 1;
        }
    }
}

void QuicksortLimitado_ColetaDados(int l, int r, int k, int *v, dados_execucao *dados) {
    while (r - l > k) {
        int i, j;
        ParticionaAleatorioDuplo_ColetaDados(l, r, &i, &j, v, dados);
        if (i - l < r - j) {
            QuicksortLimitado_ColetaDados(l, i - 1, k, v, dados);
            l = j + 1;
        } else {
            QuicksortLimitado_ColetaDados(j + 1, r, k, v, dados);
            r = i - 1;
        }
    }
}

int Particiona_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    int pivo = v[r], j = l;
    dados->movimentacoes++;
    for (int i = l; i < r; i++) {
        dados->comparacoes++;
        if (v[i] <= pivo) {
            Troca(&v[j], &v[i]);
            dados->movimentacoes += 3;
            j++;
        }
    }
    v[r] = v[j], v[j] = pivo;
    dados->movimentacoes += 2;
    return j;
}

void ParticionaDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, dados_execucao *dados) {
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
    }
}

int ParticionaAleatorio_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    int i = l + rand() % (r - l + 1);
    Troca(&v[i], &v[r]);
    dados->movimentacoes += 3;
    return Particiona_ColetaDados(l, r, v, dados);
}

void ParticionaAleatorioDuplo_ColetaDados(int l, int r, int *i, int *j, int *v, dados_execucao *dados) {
    int k = l + rand() % (r - l + 1);
    Troca(&v[k], &v[r]);
    dados->movimentacoes += 3;
    ParticionaDuplo_ColetaDados(l, r, i, j, v, dados);
}
