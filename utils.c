#include <stdlib.h>

#include "utils.h"
#include "sort.h"

void random_vec(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand();
    }
}

void benchmark_all_sorts(int v[], size_t vec_size) {
    random_vec(v, vec_size);
    benchmark_sort(v, vec_size, bubblesort, "bubblesort");

    random_vec(v, vec_size);
    benchmark_sort(v, vec_size, selection_sort, "selection sort");

    random_vec(v, vec_size);
    benchmark_sort(v, vec_size, insertion_sort, "insertion sort");

    random_vec(v, vec_size);
    benchmark_sort(v, vec_size, quicksort, "quicksort");

    random_vec(v, vec_size);
    benchmark_sort(v, vec_size, merge_sort, "merge sort");
}
