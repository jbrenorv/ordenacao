#include "ordenacao.h"

void Bolha(int tamanho, int *vetor) {
    for (int i = tamanho - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (vetor[j] > vetor[j + 1])
                Troca(&vetor[j], &vetor[j + 1]);
}

void Bolha_CD(int tamanho, int *vetor, Dados *dados) {
    for (int i = tamanho - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                Troca(&vetor[j], &vetor[j + 1]);
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
    }
}

void BolhaFlag(int tamanho, int *vetor) {
    char trocou;
    for (int i = tamanho - 1; i > 0; i--) {
        trocou = 0;
        for (int j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                Troca(&vetor[j], &vetor[j + 1]);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

void BolhaFlag_CD(int tamanho, int *vetor, Dados *dados) {
    char trocou;
    for (int i = tamanho - 1; i > 0; i--) {
        trocou = 0;
        for (int j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                Troca(&vetor[j], &vetor[j + 1]);
                trocou = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
        if (!trocou) break;
    }
}

void Coquetel(int tamanho, int *vetor) {
    int i = 0, j = tamanho - 1;
    char trocou = 1;
    while (trocou) {
        trocou = 0;
        for (int k = i; k < j; k++)
            if (vetor[k] > vetor[k + 1]) {
                Troca(&vetor[k], &vetor[k + 1]);
                trocou = 1;
            }
        if (!trocou) return;
        trocou = 0, j--;
        for (int k = j - 1; k >= i; k--)
            if (vetor[k] > vetor[k + 1]) {
                Troca(&vetor[k], &vetor[k + 1]);
                trocou = 1;
            }
        i++;
    }
}

void Coquetel_CD(int tamanho, int *vetor, Dados *dados) {
    int i = 0, j = tamanho - 1;
    char trocou = 1;
    while (trocou) {
        trocou = 0;
        for (int k = i; k < j; k++) {
            if (vetor[k] > vetor[k + 1]) {
                Troca(&vetor[k], &vetor[k + 1]);
                trocou = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
        if (!trocou) return;
        trocou = 0, j--;
        for (int k = j - 1; k >= i; k--) {
            if (vetor[k] > vetor[k + 1]) {
                Troca(&vetor[k], &vetor[k + 1]);
                trocou = 1;
                dados->movimentacoes += 3;
            }
            dados->comparacoes++;
        }
        i++;
    }
}

void Selecao(int tamanho, int *vetor) {
    for (int i = 0; i < tamanho - 1; i++) {
        int j = i;
        for (int k = i + 1; k < tamanho; k++)
            if (vetor[j] > vetor[k])
                j = k;
        if (j > i) Troca(&vetor[i], &vetor[j]);
    }
}

void Selecao_CD(int tamanho, int *vetor, Dados *dados) {
    for (int i = 0; i < tamanho - 1; i++) {
        int j = i;
        for (int k = i + 1; k < tamanho; k++) {
            if (vetor[j] > vetor[k])
                j = k;
            dados->comparacoes++;
        }
        if (j > i) {
            Troca(&vetor[i], &vetor[j]);
            dados->movimentacoes += 3;
        }
    }
}

void Insercao(int tamanho, int *vetor) {
    int chave, j;
    for (int i = 1; i < tamanho; i++) {
        chave = vetor[i];
        for (j = i; j > 0 && vetor[j - 1] > chave; j--)
            vetor[j] = vetor[j - 1];
        vetor[j] = chave;
    }
}

void Insercao_CD(int tamanho, int *vetor, Dados *dados) {
    int chave, j;
    for (int i = 1; i < tamanho; i++) {
        chave = vetor[i];
        for (j = i; j > 0 && vetor[j - 1] > chave; j--) {
            vetor[j] = vetor[j - 1];
            dados->comparacoes++;
            dados->movimentacoes++;
        }
        vetor[j] = chave;
        if (j > 0) dados->comparacoes++;
        dados->movimentacoes += 2;
    }
}

int const ciura[] = { 1699086440, 755149529, 335622013, 149165339, 66295706, 29464758, 
    13095448, 5820199, 2586755, 1149669, 510964, 227095, 100931, 44858, 
    19937, 8861, 3938, 1750, 701, 301, 132, 57, 23, 10, 4, 1 };

void Shellsort(int tamanho, int *vetor) {
    int chave, j, h;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= tamanho) continue;
        h = ciura[k];
        for (int i = h; i < tamanho; i++) {
            chave = vetor[i];
            for (j = i; j >= h && vetor[j - h] > chave; j -= h)
                vetor[j] = vetor[j - h];
            vetor[j] = chave;
        }
    }
}

void Shellsort_CD(int tamanho, int *vetor, Dados *dados) {
    int chave, j, h;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= tamanho) continue;
        h = ciura[k];
        for (int i = h; i < tamanho; i++) {
            chave = vetor[i];
            for (j = i; j >= h && vetor[j - h] > chave; j -= h) {
                vetor[j] = vetor[j - h];
                dados->movimentacoes++;
                dados->comparacoes++;
            }
            vetor[j] = chave;
            if (j >= h) dados->comparacoes++;
            dados->movimentacoes += 2;
        }
    }
}

void Mergesort(int tamanho, int *vetor) {
    int *vetor_aux = AlocaVetor(tamanho);
    MergesortRec(0, tamanho, vetor, vetor_aux);
    free(vetor_aux);
}

void MergesortRec(int l, int r, int *vetor, int *vetor_aux) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergesortRec(l, m, vetor, vetor_aux);
        MergesortRec(m, r, vetor, vetor_aux);
        Merge(l, m, r, vetor, vetor_aux);
    }
}

void Merge(int l, int m, int r, int *vetor, int *vetor_aux) {
    CopiaVetor(r - l, vetor+l, vetor_aux+l);
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (vetor_aux[i] <= vetor_aux[j]) vetor[k++] = vetor_aux[i++];
        else vetor[k++] = vetor_aux[j++];
    }
    while (i < m) vetor[k++] = vetor_aux[i++];
}

