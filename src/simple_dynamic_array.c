#include "inc/simple_dynamic_array.h"
#include "inc/utils.h"

void create_sda(int capacity, simple_dynamic_array *array)
{
    allocate_array_or_exit(capacity, false, &array->array);
    array->capacity = capacity;
    array->size = 0;
}

void push_back_sda(int value, simple_dynamic_array *array)
{
    array->array[array->size++] = value;
}
