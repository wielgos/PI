#include <stdio.h>
#include <malloc.h>
#include <math.h>

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
    int N, K;
    scanf("%d %d", &N, &K);
    int *t = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++){
        scanf("%d",&t[i]);
    }
    quicksort(t, 0, N-1);
    int i = N-1;
    for (int j = 0; j< K; j++){
        if (floor(t[i]/2) >= floor(t[i-1]/2))
            t[i] = floor(t[i]/2);
        else
        {
            i--;
            t[i] = floor(t[i]/2);
        }
    }
    int s = 0;
    for (int i = 0; i < N; i++)
        s += t[i];
    printf("%d", s);
    return 0;
}