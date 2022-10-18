#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "sort.h"

int main() {
    size_t vec_size = 10000;

    int* v = malloc(vec_size * sizeof(int));
    printf("vetor com %zu elementos gerado...\n", vec_size);

    benchmark_all_sorts(v, vec_size);

    printf("considerando 50.000 elementos\n");
    vec_size = 50000;
    realloc(v, vec_size * sizeof(int));
    benchmark_all_sorts(v, vec_size);

    printf("considerando 100.000 elementos\n");
    vec_size = 100000;
    realloc(v, vec_size * sizeof(int));
    benchmark_all_sorts(v, vec_size);

    free(v);
    return 0;
}
