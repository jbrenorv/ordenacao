#include "utils.h"

Parametros ResolveParametros(int argc, char **argv) {
    if (argc < 5) {
        FinalizaExecucao("Informe todos os parametros necessarios");
    }

    Parametros parametros;

    parametros.tamanho = atoi(argv[2]);
    parametros.tipo = atoi(argv[3]);
    if (parametros.tamanho < 1 || parametros.tamanho > 214748364 || parametros.tipo < 1 || parametros.tipo > 3) {
        FinalizaExecucao("Tamanho ou tipo de vetor invalido");
    }

    parametros.arquivo_saida = argv[1];
    parametros.execucao = atoi(argv[4]);
    
    return parametros;
}

void FinalizaExecucao(const char *mensagem) {
    printf("Erro: %s\tamanho", mensagem);
    exit(1);
}

char EhNumerico(int tamanho, const char *texto) {
    for (int i = 0; i < tamanho; ++i)
        if (!isdigit(texto[i]))
            return 0;
    return 1;
}

void Troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

int *CriaVetor(int tamanho, Tipo tipo) {
    int *vetor = AlocaVetor(tamanho);
    for (int i = 0; i < tamanho; ++i)
        if (tipo == CRESCENTE)
            vetor[i] = i;
        else if (tipo == DECRESCENTE)
            vetor[i] = tamanho - i;
        else
            vetor[i] = GeraNumeroAleatorioNoIntervalo(0, Min(100000000, 10 * tamanho)) ;
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

Dados ObterDados(int tamanho, int *vetor, Algoritmo *algoritmo) {
    Dados dados = (Dados){ 0LL, 0LL, 0.0 };

    int *vetor_copia = AlocaVetor(tamanho);
    CopiaVetor(tamanho, vetor, vetor_copia);
    algoritmo->alg_coletor(tamanho, vetor_copia, &dados);
    free(vetor_copia);

    struct timespec inicio, fim;
    clock_gettime(CLOCK_MONOTONIC, &inicio);
    algoritmo->alg(tamanho, vetor);
    clock_gettime(CLOCK_MONOTONIC, &fim);
    dados.tempo_ms = (fim.tv_sec - inicio.tv_sec) * 1000.0 + (fim.tv_nsec - inicio.tv_nsec) / 1000000.0;

    return dados;
}
