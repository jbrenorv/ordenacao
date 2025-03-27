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
    int aux = *a;
    *a = *b;
    *b = aux;
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
    if (a >= b) return a;
    return ((rand() % (b - a + 1)) + a);
}

void GeraVetorCrescente(int n, int *v) {
    for (int i = 0; i < n; ++i) {
        v[i] = i;
    }
}

void GeraVetorDecrescente(int n, int *v) {
    for (int i = n - 1; i >= 0; --i) {
        v[i] = i;
    }
}

void GeraVetorAleatorio(int n, int *v) {
    for (int i = 0; i < n; ++i) {
        v[i] = GeraNumeroAleatorioNoIntervalo(0, n * 10);
    }
}

int *CriaVetor(int n, tipo_vetor tipo) {
    int *v = AlocaVetor(n);
    switch (tipo) {
        case CRESCENTE:
            GeraVetorCrescente(n, v);
            break;
        case DECRESCENTE:
            GeraVetorDecrescente(n, v);
            break;
        default:
            GeraVetorAleatorio(n, v);
            break;
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
    }
    return res;
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
    dados_execucao dados = (dados_execucao){ 0LL, 0LL, 0.0 };

    // Obtem numero de movimentacoes e comparacoes
    printf("Coletando dados do %s\n", a->nome);
    int *vetor_aux = AlocaVetor(n);
    CopiaVetor(n, v, vetor_aux);
    a->alg_coleta_dados(n, vetor_aux, &dados);
    Verifica_Ordenacao(n, vetor_aux, a);
    
    // Obter tempo de execucao
    printf("Obtendo tempo do %s\n\n", a->nome);
    clock_t t = clock();
    a->alg(n, v);
    t = clock() - t;
    dados.tempo_ms = ((double)t * 1000.0) / CLOCKS_PER_SEC;
    Verifica_Ordenacao(n, v, a);

    return dados;
}
