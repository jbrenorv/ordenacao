# include "../ordenacao.h"

void RadixsortContagem(int n, int *v) {
    int M = ObterMaiorElemento(n, v);
    for (int p = 1; M / p > 0; p *= 10)
        ContagemDigital(p, n, v);
}

void RadixsortBalde(int n, int *v) {
    int M = ObterMaiorElemento(n, v);
    for (int p = 1; M / p > 0; p *= 10)
        BaldeDigital(p, n, v);
}

void ContagemDigital(int p, int n,  int* v) {
    int* count = AlocaVetorLimpo(10);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) count[d(p, v[i])]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        aux[count[d(p, v[i])] - 1] = v[i];
        count[d(p, v[i])]--;
    }
    for (int i = 0; i < n; i++) v[i] = aux[i];
    free(count);
    free(aux);
}

void BaldeDigital(int p, int n, int *v) {
    noh** baldes = (noh**) malloc(10 * sizeof(noh*));
    for (int i = 0; i < 10; i++) baldes[i] = NULL;
    for (int i = n - 1; i >= 0; i--) {
        noh* novo = (noh*) malloc(sizeof(noh));
        novo->valor = v[i];
        novo->prox = baldes[d(p, v[i])];
        baldes[d(p, v[i])] = novo;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        noh* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            atual = atual->prox;
        }
        ApagaLista(baldes[i]);
    }
    free(baldes);
}

int d(int p, int valor) {
    return (valor / p) % 10;
}

void RadixsortContagem_ColetaDados(int n, int *v, dados_execucao *dados) {
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    for (int p = 1; M / p > 0; p *= 10) {
        ContagemDigital_ColetaDados(p, n, v, dados);
        dados->iteracoes++;
    }
}

void RadixsortBalde_ColetaDados(int n, int *v, dados_execucao *dados) {
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    for (int p = 1; M / p > 0; p *= 10) {
        BaldeDigital_ColetaDados(p, n, v, dados);
        dados->iteracoes++;
    }
}

void ContagemDigital_ColetaDados(int p, int n,  int* v, dados_execucao *dados) {
    int* count = AlocaVetorLimpo(10);
    int* aux = AlocaVetor(n);
    for (int i = 0; i < n; i++) {
        count[d(p, v[i])]++;
        dados->iteracoes++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        dados->iteracoes++;
    }
    for (int i = n - 1; i >= 0; i--) {
        aux[count[d(p, v[i])] - 1] = v[i];
        count[d(p, v[i])]--;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    free(count);
    free(aux);
}

void BaldeDigital_ColetaDados(int p, int n, int *v, dados_execucao *dados) {
    noh** baldes = (noh**) malloc(10 * sizeof(noh*));
    for (int i = 0; i < 10; i++) baldes[i] = NULL;
    for (int i = n - 1; i >= 0; i--) {
        noh* novo = (noh*) malloc(sizeof(noh));
        novo->valor = v[i];
        novo->prox = baldes[d(p, v[i])];
        baldes[d(p, v[i])] = novo;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        noh* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            atual = atual->prox;
            dados->movimentacoes++;
            dados->iteracoes++;
        }
        ApagaLista(baldes[i]);
        dados->iteracoes++;
    }
    free(baldes);
}
