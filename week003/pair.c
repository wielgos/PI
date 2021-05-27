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
    for (int i = 0; i<N; i++){
        scanf("%d", &A[i]);
    }
    qsort(A, N, sizeof(int), comparison);
    int i = 0;
    int pairs = 0;
    int streak;
    while (1){
        if (i == 0 || A[i] > A[i-1] + K){
            streak = 1;
            i++;
            while (i < N && A[i] == A[i-1]){
                streak++;
                i++;
            }//seria

            if (i==N)
                break;
            if (A[i] <= A[i-1] + K)
                pairs += streak; //add series
        }
        else
        {
            pairs++;
            i++;
            while (i < N && A[i] == A[i-1]){
                pairs++;
                i++;
            }
            if (i==N)
                break;
        }
    }
    free(A);
    printf("%d", pairs);
    return 0;
}