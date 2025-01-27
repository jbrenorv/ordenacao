# include "../ordenacao.h"

void BolhaComFlag(int n, int *v) {
    char trocado;
    for (int i = 0; i < n - 1; i++) {
        trocado = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                Troca(&v[j], &v[j + 1]);
                trocado = 1;
            }
        }
        if (!trocado) return;
    }
}

void BolhaComFlag_ColetaDados(int n, int *v, dados_execucao *dados) {
    char trocado;
    for (int i = 0; i < n - 1; i++) {
        trocado = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                Troca(&v[j], &v[j + 1]);
                dados->movimentacoes += 3;
                trocado = 1;
            }
            dados->comparacoes++;
        }
        if (!trocado) return;
    }
}
