void print_array(int *, int);
void swap(int *, int *);

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void print_array(int *array, int len) {
    int i;
    for (i=0; i < len; i++)
        printf("%4d", array[i]);
   printf("\n"); 
}
