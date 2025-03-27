# include "../ordenacao.h"

void Selecao(int n, int *v) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++)
            if (v[j] > v[k])
                j = k;
        Troca(&v[i], &v[j]);
    }
}

void Selecao_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int i = 0; i < n - 1; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (v[j] > v[k])
                j = k;
            dados->comparacoes++;
        }
        Troca(&v[i], &v[j]);
        dados->movimentacoes += 3;
    }
}
