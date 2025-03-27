# include "../ordenacao.h"

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
        }
    }
}