void Mergesort_CD(int tamanho, int *vetor, Dados *dados) {
    int *vetor_aux = AlocaVetor(tamanho);
    MergesortRec_CD(0, tamanho, vetor, vetor_aux, dados);
    free(vetor_aux);
}

void MergesortRec_CD(int l, int r, int *vetor, int *vetor_aux, Dados *dados) {
    if (l < r - 1) {
        int m = (l + r) / 2;
        MergesortRec_CD(l, m, vetor, vetor_aux, dados);
        MergesortRec_CD(m, r, vetor, vetor_aux, dados);
        Merge_CD(l, m, r, vetor, vetor_aux, dados);
    }
}

void Merge_CD(int l, int m, int r, int *vetor, int *vetor_aux, Dados *dados) {
    CopiaVetor(r - l, vetor+l, vetor_aux+l);
    dados->movimentacoes += r - l;
    int i = l, j = m, k = l;
    while (i < m && j < r) {
        if (vetor_aux[i] <= vetor_aux[j]) vetor[k++] = vetor_aux[i++];
        else vetor[k++] = vetor_aux[j++];
        dados->comparacoes++;
        dados->movimentacoes++;
    }
    while (i < m) {
        vetor[k++] = vetor_aux[i++];
        dados->movimentacoes++;
    }
}

void Quicksort(int tamanho, int *vetor) {
    QuicksortRec(0, tamanho - 1, vetor);
}

void QuicksortRec(int l, int r, int *vetor) {
    while (l < r) {
        int i, j;
        ParticionaAleatorioDuplo(l, r, &i, &j, vetor);
        if (i - l < r - j) {
            QuicksortRec(l, i - 1, vetor);
            l = j + 1;
        } else {
            QuicksortRec(j + 1, r, vetor);
            r = i - 1;
        }
    }
}

void ParticionaAleatorioDuplo(int l, int r, int *i, int *j, int *vetor) {
    Troca(&vetor[GeraNumeroAleatorioNoIntervalo(l, r)], &vetor[r]);
    int pivo = vetor[r], k = l;
    *i = l, *j = r;
    while (k <= *j) {
        if (vetor[k] < pivo) Troca(&vetor[(*i)++], &vetor[k++]);
        else if (vetor[k] > pivo) Troca(&vetor[(*j)--], &vetor[k]);
        else k++;
    }
}

void Quicksort_CD(int tamanho, int *vetor, Dados *dados) {
    QuicksortRec_CD(0, tamanho - 1, vetor, dados);
}

void QuicksortRec_CD(int l, int r, int *vetor, Dados *dados) {
    while (l < r) {
        int i, j;
        ParticionaAleatorioDuplo_CD(l, r, &i, &j, vetor, dados);
        if (i - l < r - j) {
            QuicksortRec_CD(l, i - 1, vetor, dados);
            l = j + 1;
        } else {
            QuicksortRec_CD(j + 1, r, vetor, dados);
            r = i - 1;
        }
    }
}

