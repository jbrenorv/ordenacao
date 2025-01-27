#include "../ordenacao.h"

lista_ligada* CriaListaLigada() {
    lista_ligada* lista = (lista_ligada *) malloc(sizeof(lista_ligada));
    lista->tamanho = 0;
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

void InsereEmListaLigada(int valor, lista_ligada* lista) {
    celula* c = (celula *) malloc(sizeof(celula));
    c->valor = valor;
    if (lista->tamanho == 0) {
        lista->primeiro = lista->ultimo = c;
    } else {
        lista->ultimo->proximo = c;
        lista->ultimo = lista->ultimo->proximo;
    }
    lista->ultimo->proximo = NULL;
    lista->tamanho++;
}

void CopiaListaLigadaParaVetor(int* v, lista_ligada* lista) {
    int i = 0;
    celula* c = lista->primeiro;
    while (c != NULL) {
        v[i++] = c->valor;
        c = c->proximo;
    }
}

void ApagaCelulasRecursivo(celula* c) {
    if (c == NULL) return;
    ApagaCelulasRecursivo(c->proximo);
    free(c);
}

void ApagaListaLigada(lista_ligada* lista) {
    ApagaCelulasRecursivo(lista->primeiro);
    free(lista);
}
