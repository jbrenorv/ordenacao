# include "../ordenacao.h"

int const ciura[] = { 1699086440, 755149529, 335622013, 149165339, 66295706, 29464758, 
    13095448, 5820199, 2586755, 1149669, 510964, 227095, 100931, 44858, 
    19937, 8861, 3938, 1750, 701, 301, 132, 57, 23, 10, 4, 1 };

void Shellsort(int n, int *v) {
    int chave, j, h;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= n) continue;
        h = ciura[k];
        for (int i = h; i < n; i++) {
            chave = v[i];
            for (j = i; j >= h && v[j - h] > chave; j -= h)
                v[j] = v[j - h];
            v[j] = chave;
        }
    }
}

void Shellsort_ColetaDados(int n, int *v, dados_execucao *dados) {
    int chave, j, h;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= n) continue;
        h = ciura[k];
        for (int i = h; i < n; i++) {
            chave = v[i];
            for (j = i; j >= h && v[j - h] > chave; j -= h) {
                v[j] = v[j - h];
                dados->movimentacoes++;
                dados->comparacoes++;
                dados->iteracoes++;
            }
            v[j] = chave;
            if (j >= h) dados->comparacoes++;
            dados->movimentacoes += 2;
            dados->iteracoes++;
        }
        dados->iteracoes++;
    }
}
