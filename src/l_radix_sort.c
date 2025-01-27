# include "../ordenacao.h"

void ContagemParaRadixSort(int exp, int n,  int* v) {
    int* count = AlocaVetorLimpo(10);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) count[(v[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        aux[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++) v[i] = aux[i];
    free(count);
    free(aux);
}

void RadixSort(int n, int *v) {
    int maior = ObterMaiorElemento(n, v);
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        ContagemParaRadixSort(exp, n, v);
    }
}

void ContagemParaRadixSort_ColetaDados(int exp, int n,  int* v, dados_execucao *dados) {
    int* count = AlocaVetorLimpo(10);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) count[(v[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        aux[count[(v[i] / exp) % 10] - 1] = v[i];
        count[(v[i] / exp) % 10]--;
        dados->movimentacoes++;
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
        dados->movimentacoes++;
    }
    free(count);
    free(aux);
}

void RadixSort_ColetaDados(int n, int *v, dados_execucao *dados) {
    int maior = v[0];
    for (int i = 1; i < n; i++) {
        if (maior < v[i]) {
            maior = v[i];
            dados->movimentacoes++;
        }
    }
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        ContagemParaRadixSort_ColetaDados(exp, n, v, dados);
    }
}
