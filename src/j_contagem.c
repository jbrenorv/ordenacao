#include "../ordenacao.h"

void Contagem(int n, int *v) {
    int M = ObterMaiorElemento(n, v);
    int* cnt = AlocaVetorLimpo(M + 1);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) cnt[v[i]]++;
    for (int i = 1; i <= M; i++) cnt[i] += cnt[i - 1];
    for (int i = 0; i < n; i++) aux[i] = v[i];
    for (int i = n - 1; i >= 0; i--) {
        v[cnt[aux[i]] - 1] = aux[i];
        cnt[aux[i]]--;
    }
    free(cnt);
    free(aux);
}

void Contagem_ColetaDados(int n, int *v, dados_execucao *dados) {
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    int* cnt = AlocaVetorLimpo(M + 1);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
        dados->iteracoes++;
    }
    for (int i = 1; i <= M; i++) {
        cnt[i] += cnt[i - 1];
        dados->iteracoes++;
    }
    for (int i = 0; i < n; i++) {
        aux[i] = v[i];
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = n - 1; i >= 0; i--) {
        v[cnt[aux[i]] - 1] = aux[i];
        cnt[aux[i]]--;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    free(cnt);
    free(aux);
}
