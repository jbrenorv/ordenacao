# include "../ordenacao.h"

const int ciura[] = {1699086440,755149529,335622013,149165339,66295706,
29464758,13095448,5820199,2586755,1149669,510964,227095,100931,
44858,19937,8861,3938,1750,701,301,132,57,23,10,4,1};

void ShellSort(int n, int *v) {
    int chave, j, gap;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= n) continue;
        gap = ciura[k];
        for (int i = gap; i < n; i++) {
            chave = v[i];
            for (j = i; j >= gap && v[j - gap] > chave; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = chave;
        }
    }
}

void ShellSort_ColetaDados(int n, int *v, dados_execucao *dados) {
    int chave, j, gap;
    for (int k = 0; k < 26; k++) {
        if (ciura[k] >= n) continue;
        gap = ciura[k];
        for (int i = gap; i < n; i++) {
            chave = v[i];
            for (j = i; j >= gap && v[j - gap] > chave; j -= gap) {
                v[j] = v[j - gap];
                dados->movimentacoes++;
                dados->comparacoes++;
            }
            v[j] = chave;
            if (j >= gap) dados->comparacoes++;
            dados->movimentacoes += 2;
        }
    }
}
