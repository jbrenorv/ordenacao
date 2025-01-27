# include "../ordenacao.h"

int Particiona(int l, int r, int *v) {
    int pivo = v[r], j = l;
    for (int i = l; i < r; i++) {
        if (v[i] <= pivo) {
            Troca(&v[j], &v[i]);
            j++;
        }
    }
    v[r] = v[j], v[j] = pivo;
    return j;
}

void QuickSortBasicoRecursivoD(int l, int r, int *v) {
    if (l < r) {
        int j = Particiona(l, r, v);
        QuickSortBasicoRecursivoD(l, j - 1, v);
        QuickSortBasicoRecursivoD(j + 1, r, v);
    }
}

void QuickSortBasicoD(int n, int *v) {
    QuickSortBasicoRecursivoD(0, n - 1, v);
}

void QuickSortBasicoRecursivoP(int l, int r, int *v) {
    if (l < r) {
        int pivo_indice = GeraNumeroAleatorioNoIntervalo(l, r);
        Troca(&v[pivo_indice], &v[r]);
        int j = Particiona(l, r, v);
        QuickSortBasicoRecursivoP(l, j - 1, v);
        QuickSortBasicoRecursivoP(j + 1, r, v);
    }
}

void QuickSortBasicoP(int n, int *v) {
    QuickSortBasicoRecursivoP(0, n - 1, v);
}

void QuickSortRecursivoD(int l, int r, int *v) {
    while (l < r) {
        int j = Particiona(l, r, v);
        if (j - l < r - j) {
            QuickSortRecursivoD(l, j - 1, v);
            l = j + 1;
        } else {
            QuickSortRecursivoD(j + 1, r, v);
            r = j - 1;
        }
    }
}

void QuickSortD(int n, int *v) {
    QuickSortRecursivoD(0, n - 1, v);
}

void QuickSortRecursivoP(int l, int r, int *v) {
    while (l < r) {
        int pivo_indice = GeraNumeroAleatorioNoIntervalo(l, r);
        Troca(&v[pivo_indice], &v[r]);
        int j = Particiona(l, r, v);
        if (j - l < r - j) {
            QuickSortRecursivoP(l, j - 1, v);
            l = j + 1;
        } else {
            QuickSortRecursivoP(j + 1, r, v);
            r = j - 1;
        }
    }
}

void QuickSortP(int n, int *v) {
    QuickSortRecursivoP(0, n - 1, v);
}

int Particiona_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    int pivo = v[r], j = l;
    for (int i = l; i < r; i++) {
        if (v[i] <= pivo) {
            Troca(&v[j], &v[i]);
            j++;
        }
    }
    v[r] = v[j], v[j] = pivo;
    return j;
}

void QuickSortBasicoRecursivoD_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    if (l < r) {
        int j = Particiona_ColetaDados(l, r, v, dados);
        QuickSortBasicoRecursivoD_ColetaDados(l, j - 1, v, dados);
        QuickSortBasicoRecursivoD_ColetaDados(j + 1, r, v, dados);
    }
}
void QuickSortBasicoD_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuickSortBasicoRecursivoD_ColetaDados(0, n - 1, v, dados);
}

void QuickSortRecursivoD_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    while (l < r) {
        int j = Particiona_ColetaDados(l, r, v, dados);
        if (j - l < r - j) {
            QuickSortRecursivoD_ColetaDados(l, j - 1, v, dados);
            l = j + 1;
        } else {
            QuickSortRecursivoD_ColetaDados(j + 1, r, v, dados);
            r = j - 1;
        }
    }
}
void QuickSortD_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuickSortRecursivoD_ColetaDados(0, n - 1, v, dados);
}

void QuickSortBasicoRecursivoP_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    if (l < r) {
        int pivo_indice = GeraNumeroAleatorioNoIntervalo(l, r);
        Troca(&v[pivo_indice], &v[r]);
        int j = Particiona_ColetaDados(l, r, v, dados);
        QuickSortBasicoRecursivoP_ColetaDados(l, j - 1, v, dados);
        QuickSortBasicoRecursivoP_ColetaDados(j + 1, r, v, dados);
    }
}

void QuickSortBasicoP_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuickSortBasicoRecursivoP_ColetaDados(0, n - 1, v, dados);
}

void QuickSortRecursivoP_ColetaDados(int l, int r, int *v, dados_execucao *dados) {
    while (l < r) {
        int pivo_indice = GeraNumeroAleatorioNoIntervalo(l, r);
        Troca(&v[pivo_indice], &v[r]);
        int j = Particiona_ColetaDados(l, r, v, dados);
        if (j - l < r - j) {
            QuickSortRecursivoP_ColetaDados(l, j - 1, v, dados);
            l = j + 1;
        } else {
            QuickSortRecursivoP_ColetaDados(j + 1, r, v, dados);
            r = j - 1;
        }
    }
}

void QuickSortP_ColetaDados(int n, int *v, dados_execucao *dados) {
    QuickSortRecursivoP_ColetaDados(0, n - 1, v, dados);
}
