# include "../ordenacao.h"

void Insercao(int n, int *v) {
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = v[i];
        for (j = i; j > 0 && v[j - 1] > chave; j--)
            v[j] = v[j - 1];
        v[j] = chave;
    }
}

void Insercao_ColetaDados(int n, int *v, dados_execucao *dados) {
    int chave, j;
    for (int i = 1; i < n; i++) {
        chave = v[i];
        for (j = i; j > 0 && v[j - 1] > chave; j--) {
            v[j] = v[j - 1];
            dados->comparacoes++;
            dados->movimentacoes++;
            dados->iteracoes++;
        }
        v[j] = chave;
        if (j > 0) dados->comparacoes++;
        dados->movimentacoes += 2;
        dados->iteracoes++;
    }
}
