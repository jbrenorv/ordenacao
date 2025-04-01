# include "../ordenacao.h"

void Balde(int n, int *v) {
    int M = ObterMaiorElemento(n, v);
    noh** baldes = (noh**) malloc(n * sizeof(noh*));
    for (int i = 0; i < n; i++)
        baldes[i] = NULL;
    for (int i = n - 1; i >= 0; i--) {
        int j = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[j]);
    }
    for (int i = 0, k = 0; i < n; i++) {
        noh* atual = baldes[i];
        while (atual != NULL) {
            v[k++] = atual->valor;
            atual = atual->prox;
        }
        ApagaLista(baldes[i]);
    }
    free(baldes);
}

void InsereOrdenado(int valor, noh** l) {
    noh* novo = (noh*) malloc(sizeof(noh));
    novo->valor = valor; novo->prox = NULL;
    if (*l == NULL || (*l)->valor >= valor) {
        novo->prox = *l;
        *l = novo;
        return;
    }
    noh* atual = *l;
    while (atual->prox != NULL && atual->prox->valor < valor)
        atual = atual->prox;
    novo->prox = atual->prox; atual->prox = novo;
}

void ApagaLista(noh* cabeca) {
    noh* temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}

void Balde_ColetaDados(int n, int *v, dados_execucao *dados) {
    int M = ObterMaiorElemento_ColetaDados(n, v, dados);
    noh** baldes = (noh**) malloc(n * sizeof(noh*));
    for (int i = 0; i < n; i++) {
        baldes[i] = NULL;
        dados->iteracoes++;
    }
    for (int i = 0; i < n; i++) {
        int j = ((long long)v[i] * n) / (M + 1);
        InsereOrdenado(v[i], &baldes[j]);
        dados->iteracoes++;
    }
    for (int i = 0, k = 0; i < n; i++) {
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

void InsereOrdenado_ColetaDados(int valor, noh** l, dados_execucao* dados) {
    noh* novo = (noh*) malloc(sizeof(noh));
    novo->valor = valor;
    novo->prox = NULL;
    dados->movimentacoes++;
    dados->comparacoes++;
    if (*l == NULL || (*l)->valor >= valor) {
        novo->prox = *l;
        *l = novo;
        dados->movimentacoes += 2;
        return;
    }
    noh* atual = *l;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
        dados->movimentacoes++;
        dados->comparacoes++;
        dados->iteracoes++;
    }
    novo->prox = atual->prox;
    atual->prox = novo;
    dados->movimentacoes += 2;
}
