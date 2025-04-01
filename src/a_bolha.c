# include "../ordenacao.h"

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
        }
    }
}
