# include "../ordenacao.h"

void Balde(int n, int *v) {
    const int num_buckets = 10;
    int* aux = AlocaVetor(n);
    int menor = ObterMenorElemento(n, v);
    int maior = ObterMaiorElemento(n, v);
    int intervalo = (int) ceil((maior - menor + 1.0) / num_buckets);
    lista_ligada* buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = CriaListaLigada();
    }
    for (int i = 0; i < n; i++) {
        int j = (v[i] - menor) / intervalo;
        InsereEmListaLigada(v[i], buckets[j]);
    }
    int k = 0;
    for (int i = 0; i < num_buckets; i++) {
        CopiaListaLigadaParaVetor(aux, buckets[i]);
        Insercao(buckets[i]->tamanho, aux);
        for (int j = 0; j < buckets[i]->tamanho; j++) {
            v[k++] = aux[j];
        }
    }
    for (int i = 0; i < num_buckets; i++) {
        ApagaListaLigada(buckets[i]);
    }
}

void Balde_ColetaDados(int n, int *v, dados_execucao *dados) {
    const int num_buckets = 10;
    int* aux = AlocaVetor(n);
    int menor = v[0], maior = v[0];
    for (int i = 1; i < n; i++) {
        if (menor > v[i]) {
            menor = v[i];
            dados->movimentacoes++;
        }
        if (maior < v[i]) {
            maior = v[i];
            dados->movimentacoes++;
        }
    }
    int intervalo = (int) ceil((maior - menor + 1.0) / num_buckets);
    lista_ligada* buckets[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = CriaListaLigada();
    }
    for (int i = 0; i < n; i++) {
        int j = (v[i] - menor) / intervalo;
        InsereEmListaLigada(v[i], buckets[j]);
        dados->movimentacoes++;
    }
    int k = 0;
    for (int i = 0; i < num_buckets; i++) {
        CopiaListaLigadaParaVetor(aux, buckets[i]);
        dados->movimentacoes += buckets[i]->tamanho;
        Insercao_ColetaDados(buckets[i]->tamanho, aux, dados);
        for (int j = 0; j < buckets[i]->tamanho; j++) {
            v[k++] = aux[j];
            dados->movimentacoes++;
        }
    }
    for (int i = 0; i < num_buckets; i++) {
        ApagaListaLigada(buckets[i]);
    }
}
