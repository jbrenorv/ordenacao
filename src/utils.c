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
    if (parametros.tamanho < 1 ||
        parametros.tamanho > MAX_TAM ||
        parametros.tipo < CRE ||
        parametros.tipo > M3K ||
        (parametros.tipo == M3K && parametros.tamanho % 4 != 0)
    ) {
        FinalizaExecucao("Tamanho ou tipo de vetor invalido");
    }

    parametros.arquivo_saida = argv[1];
    parametros.execucao = atoi(argv[4]);
    
    return parametros;
}

void FinalizaExecucao(const char *mensagem) {
    printf("Erro: %s\n", mensagem);
    exit(1);
}

int *AlocaVetor(int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return vetor;
}

int *AlocaVetorLimpo(int tamanho) {
    int *vetor = (int *)calloc(tamanho, sizeof(int));
    if (vetor == NULL) {
        FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return vetor;
}

int GeraNumeroAleatorioNoIntervalo(int a, int b) {
    return a + rand() % (b - a + 1);
}

int *CriaVetor(int tamanho, VTipo tipo) {
    int *vetor = AlocaVetor(tamanho);
    int k = tamanho / 2;
    for (int i = 0; i < tamanho; ++i) {
        if (tipo == CRE)            vetor[i] = i;
        if (tipo == DEC)            vetor[i] = tamanho - i;
        if (tipo == ALE)            vetor[i] = GeraNumeroAleatorioNoIntervalo(MIN_EL, MAX_EL);
        if (tipo == M3K) {
            if (i < k)
                if (i % 2 == 0)     vetor[i] = i + 1;
                else                vetor[i] = k + i;
            else                    vetor[i] = 2 * (i - k + 1);
        }
    }
    return vetor;
}

void CopiaVetor(int tamanho, int *origem, int *destino) {
    for (int i = 0; i < tamanho; ++i)
        destino[i] = origem[i];
}

int Min(int a, int b) {
    return (a < b ? a : b);
}

int Max(int a, int b) {
    return (a > b ? a : b);
}

int ObterMaiorElemento(int tamanho, int *vetor) {
    int res = vetor[0];
    for (int i = 1; i < tamanho; i++)
        res = Max(res, vetor[i]);
    return res;
}

int ObterMaiorElemento_CD(int tamanho, int *vetor, Dados *dados) {
    int res = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        dados->comparacoes++;
        if (res < vetor[i]) {
            res = vetor[i];
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

void Verifica_Ordenacao(int tamanho, int *vetor, Algoritmo *algoritmo) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            printf("Erro em: %s\n", algoritmo->nome);
            FinalizaExecucao("O vetor nao esta ordenado\n");
        }
    }
}

Dados ObterDados(int tamanho, int *vetor, Algoritmo *algoritmo) {
    Dados dados = (Dados){ 0LL, 0LL, 0.0 };

    int *vetor_copia = AlocaVetor(tamanho);
    CopiaVetor(tamanho, vetor, vetor_copia);
    algoritmo->alg_coletor(tamanho, vetor_copia, &dados);
    Verifica_Ordenacao(tamanho, vetor_copia, algoritmo);
    free(vetor_copia);

    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    algoritmo->alg(tamanho, vetor);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    dados.tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1000000000.0;
    Verifica_Ordenacao(tamanho, vetor, algoritmo);

    return dados;
}
