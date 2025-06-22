#include "ordenacao.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    Parametros parametros = ResolveParametros(argc, argv);
    int *vetor_original = CriaVetor(parametros.tamanho, parametros.tipo);
    int *vetor = AlocaVetor(parametros.tamanho);

    Algoritmo algoritmos[] =
    {
        // Nome          , N max    , Alg.      , Alg. coletor
        { "Bolha"        , 100000   , Bolha     , Bolha_CD      },
        { "Bolha c/ F."  , 100000   , BolhaFlag , BolhaFlag_CD  },
        { "Coquetel"     , 100000   , Coquetel  , Coquetel_CD   },
        { "Selecao"      , 100000   , Selecao   , Selecao_CD    },
        { "Insercao"     , 100000   , Insercao  , Insercao_CD   },
        { "Shellsort"    , 100000000, Shellsort , Shellsort_CD  },
        { "Mergesort"    , 100000000, Mergesort , Mergesort_CD  },
        { "Quicksort"    , 100000000, Quicksort , Quicksort_CD  },
        { "Heapsort"     , 100000000, Heapsort  , Heapsort_CD   },
        { "Contagem"     , 100000000, Contagem  , Contagem_CD   },
        { "Balde"        , 100000000, Balde     , Balde_CD      },
        { "Radixsort C." , 100000000, RadixsortC, RadixsortC_CD },
        { "Radixsort B." , 100000000, RadixsortB, RadixsortB_CD },
    };
    int num_algoritmos = sizeof(algoritmos) / sizeof(Algoritmo);
    
    FILE *arquivo_saida;
    if ((arquivo_saida = fopen(parametros.arquivo_saida, "a")) == NULL) {
        FinalizaExecucao("Falha ao tentar abrir arquivo de saida.");
    }

    for (int i = 0; i < num_algoritmos; ++i) {
        if (parametros.tamanho > algoritmos[i].tamanho_maximo) continue;

        CopiaVetor(parametros.tamanho, vetor_original, vetor);

        Dados dados = ObterDados(parametros.tamanho, vetor, &algoritmos[i]);

        fprintf(arquivo_saida, "%s,%i,%i,%i,%lli,%lli,%lf\n",
            algoritmos[i].nome,
            parametros.tamanho,
            parametros.tipo,
            parametros.execucao,
            dados.comparacoes,
            dados.movimentacoes,
            dados.tempo_ms
        );
    }

    free(vetor_original);
    free(vetor);
    fclose(arquivo_saida);

    return 0;
}
