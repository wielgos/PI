#include <stdio.h>
#include <stdlib.h>

int comparison(const void * a, const void * b)
{
    int _a = *(int*)a;
    int _b = *(int*)b;
    if(_a < _b) return -1;
    else if(_a == _b) return 0;
    else return 1;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int *A = calloc(N, sizeof(int));
    int *B = calloc(N, sizeof(int));
    for (int i = 0; i<N; i++){
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), comparison);
    int i = 0;
    int s = 0;
    int j;
    while (i < N-1){
        j = i + 1;
        while (j <= N-1 && A[j] <= A[i] + abs(K)){
            if (A[i] != A[j]){
                B[i] = 1;
                B[j] = 1;
            }
            j++;
        }
        if (B[i+1]==1){
            while (B[i+1]==1){
                i++;
            }
        }
        else
            i++;
    }
    for (int i = 0; i < N; i++)
        s += B[i];
    free(B);
    free(A);
    printf("%d", s);
    return 0;
}
