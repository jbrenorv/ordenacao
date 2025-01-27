#include "../ordenacao.h"

void Contagem(int n, int *v) {
    int M = ObterMaiorElemento(n, v);
    int* count = AlocaVetorLimpo(M + 1);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) count[v[i]]++;
    for (int i = 1; i <= M; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        aux[count[v[i]] - 1] = v[i];
        count[v[i]]--;
    }
    for (int i = 0; i < n; i++) v[i] = aux[i];
    free(count);
    free(aux);
}

void Contagem_ColetaDados(int n, int *v, dados_execucao *dados) {
    int M = v[0];
    for (int i = 1; i < n; i++) {
        if (M < v[i]) {
            M = v[i];
            dados->movimentacoes++;
        }
    }
    int* count = AlocaVetorLimpo(M + 1);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) count[v[i]]++;
    for (int i = 1; i <= M; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        aux[count[v[i]] - 1] = v[i];
        count[v[i]]--;
        dados->movimentacoes++;
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
        dados->movimentacoes++;
    }
    free(count);
    free(aux);
}
