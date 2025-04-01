# include "../ordenacao.h"

void Coquetel(int n, int *v) {
    int flag = 1, i = 0, j = n - 1;
    while (flag) {
        flag = 0;
        for (int k = i; k < j; k++)
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
            }
        if (!flag) return;
        flag = 0, j--;
        for (int k = j - 1; k >= i; k--)
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
            }
        i++;
    }
}

void Coquetel_ColetaDados(int n, int *v, dados_execucao *dados) {
    int flag = 1, i = 0, j = n - 1;
    while (flag) {
        flag = 0;
        for (int k = i; k < j; k++) {
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
            dados->iteracoes++;
        }
        if (!flag) return;
        flag = 0, j--;
        for (int k = j - 1; k >= i; k--) {
            if (v[k] > v[k + 1]) {
                Troca(&v[k], &v[k + 1]);
                flag = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
            dados->iteracoes++;
        }
        i++;
        dados->iteracoes++;
    }
}
