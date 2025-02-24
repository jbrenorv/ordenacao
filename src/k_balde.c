# include "../ordenacao.h"

void InsereOrdenado(int valor, noh** cabeca) {
    noh* novo = (noh*) malloc(sizeof(noh));
    novo->valor = valor;
    novo->prox = NULL;
    
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        novo->prox = *cabeca;
        *cabeca = novo;
        return;
    }
    
    noh* atual = *cabeca;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
    }
    
    novo->prox = atual->prox;
    atual->prox = novo;
}

void ApagaLista(noh* cabeca) {
    noh* temp;
    while (cabeca != NULL) {
        temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}

void Balde(int n, int *v) {
    if (n <= 0) return;
    int M = ObterMaiorElemento(n, v);
    noh** baldes = (noh**) malloc(n * sizeof(noh*));
    for (int i = 0; i < n; i++) {
        baldes[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int j = (v[i] * n) / (M + 1);
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

void InsereOrdenado_ColetaDados(int valor, noh** cabeca, dados_execucao* dados) {
    noh* novo = (noh*) malloc(sizeof(noh));
    novo->valor = valor;
    novo->prox = NULL;
    dados->movimentacoes++;
    dados->comparacoes++;
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        novo->prox = *cabeca;
        *cabeca = novo;
        dados->movimentacoes += 2;
        return;
    }
    
    noh* atual = *cabeca;
    while (atual->prox != NULL && atual->prox->valor < valor) {
        atual = atual->prox;
        dados->movimentacoes++;
        dados->comparacoes++;
    }
    
    dados->movimentacoes += 2;
    novo->prox = atual->prox;
    atual->prox = novo;
}

void Balde_ColetaDados(int n, int *v, dados_execucao *dados) {
    if (n <= 0) return;
    int M = ObterMaiorElemento(n, v);
    noh** baldes = (noh**) malloc(n * sizeof(noh*));
    for (int i = 0; i < n; i++) {
        baldes[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int j = (v[i] * n) / (M + 1);
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
