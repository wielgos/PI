#include <stdio.h>
#include <malloc.h>

int main() {
    int N;
    scanf("%d", &N);
    int *t1 = calloc(N*N,sizeof(int));
    int index=0;
    for (int i=0; i<N;i++){
        for (int j=0; j<N; j++){
            scanf("%d", &t1[index]);
            index++;
        }
    }
    int *t2 = calloc(N*N,sizeof(int));
    int i = 0;
    int j = N;
    int max_i = N;
    int max_j = 2*N;
    int k=0;
    while(1){
        while( i< max_i && j< max_j)
        {
            if (t1[i] < t1[j]){
                t2[k] = t1[i];
                i++;
            }
            else{
                t2[k] = t1[j];
                j++;
            }
            k++;
        }
        while (i < max_i){
            t2[k]=t1[i];
            k++;
            i++;
        }
        while (j < max_j){
            t2[k]=t1[j];
            k++;
            j++;
        }
        //przepisz do t1;
        for (i=0; i<max_j;i++)
            t1[i] = t2[i];

        i = 0;
        max_i = max_j;
        j = max_j;
        max_j += N;
        k = 0;
        if (j>(N*N)-1)
            break;
    }


    for (int i=0; i<N*N; i++){
        if (i<=N*N-2 && t1[i] == t1[i+1]) //pomijam duplikaty
            continue;
        printf("%d ", t1[i]);
    }
    free(t1);
    free(t2);
    return 0;
}