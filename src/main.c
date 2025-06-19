#include "ordenacao.h"

int main(int argc, char **argv) {
    srand(time(NULL));

    parametros params = ResolveParametros(argc, argv);
    int *original = CriaVetor(params.tamanho, params.tipo);
    int *v = AlocaVetor(params.tamanho);

    algoritmo algoritmos[] =
    {
        // Nome          , N max    , Alg.             , Alg. coleta dados
        { "Bolha"        , 100000   , Bolha            , Bolha_ColetaDados             },
        { "Bolha c/ F."  , 100000   , BolhaFlag        , BolhaFlag_ColetaDados         },
        { "Coquetel"     , 100000   , Coquetel         , Coquetel_ColetaDados          },
        { "Selecao"      , 100000   , Selecao          , Selecao_ColetaDados           },
        { "Insercao"     , 100000   , Insercao         , Insercao_ColetaDados          },
        { "Shellsort"    , 100000000, Shellsort        , Shellsort_ColetaDados         },
        { "Mergesort"    , 100000000, Mergesort        , Mergesort_ColetaDados         },
        { "Quicksort"    , 100000000, Quicksort        , Quicksort_ColetaDados         },
        { "Heapsort"     , 100000000, Heapsort         , Heapsort_ColetaDados          },
        { "Contagem"     , 100000000, Contagem         , Contagem_ColetaDados          },
        { "Balde"        , 100000000, Balde            , Balde_ColetaDados             },
        { "Radixsort C." , 100000000, RadixsortContagem, RadixsortContagem_ColetaDados },
        { "Radixsort B." , 100000000, RadixsortBalde   , RadixsortBalde_ColetaDados    },
    };
    int num_algoritmos = sizeof(algoritmos) / sizeof(algoritmo);
    
    FILE *fp;
    if ((fp = fopen(params.arquivo_saida, "a")) == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar abrir arquivo de saida.");
    }

    for (int i = 0; i < num_algoritmos; ++i) {
        if (params.tamanho > algoritmos[i].tamanho_maximo) continue;

        CopiaVetor(params.tamanho, original, v);

        dados_execucao dados = ObterDadosExecucao(params.tamanho, v, &algoritmos[i]);

        fprintf(fp, "%s,%i,%i,%i,%lli,%lli,%lf\n",
            algoritmos[i].nome,
            params.tamanho,
            params.tipo,
            params.execucao,
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
