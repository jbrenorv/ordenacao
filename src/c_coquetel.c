# include "../ordenacao.h"

void Coquetel(int n, int *v) {
    char trocado = 1;
    int inicio = 0;
    int fim = n - 1;
    while (trocado) {
        trocado = 0;
        for (int i = inicio; i < fim; i++) {
            if (v[i] > v[i + 1]) {
                Troca(&v[i], &v[i + 1]);
                trocado = 1;
            }
        }
        if (!trocado) return;
        trocado = 0;
        fim--;
        for (int i = fim - 1; i >= inicio; i--) {
            if (v[i] > v[i + 1]) {
                Troca(&v[i], &v[i + 1]);
                trocado = 1;
            }
        }
        inicio++;
    }
}

void Coquetel_ColetaDados(int n, int *v, dados_execucao *dados) {
    char trocado = 1;
    int inicio = 0;
    int fim = n - 1;
    while (trocado) {
        trocado = 0;
        for (int i = inicio; i < fim; i++) {
            if (v[i] > v[i + 1]) {
                Troca(&v[i], &v[i + 1]);
                dados->movimentacoes += 3;
                trocado = 1;
            }
            dados->comparacoes++;
        }
        if (!trocado) return;
        trocado = 0;
        fim--;
        for (int i = fim - 1; i >= inicio; i--) {
            if (v[i] > v[i + 1]) {
                Troca(&v[i], &v[i + 1]);
                dados->movimentacoes += 3;
                trocado = 1;
            }
            dados->comparacoes++;
        }
        inicio++;
    }
}
