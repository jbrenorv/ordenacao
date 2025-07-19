#include "utils.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

Parametros ResolveParametros(int argc, char **argv) {
    if (argc < 5) {
        FinalizaExecucao("Informe todos os parametros necessarios");
    }

    Parametros parametros;
    parametros.tamanho = atoi(argv[2]);
    parametros.tipo = atoi(argv[3]);
    parametros.arquivo_saida = argv[1];
    parametros.execucao = atoi(argv[4]);

    if (parametros.tamanho < 1 || parametros.tamanho > MAX_TAM)
        FinalizaExecucao("Tamanho invalido");

    if (parametros.tipo < CRE || parametros.tipo > M3K)
        FinalizaExecucao("Tipo invalido");

    if (parametros.tipo == M3K && parametros.tamanho % 4 != 0)
        FinalizaExecucao("Para usar o tipo M3K (3), o tamanho precisa ser multiplo de 4");

    return parametros;
}

void FinalizaExecucao(const char *mensagem) {
    printf("Erro: %s\n", mensagem);
    exit(1);
}

int *AlocaVetor(int n) {
    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return v;
}

int *AlocaVetorLimpo(int n) {
    int *v = (int *)calloc(n, sizeof(int));
    if (v == NULL) {
        FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return v;
}

int GeraNumeroAleatorioNoIntervalo(int a, int b) {
    return a + rand() % (b - a + 1);
}

int *CriaVetor(int n, VTipo tipo) {
    int *v = AlocaVetor(n);
    int k = n / 2;
    for (int i = 0; i < n; ++i) {
        if (tipo == CRE)        v[i] = i;
        if (tipo == DEC)        v[i] = n - i;
        if (tipo == ALE)        v[i] = GeraNumeroAleatorioNoIntervalo(MIN_EL, MAX_EL);
        if (tipo == M3K) {
            if (i < k)
                if (i % 2 == 0) v[i] = i + 1;
                else            v[i] = k + i;
            else                v[i] = 2 * (i - k + 1);
        }
    }
    return v;
}

void CopiaVetor(int n, int *origem, int *destino) {
    for (int i = 0; i < n; ++i)
        destino[i] = origem[i];
}

int Min(int a, int b) {
    return (a < b ? a : b);
}

int Max(int a, int b) {
    return (a > b ? a : b);
}

int MaxEl(int n, int *v) {
    int res = v[0];
    for (int i = 1; i < n; i++)
        res = Max(res, v[i]);
    return res;
}

int MaxEl_CD(int n, int *v, Dados *dados) {
    int res = v[0];
    for (int i = 1; i < n; i++) {
        dados->comparacoes++;
        if (res < v[i]) {
            res = v[i];
            dados->movimentacoes++;
        }
    }
    return res;
}

Celula *CriaCelula(int valor) {
    Celula *celula = (Celula *) malloc(sizeof(Celula));
    celula->valor = valor;
    celula->prox = NULL;
    return celula;
}

void Verifica_Ordenacao(int n, int *v, AlgInfo *alg_info) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            printf("Erro em: %s\n", alg_info->nome);
            FinalizaExecucao("O v nao esta ordenado\n");
        }
    }
}

Dados ObterDados(int n, int *v, AlgInfo *alg_info) {
    Dados dados = (Dados){ 0LL, 0LL, 0.0 };

    int *v_copia = AlocaVetor(n);
    CopiaVetor(n, v, v_copia);
    alg_info->impl_coletor(n, v_copia, &dados);
    Verifica_Ordenacao(n, v_copia, alg_info);
    free(v_copia);

    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    alg_info->impl(n, v);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    dados.tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    Verifica_Ordenacao(n, v, alg_info);

    return dados;
}
