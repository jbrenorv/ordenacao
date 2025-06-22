#include "ordenacao.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    Parametros parametros = ResolveParametros(argc, argv);
    int *original = CriaVetor(parametros.tamanho, parametros.tipo);
    int *v = AlocaVetor(parametros.tamanho);

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
    
    FILE *fp;
    if ((fp = fopen(parametros.arquivo_saida, "a")) == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar abrir arquivo de saida.");
    }

    for (int i = 0; i < num_algoritmos; ++i) {
        if (parametros.tamanho > algoritmos[i].tamanho_maximo) continue;

        CopiaVetor(parametros.tamanho, original, v);

        Dados dados = ObterDados(parametros.tamanho, v, &algoritmos[i]);

        fprintf(fp, "%s,%i,%i,%i,%lli,%lli,%lf\n",
            algoritmos[i].nome,
            parametros.tamanho,
            parametros.tipo,
            parametros.execucao,
            dados.comparacoes,
            dados.movimentacoes,
            dados.tempo_ms
        );
    }

    free(original);
    free(v);
    fclose(fp);

    return 0;
}
