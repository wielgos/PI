#include <stdio.h>

int partition(int* t, int p, int r){
    int i = p;
    int pivot = t[p];
    int j = p + 1;
    while (j <= r){
        if(t[j] <= pivot){
            i++;
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
        }
        j++;
    }
    t[p] = t[i];
    t[i] = pivot;
    return i;
}

void quicksort(int* t, int p, int r){
    if (p < r){
        int q = partition(t, p, r);
        quicksort(t, p, q-1);
        quicksort(t, q+1, r);
    }
}

int main() {
    return 0;
}