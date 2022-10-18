#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "sort.h"

int particao(int v[], int esq, int dir) {
    int i, fim;
    fim = esq;
    for (i = esq + 1; i <= dir; i++)
        if (v[i] < v[esq]) {
            fim = fim + 1;
            swap(v, fim, i);
        }
    swap(v, esq, fim);
    return fim;
}

void quicksort_aux(int v[], int esq, int dir) {
    if (esq >= dir)
        return;

    int i = particao(v, esq, dir);
    quicksort_aux(v, esq, i - 1);
    quicksort_aux(v, i + 1, dir);
}

void swap(int v[], int a, int b) {
    int c = v[a];
    v[a] = v[b];
    v[b] = c;
}

void benchmark_sort(int v[], int len, sort_fn sort, char* name) {
    clock_t start = clock();
    
    sort(v, len);

    clock_t end = clock();
    clock_t time_elapsed = end - start;

    printf("%s\t%f\n", name, (float) time_elapsed / CLOCKS_PER_SEC);
}

void bubblesort(int v[], int len) {
    bool sorted = false;
    int end = len;

    do {
        sorted = true;
        for (int i = 0; i < len - 1; i++) {
            if (v[i] > v[i + 1]) {
                swap(v, i, i + 1);
                sorted = false;
            }
        }   
    } while (!sorted);
}

void selection_sort(int v[], int len) {
    for (int left = 0; left < len - 1; left++) {
    int smallest = left;

    for (int right = left + 1; right < len; right++) {
      if (v[right] < v[smallest]) {
        smallest = right;
      }
    }

    swap(v, left, smallest);
  }
}

void insertion_sort(int v[], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j > 0; j--) {
            if (v[j - 1] > v[j])
                swap(v, j - 1, j);
        }
    }
}

void quicksort(int v[], int len) {
    quicksort_aux(v, 0, len);
}

void intercala(int v[], int e, int m, int d) {
    int *r; // vetor auxiliar para armazenar a mistura
    int i, j, k;
    r = (int *)malloc(((d + 1) - e) * sizeof(int));
    i = e;
    j = m + 1;
    k = 0;
    while ((i <= m) && (j <= d)) {    // intercala enquanto nenhuma das partes do vetor
        if (v[i] <= v[j]) { // foi consumida totalmente
        r[k] = v[i];
        i++;
    } else {
        r[k] = v[j];
        j++;
    }
    k++;
    }
    while (i <= m) {
        r[k] = v[i];
        i++;
        k++;
    } // termina de intercalar se sobrou à esquerda
    while (j <= d) {
        r[k] = v[j];
        j++;
        k++;
    } // termina de intercalar se sobrou à direita
    // Cópia do vetor auxiliar (contendo os dados ordenados) sobre o vetor
    // original
    j = 0;
    for (i = e; i <= d; i++) {
        v[i] = r[j];
        j++;
    }
    free(r);
}

void mergesort_aux(int v[], int e, int d) {
    int m;

    if (e < d) {
        m = (e + d) / 2;
        mergesort_aux(v, e, m);
        mergesort_aux(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

void merge_sort(int v[], int len) {
    mergesort_aux(v, 0, len);
}