void ParticionaAleatorioDuplo_CD(int l, int r, int *i, int *j, int *vetor, Dados *dados) {
    Troca(&vetor[GeraNumeroAleatorioNoIntervalo(l, r)], &vetor[r]);
    dados->movimentacoes += 3;
    int pivo = vetor[r], k = l;
    dados->movimentacoes++;
    *i = l, *j = r;
    while (k <= *j) {
        if (vetor[k] < pivo) {
            Troca(&vetor[*i], &vetor[k]);
            (*i)++, k++;
            dados->movimentacoes += 3;
            dados->comparacoes += 1;
        } else if (vetor[k] > pivo) {
            Troca(&vetor[*j], &vetor[k]);
            (*j)--;
            dados->movimentacoes += 3;
            dados->comparacoes += 2;
        } else {
            k++;
            dados->comparacoes += 2;
        }
    }
}

void Heapsort(int tamanho, int *vetor) {
    ConstroiHeap(tamanho, vetor);
    for (int i = tamanho - 1; i > 0; i--) {
        Troca(&vetor[0], &vetor[i]);
        Heapify(0, i, vetor);
    }
}

void ConstroiHeap(int tamanho, int *vetor) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        Heapify(i, tamanho, vetor);
}

void Heapify(int i, int tamanho, int *vetor) {
    int j = i, k;
    while (2 * j + 1 < tamanho) {
        k = 2 * j + 1;
        if (k < tamanho - 1 && vetor[k] < vetor[k + 1]) k++;
        if (vetor[j] >= vetor[k]) break;
        else {
            Troca(&vetor[j], &vetor[k]);
            j = k;
        }
    }
}

void Heapsort_CD(int tamanho, int *vetor, Dados *dados) {
    ConstroiHeap_CD(tamanho, vetor,dados);
    for (int i = tamanho - 1; i > 0; i--) {
        Troca(&vetor[0], &vetor[i]);
        Heapify_CD(0, i, vetor, dados);
        dados->movimentacoes += 3;
    }
}

void ConstroiHeap_CD(int tamanho, int *vetor, Dados *dados) {
    for (int i = tamanho / 2 - 1; i >= 0; i--) {
        Heapify_CD(i, tamanho, vetor, dados);
    }
}

void Heapify_CD(int i, int tamanho, int *vetor, Dados *dados) {
    int j = i, k;
    while (2 * j + 1 < tamanho) {
        k = 2 * j + 1;
        if (k < tamanho - 1 && vetor[k] < vetor[k + 1]) k++;
        if (vetor[j] >= vetor[k]) break;
        else {
            Troca(&vetor[j], &vetor[k]);
            dados->movimentacoes += 3;
            j = k;
        }
        dados->comparacoes += 2;
    }
}

void Contagem(int tamanho, int *vetor) {
    int M = ObterMaiorElemento(tamanho, vetor);
    int *contagem = AlocaVetorLimpo(M + 1);
    int *vetor_aux = AlocaVetor(tamanho);
    for (int i = 0; i < tamanho; i++) contagem[vetor[i]]++;
    for (int i = 1; i <= M; i++) contagem[i] += contagem[i - 1];
    for (int i = 0; i < tamanho; i++) vetor_aux[i] = vetor[i];
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor[contagem[vetor_aux[i]] - 1] = vetor_aux[i];
        contagem[vetor_aux[i]]--;
    }
    free(contagem);
    free(vetor_aux);
}

void Contagem_CD(int tamanho, int *vetor, Dados *dados) {
    int M = ObterMaiorElemento_CD(tamanho, vetor, dados);
    int *contagem = AlocaVetorLimpo(M + 1);
    int *vetor_aux = AlocaVetor(tamanho);
    for (int i = 0; i < tamanho; i++) contagem[vetor[i]]++;
    for (int i = 1; i <= M; i++) contagem[i] += contagem[i - 1];
    for (int i = 0; i < tamanho; i++) {
        vetor_aux[i] = vetor[i];
        dados->movimentacoes++;
    }
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor[contagem[vetor_aux[i]] - 1] = vetor_aux[i];
        contagem[vetor_aux[i]]--;
        dados->movimentacoes++;
    }
    free(contagem);
    free(vetor_aux);
}

