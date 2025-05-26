# include "../ordenacao.h"

void Balde(int n, int *v) {
    celula** baldes = (celula**) calloc(n, sizeof(celula*));
    int M = ObterMaiorElemento(n, v);
    for (int i = n - 1; i >= 0; i--) {
        int index = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[index]);
    }
    for (int i = 0, k = 0; i < n; i++) {
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

void InsereOrdenado(int valor, celula** balde) {
    celula* cel = CriaCelula(valor);
    if (*balde == NULL || (*balde)->valor >= valor) {
        cel->prox = *balde;
        *balde = cel;
    } else {
        celula* atual = *balde;
        while (atual->prox && atual->prox->valor < valor)
            atual = atual->prox;
        cel->prox = atual->prox;
        atual->prox = cel;
    }
}

void Balde_ColetaDados(int n, int *v, dados_execucao *dados) {
    celula** baldes = (celula**) calloc(n, sizeof(celula*));
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    for (int i = n - 1; i >= 0; i--) {
        int index = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[index]);
        dados->iteracoes++;
    }
    for (int i = 0, k = 0; i < n; i++) {
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

void InsereOrdenado_ColetaDados(int valor, celula** balde, dados_execucao* dados) {
    celula* cel = CriaCelula(valor);
    dados->movimentacoes++;
    dados->comparacoes++;
    if (*balde == NULL || (*balde)->valor >= valor) {
        cel->prox = *balde;
        *balde = cel;
        dados->movimentacoes += 2;
    } else {
        celula* atual = *balde;
        while (atual->prox && atual->prox->valor < valor) {
            atual = atual->prox;
            dados->movimentacoes++;
            dados->comparacoes++;
            dados->iteracoes++;
        }
        cel->prox = atual->prox;
        atual->prox = cel;
        dados->movimentacoes += 2;
    }
}
