#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "inc/utils.h"

void parse_args_or_exit(int* n, int *t, int argc, char **argv)
{
    if (argc < 3)
    {
        print_help_and_exit();
    }

    int argv_1_size = strlen(argv[1]);
    int argv_2_size = strlen(argv[2]);
    if (argv_1_size < 1 || argv_1_size > 9 || argv_2_size != 1)
    {
        print_help_and_exit();
    }

    for (int i = 0; i < (argv_1_size + argv_2_size); i++)
    {
        if ((i < argv_1_size && !isdigit(argv[1][i])) || (i >= argv_1_size && !isdigit(argv[2][i - argv_1_size])))
        {
            print_help_and_exit();
        }
    }

    *n = atoi(argv[1]);
    *t = atoi(argv[2]);
    if (*n < 1 || *n > 214748364 || *t < 1 || *t > 3)
    {
        print_help_and_exit();
    }
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void allocate_array_or_exit(int n, bool clear, int **array)
{
    *array = (int *) (clear ? calloc(n, sizeof(int)) : malloc(n * sizeof(int)));
    if (*array == NULL)
    {
        // Failed to allocate memory
        print_memory_allocation_error_and_exit();
    }
}

int generate_number_randomly(int min, int max)
{
    return ((rand() % (max - min + 1)) + min);
}

void generate_array(int n, int t, int *array)
{
    for (int i = 0; i < n; ++i)
    {
        if (t == 1)
        {
            // Ascending
            array[i] = i + 1;
        }
        else if (t == 2)
        {
            // Descending
            array[n - i - 1] = i + 1;
        }
        else
        {
            // Random
            array[i] = generate_number_randomly(0, n * 10);
        }
    }
}

void copy_array(int n, int offset_source, int offset_copy, int *source, int *copy)
{
    for (int i = offset_source, j = offset_copy, counter = 0; counter < n; ++i, ++j, ++counter)
    {
        copy[j] = source[i];
    }
}

void print_help_and_exit()
{
    printf("A partir da raíz do projeto, compile o código usando o seguinte comando:\n");
    printf("\tgcc src/*.c -lm\n\n");
    printf("E então execute:\n");
    printf("\t./a.out <tamanho-da-lista> <tipo-da-lista>\n\n");
    printf("<tamanho-da-lista> deve ser um número inteiro entre 1 e 214748364, indicando o tamanho da lista a ser gerada\n\n");
    printf("<tipo-da-lista> deve ser um dos números a serguir:\n");
    printf("\t1 - lista gerada aleatóriamente\n");
    printf("\t2 - lista em ordem decrescente\n");
    printf("\t3 - lista já em ordem crescente\n");
    exit(1);
}

void print_memory_allocation_error_and_exit()
{
    printf("Falha ao tentar alocar memória para a lista de números\n");
    exit(1);
}

void print_array(int n, int *array, const char *prefix)
{
    if (prefix != NULL)
    {
        printf("%s\n", prefix);
    }

    for (int i=0; i<n; ++i)
    {
        printf("%i ", array[i]);
    }

    printf("\n");
}

void print_array_to_file()
{
    // TODO:
}

algorithm_run_info run_algorithm(int n, int *array, void (* alg)(int, int *, algorithm_run_info *))
{
    algorithm_run_info info = (algorithm_run_info) { 0LL, 0LL, 0.0 };

    clock_t t = clock();
    
    alg(n, array, &info);

    t = clock() - t;
    info.time_ms = ((double)t * 1000.0) / CLOCKS_PER_SEC;

    return info;
}

int min(int a, int b)
{
    return (a < b ? a : b);
}

int max(int a, int b)
{
    return (a > b ? a : b);
}