void Balde(int tamanho, int *vetor) {
    Celula **baldes = (Celula **) calloc(tamanho, sizeof(Celula*));
    int M = ObterMaiorElemento(tamanho, vetor);
    for (int i = tamanho - 1; i >= 0; i--) {
        int index = ((long long)vetor[i] * tamanho) / (M + 1);
        InsereOrdenado(vetor[i], &baldes[index]);
    }
    for (int i = 0, k = 0; i < tamanho; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            vetor[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}

void InsereOrdenado(int valor, Celula **balde) {
    Celula *celula = CriaCelula(valor);
    if (*balde == NULL || (*balde)->valor >= valor) {
        celula->prox = *balde;
        *balde = celula;
    } else {
        Celula *atual = *balde;
        while (atual->prox && atual->prox->valor < valor)
            atual = atual->prox;
        celula->prox = atual->prox;
        atual->prox = celula;
    }
}

void Balde_CD(int tamanho, int *vetor, Dados *dados) {
    Celula **baldes = (Celula**) calloc(tamanho, sizeof(Celula*));
    int M = ObterMaiorElemento_CD(tamanho, vetor, dados);
    for (int i = tamanho - 1; i >= 0; i--) {
        int index = ((long long)vetor[i] * tamanho) / (M + 1);
        InsereOrdenado_CD(vetor[i], &baldes[index], dados);
    }
    for (int i = 0, k = 0; i < tamanho; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            vetor[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
        }
    }
    free(baldes);
}

void InsereOrdenado_CD(int valor, Celula **balde, Dados *dados) {
    Celula *celula = CriaCelula(valor);
    dados->movimentacoes++;
    dados->comparacoes++;
    if (*balde == NULL || (*balde)->valor >= valor) {
        celula->prox = *balde;
        *balde = celula;
        dados->movimentacoes += 2;
    } else {
        Celula *atual = *balde;
        while (atual->prox && atual->prox->valor < valor) {
            atual = atual->prox;
            dados->movimentacoes++;
            dados->comparacoes++;
        }
        celula->prox = atual->prox;
        atual->prox = celula;
        dados->movimentacoes += 2;
    }
}

void RadixsortC(int tamanho, int *vetor) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10)
        ContagemDigital(posicao, tamanho, vetor);
}

void RadixsortB(int tamanho, int *vetor) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10)
        BaldeDigital(posicao, tamanho, vetor);
}

void ContagemDigital(int posicao, int tamanho,  int *vetor) {
    int *contagem = AlocaVetorLimpo(10);
    int *vetor_aux = AlocaVetor(tamanho);
    for (int i = 0; i < tamanho; i++) contagem[ObterDigito(posicao, vetor[i])]++;
    for (int i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor_aux[contagem[ObterDigito(posicao, vetor[i])] - 1] = vetor[i];
        contagem[ObterDigito(posicao, vetor[i])]--;
    }
    for (int i = 0; i < tamanho; i++) vetor[i] = vetor_aux[i];
    free(contagem);
    free(vetor_aux);
}

void BaldeDigital(int posicao, int tamanho, int *vetor) {
    Celula **baldes = (Celula**) calloc(10, sizeof(Celula*));
    for (int i = tamanho - 1; i >= 0; i--) {
        Celula *celula = CriaCelula(vetor[i]);
        celula->prox = baldes[ObterDigito(posicao, vetor[i])];
        baldes[ObterDigito(posicao, vetor[i])] = celula;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            vetor[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(baldes);
}

int ObterDigito(int posicao, int valor) {
    return (valor / posicao) % 10;
}

void RadixsortC_CD(int tamanho, int *vetor, Dados *dados) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10) {
        ContagemDigital_CD(posicao, tamanho, vetor, dados);
    }
}

void RadixsortB_CD(int tamanho, int *vetor, Dados *dados) {
    for (int posicao = 1; posicao < _10e9; posicao *= 10) {
        BaldeDigital_CD(posicao, tamanho, vetor, dados);
    }
}

void ContagemDigital_CD(int posicao, int tamanho,  int *vetor, Dados *dados) {
    int *contagem = AlocaVetorLimpo(10);
    int *vetor_aux = AlocaVetor(tamanho);
    for (int i = 0; i < tamanho; i++) contagem[ObterDigito(posicao, vetor[i])]++;
    for (int i = 1; i < 10; i++) contagem[i] += contagem[i - 1];
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor_aux[contagem[ObterDigito(posicao, vetor[i])] - 1] = vetor[i];
        contagem[ObterDigito(posicao, vetor[i])]--;
        dados->movimentacoes++;
    }
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = vetor_aux[i];
        dados->movimentacoes++;
    }
    free(contagem);
    free(vetor_aux);
}

void BaldeDigital_CD(int posicao, int tamanho, int *vetor, Dados *dados) {
    Celula **baldes = (Celula **) calloc(10, sizeof(Celula *));
    for (int i = tamanho - 1; i >= 0; i--) {
        Celula *celula = CriaCelula(vetor[i]);
        celula->prox = baldes[ObterDigito(posicao, vetor[i])];
        baldes[ObterDigito(posicao, vetor[i])] = celula;
        dados->movimentacoes++;
    }
    for (int i = 0, k = 0; i < 10; i++) {
        Celula *atual = baldes[i];
        while (atual != NULL) {
            vetor[k++] = atual->valor;
            Celula *temp = atual;
            atual = atual->prox;
            free(temp);
            dados->movimentacoes++;
        }
    }
    free(baldes);
}
