#include "../ordenacao.h"

void ImprimeErro_E_FinalizaExecucao(const char *mensagem) {
    printf("Erro: %s\n", mensagem);
    exit(1);
}

char EhNumerico(int n, const char *texto) {
    for (int i = 0; i < n; ++i) {
        if (!isdigit(texto[i])) {
            return 0;
        }
    }
    return 1;
}

void Troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *AlocaVetor(int n) {
    int* v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return v;
}

int *AlocaVetorLimpo(int n) {
    int* v = (int *)calloc(n, sizeof(int));
    if (v == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar alocar vetor");
    }
    return v;
}

int GeraNumeroAleatorioNoIntervalo(int a, int b) {
    return a + rand() % (b - a + 1);
}

int *CriaVetor(int n, tipo_vetor tipo) {
    int *v = AlocaVetor(n);
    for (int i = 0; i < n; ++i) {
        if (tipo == CRESCENTE) {
            v[i] = i;
        } else if (tipo == DECRESCENTE) {
            v[i] = n - i;
        } else {
            v[i] = min(100000000, GeraNumeroAleatorioNoIntervalo(0, 10 * n));
        }
    }
    return v;
}

void CopiaVetor(int n, int *origem, int *destino) {
    for (int i = 0; i < n; ++i) {
        destino[i] = origem[i];
    }
}

void ImprimeVetor(int n, int *v, const char *prefixo) {
    if (prefixo != NULL) {
        printf("%s\n", prefixo);
    }
    for (int i=0; i<n; ++i) {
        printf("%i ", v[i]);
    }
    printf("\n");
}

int min(int a, int b) {
    return (a < b ? a : b);
}

int max(int a, int b) {
    return (a > b ? a : b);
}

int ObterMaiorElemento(int n, int *v) {
    int res = v[0];
    for (int i = 1; i < n; i++)
        res = max(res, v[i]);
    return res;
}

int ObterMaiorElemento_ColetaDados(int n, int *v, dados_execucao* dados) {
    int res = v[0];
    for (int i = 1; i < n; i++) {
        dados->comparacoes++;
        if (res < v[i]) {
            res = v[i];
            dados->movimentacoes++;
        }
        dados->iteracoes++;
    }
    return res;
}

celula* CriaCelula(int valor) {
    celula* cel = (celula*) malloc(sizeof(celula));
    cel->valor = valor;
    cel->prox = NULL;
    return cel;
}

void Verifica_Ordenacao(int n, int* v, algoritmo* a) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            printf("Erro em: %s\n", a->nome);
            ImprimeErro_E_FinalizaExecucao("O vetor nao esta ordenado\n");
        }
    }
}

dados_execucao ObterDadosExecucao(int n, int *v, algoritmo* a) {
    dados_execucao dados = (dados_execucao){ 0LL, 0LL, 0LL, 0.0 };

    // Obtem numero de movimentacoes e comparacoes
    int *v_copia = AlocaVetor(n);
    CopiaVetor(n, v, v_copia);
    a->alg_coleta_dados(n, v_copia, &dados);
    Verifica_Ordenacao(n, v_copia, a);
    free(v_copia);
    
    // Obter tempo de execucao
    tempo inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    a->alg(n, v);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    dados.tempo_ms = (fim.tv_sec - inicio.tv_sec) * 1000.0 + (fim.tv_nsec - inicio.tv_nsec) / 1000000.0;
    Verifica_Ordenacao(n, v, a);

    return dados;
}
