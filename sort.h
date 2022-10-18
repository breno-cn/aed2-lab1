typedef void (*sort_fn) (int[], int);

void swap(int v[], int a, int b);
void benchmark_sort(int v[], int len, sort_fn sort, char *name);

void bubblesort(int v[], int len);
void selection_sort(int v[], int len);
void insertion_sort(int v[], int len);
void quicksort(int v[], int len);
void merge_sort(int v[], int len);
