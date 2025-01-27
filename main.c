#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "ordenacao.h"

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc < 3) {
        ImprimeErro_E_FinalizaExecucao("Deve-se informar o tamanho e o tipo do vetor");
    }

    char* output_file_name = argv[1];
    int n = atoi(argv[2]);
    int tipo = atoi(argv[3]);
    if (n < 1 || n > 214748364 || tipo < 1 || tipo > 3) {
        ImprimeErro_E_FinalizaExecucao("Parametros invalidos");
    }

    int *original = CriaVetor(n, tipo);
    int *v = AlocaVetor(n);

    const int algorithms_count = 13;
    algoritmo algoritmos[] =
    {
        // Nome           , N max    , Alg.         , Alg. coleta dados
        { "Bolha"         , 50000    , Bolha       , Bolha_ColetaDados        },
        { "Bolha Com Flag", 50000    , BolhaComFlag, BolhaComFlag_ColetaDados },
        { "Coquetel"      , 50000    , Coquetel    , Coquetel_ColetaDados     },
        { "Seleção"       , 50000    , Selecao     , Selecao_ColetaDados      },
        { "Inserção"      , 50000    , Insercao    , Insercao_ColetaDados     },
        { "Shell Sort"    , 214748364, ShellSort   , ShellSort_ColetaDados    },
        { "Merge Sort"    , 214748364, MergeSort   , MergeSort_ColetaDados    },
        { "Quick Sort D"  , 214748364, QuickSortD  , QuickSortD_ColetaDados   },
        { "Quick Sort P"  , 214748364, QuickSortP  , QuickSortP_ColetaDados   },
        { "Heap Sort"     , 214748364, HeapSort    , HeapSort_ColetaDados     },
        { "Contagem"      , 214748364, Contagem    , Contagem_ColetaDados     },
        { "Balde"         , 214748364, Balde       , Balde_ColetaDados        },
        { "Radix Sort"    , 214748364, RadixSort   , RadixSort_ColetaDados    },
    };

    FILE *fp;
    if ((fp = fopen(output_file_name, "a")) == NULL) {
        ImprimeErro_E_FinalizaExecucao("Falha ao tentar abrir arquivo de saida.");
    }

    for (int i = 0; i < algorithms_count; ++i) {
        if (n > algoritmos[i].tamanho_maximo) continue;

        CopiaVetor(n, original, v);

        dados_execucao dados = ObterDadosExecucao(n, v, &algoritmos[i]);

        fprintf(fp, "%s,%i,%i,%lli,%lli,%lf\n",
            algoritmos[i].nome,
            n, tipo,
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
