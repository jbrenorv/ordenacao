#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "ordenacao.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

    parametros params = ResolveParametros(argc, argv);
    int *original = CriaVetor(params.tamanho_vetor, params.tipo_vetor);
    int *v = AlocaVetor(params.tamanho_vetor);

    algoritmo algoritmos[] =
    {
        // Nome               , N max    , Alg.             , Alg. coleta dados
        { "Bolha"             , 100000   , Bolha            , Bolha_ColetaDados             },
        { "BolhaFlag"         , 100000   , BolhaFlag        , BolhaFlag_ColetaDados         },
        { "Coquetel"          , 100000   , Coquetel         , Coquetel_ColetaDados          },
        { "Selecao"           , 100000   , Selecao          , Selecao_ColetaDados           },
        { "Insercao"          , 100000   , Insercao         , Insercao_ColetaDados          },
        { "Shellsort"         , 100000000, Shellsort        , Shellsort_ColetaDados         },
        { "Mergesort"         , 100000000, Mergesort        , Mergesort_ColetaDados         },
        { "Quicksort"         , 100000000, Quicksort        , Quicksort_ColetaDados         },
        { "Heapsort"          , 100000000, Heapsort         , Heapsort_ColetaDados          },
        { "Contagem"          , 100000000, Contagem         , Contagem_ColetaDados          },
        { "Balde"             , 100000000, Balde            , Balde_ColetaDados             },
        { "Radixsort+Contagem", 100000000, RadixsortContagem, RadixsortContagem_ColetaDados },
        { "Radixsort+Balde"   , 100000000, RadixsortBalde   , RadixsortBalde_ColetaDados    },
    };
    int algorithms_count = sizeof(algoritmos) / sizeof(algoritmo);
    
    FILE *fp;
    if ((fp = fopen(params.nome_arquivo, "a")) == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar abrir arquivo de saida.");
    }

    for (int i = 0; i < algorithms_count; ++i) {
        if (params.tamanho_vetor > algoritmos[i].tamanho_maximo) continue;

        CopiaVetor(params.tamanho_vetor, original, v);

        dados_execucao dados = ObterDadosExecucao(params.tamanho_vetor, v, &algoritmos[i]);

        fprintf(fp, "%s,%i,%i,%i,%lli,%lli,%lli,%lf\n",
            algoritmos[i].nome,
            params.tamanho_vetor,
            params.tipo_vetor,
            params.execucao,
            dados.comparacoes,
            dados.movimentacoes,
            dados.iteracoes,
            dados.tempo_ms
        );
    }

    free(original);
    free(v);
    fclose(fp);

    return 0;
}
