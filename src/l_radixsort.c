# include "../ordenacao.h"

#define _10e9 1000000000

void RadixsortContagem(int n, int *v) {
    for (int p = 1; p < _10e9; p *= 10)
        ContagemDigital(p, n, v);
}

void RadixsortBalde(int n, int *v) {
    for (int p = 1; p < _10e9; p *= 10)
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
    celula** baldes = (celula**) calloc(10, sizeof(celula*));
    for (int i = n - 1; i >= 0; i--) {
        celula* cel = CriaCelula(v[i]);
        cel->prox = baldes[d(p, v[i])];
        baldes[d(p, v[i])] = cel;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        celula* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}

int d(int p, int valor) {
    return (valor / p) % 10;
}

void RadixsortContagem_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int p = 1; p < _10e9; p *= 10) {
        ContagemDigital_ColetaDados(p, n, v, dados);
        dados->iteracoes++;
    }
}

void RadixsortBalde_ColetaDados(int n, int *v, dados_execucao *dados) {
    for (int p = 1; p < _10e9; p *= 10) {
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
    celula** baldes = (celula**) calloc(10, sizeof(celula*));
    for (int i = n - 1; i >= 0; i--) {
        celula* cel = CriaCelula(v[i]);
        cel->prox = baldes[d(p, v[i])];
        baldes[d(p, v[i])] = cel;
        dados->movimentacoes++;
        dados->iteracoes++;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        celula* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            celula* temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
    free(baldes);
}
