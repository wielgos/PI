#include <stdio.h>
#include <malloc.h>

int get_index(int i, int j, int n){
    return i*n+j;
}

int main() {
//    int n, r;
//    int *F = calloc(n*n, sizeof(int));
//    int index = 0;
//    for (int i = 0;i < n; i++){
//        for (int j = 0; j < n; j++){
//            scanf("%d",&F[index]);
//            index++;
//        }
//    }
    int n = 5;
    int r = 1;
    int s;
    int idx, jdx;
    int F[25] = {1,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0};
    int G[25] = {1,0,0,0,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0}; //for output
    for (int i = 0; i<n; i++){
        for (int j = 0;j<n; j++){
            s = 0;
            idx = i-r;
            jdx = j-r;
            while (1){
                while (idx < 0)
                    idx++;
                while (jdx < 0)
                    jdx++;
                if (jdx>n || jdx>j+r)
                    jdx = j-r;
                    idx++;
                if (idx>n || idx>i+r)
                    break;
                jdx++;
                s+=F[get_index(idx,jdx,n)];
            }
            G[get_index(i,j,n)] = s;
        }
    }
    int index = 0;
    for (int i = 0;i < n; i++){
        for (int j = 0; j < n; j++) {
            printf("%d ", G[index]);
            index++;
        }
        printf("\n");
    }

    return 0;
}