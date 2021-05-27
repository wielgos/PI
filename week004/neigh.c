#include <stdio.h>
#include <malloc.h>

int get_index(int i, int j, int col_size){
    return i*col_size+j;
}

int main() {
    int n, r;
    scanf("%d %d",&n, &r);
    int *F = calloc(n*n, sizeof(int));
    int index = 0;
    for (int i = 0;i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&F[index]);
            index++;
        }
    }
    int s;
    int idx, jdx;
    int *G = calloc(n*n, sizeof(int));
    for (int i = 0; i<n; i++){
        for (int j = 0;j<n; j++){
            s = 0;
            idx = i-r; //
            jdx = j-r;
            while (1){
                if (idx < 0)
                    idx = 0;
                if (jdx < 0)
                    jdx = 0;
                if (jdx==n || jdx==j+r+1){
                    jdx = j-r;
                    idx++;
                    continue;
                }
                if (idx==n || idx==i+r+1){
                    break;
                }
                s+=F[get_index(idx,jdx,n)];
                jdx++;
            }
            G[get_index(i,j,n)] = s;
        }
    }
    index = 0;
    for (int i = 0;i < n; i++){
        for (int j = 0; j < n; j++) {
            printf("%d ", G[index]);
            index++;
        }
        printf("\n");
    }
    free(F);
    free(G);
    return 0;
}