#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "inc/sort.h"

int main(int argc, char **argv)
{
    srand(time(NULL));

    int n, t;
    parse_args_or_exit(&n, &t, argc, argv);

    int *original_array = NULL;
    int *array = NULL;

    allocate_array_or_exit(n, false, &array);
    allocate_array_or_exit(n, false, &original_array);
    generate_array(n, t, original_array);

    const int algorithms_count = 13;
    algorithm algorithms[] =
    {
        // Algorithm Name , Max N    , Algorithm implementation
        { "Bubble Sort"   , 50000    , bubble_sort                   },
        { "Cocktail Sort" , 50000    , cocktail_sort                 },
        { "Insertion Sort", 50000    , insertion_sort                },
        { "Selection Sort", 50000    , selection_sort                },
        { "Shell Sort"    , 214748364, shell_sort                    },
        { "Bucket Sort"   , 214748364, bucket_sort                   },
        { "Counting Sort" , 214748364, counting_sort                 },
        { "Radix Sort wBS", 214748364, radix_sort_with_bucket_sort   },
        { "Radix Sort wCS", 214748364, radix_sort_with_counting_sort },
        { "Quick Sort D"  , 214748364, quick_sort_deterministic      },
        { "Quick Sort P"  , 214748364, quick_sort_probabilistic      },
        { "Merge Sort"    , 214748364, merge_sort                    },
        { "Heap Sort"     , 214748364, heap_sort                     },
    };

    FILE *fp;
    if ((fp = fopen("output.csv", "a")) == NULL)
    {
        print_memory_allocation_error_and_exit();
    }

    for (int i = 0; i < algorithms_count; ++i)
    {
        if (n > algorithms[i].max_array_size) continue;

        copy_array(n, 0, 0, original_array, array);

        algorithm_run_info info = run_algorithm(n, array, algorithms[i].alg);

        fprintf(fp, "%s,%i,%i,%lli,%lli,%lf\n",
            algorithms[i].name,
            n, t,
            info.comparisons,
            info.movements,
            info.time_ms
        );
    }

    free(array);
    free(original_array);
    fclose(fp);

    return 0;
}
