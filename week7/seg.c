#include <stdio.h>
#include <malloc.h>
#include <math.h>

int gi(int i, int j, int n){
    return i*n+j;
}

int main() {
    int n,k;
    scanf("%d%d",&n, &k);
    int *t = calloc(n*n, sizeof(int));
    for (int i = 0; i <n; i++){
        for (int j = 0; j<n; j++){
            scanf("%d", &t[gi(i,j,n)]);
        }
    }
    int s = 0;
    int maxs = -99999999;
    for (int i = 0; i <n; i++){
        for (int j = 0; j<n; j++){
            s = 0;
            //kolumny:

            for (int l = 0; l<k; l++){
                int index = (i+l)%n;
                s += t[gi(index,j,n)];

            }
            // wiersz
            if (s > maxs)
                maxs = s;
            s = 0;
            for (int l = 0; l<k; l++){
                int index = (j+l)%n;
                s += t[gi(i,index,n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;
            // przekatne prawo dol

            for (int l = 0; l<k; l++){
                int index1 = (i+l)%n;
                int index2 = (j+l)%n;
                s += t[gi(index1,index2,n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;
            // przekatne lewo dol

            for (int l = 0; l<k; l++){
                int index1 = (abs(i+l))%n;
                int index2 = (abs(j-l))%n;
                s += t[gi(index1,index2,n)];
            }
            if (s > maxs)
                maxs = s;
        }
    }
    printf("%d", maxs);
    return 0;
}