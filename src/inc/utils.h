#ifndef __UTILS_H__
#define __UTILS_H__

#define true (char)1
#define false (char)0

typedef char bool;

typedef struct __algorithm_run_info
{
    long long comparisons;
    long long movements;
    double time_ms;
} algorithm_run_info;

typedef struct __algorithm
{
    char *name;
    int max_array_size;
    void (* alg)(int, int *, algorithm_run_info *);
} algorithm;

void parse_args_or_exit(int* n, int *t, int argc, char **argv);

void swap(int* a, int * b);

void allocate_array_or_exit(int n, bool clear, int **array);

int generate_number_randomly(int min, int max);

void generate_array(int n, int t, int *array);

void copy_array(int n, int offset_source, int offset_copy, int *source, int *copy);

void print_help_and_exit();

void print_memory_allocation_error_and_exit();

void print_array(int n, int *array, const char *prefix);

void print_array_to_file();

algorithm_run_info run_algorithm(int n, int *array, void (* alg)(int, int *, algorithm_run_info *));

int min(int a, int b);

int max(int a, int b);

#endif
