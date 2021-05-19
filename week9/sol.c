#include <stdio.h>
#include <malloc.h>
#include <math.h>

int pow2(int k){
    if (k == 0)
        return 1;
    return 2*pow2(k-1);
}


int main() {
    int n;
    int g;
    scanf("%d %d", &n, &g);
    int *t = calloc(n, sizeof(int));
    int max_len = 0;
    int len;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
        len = (int)log2(t[i])+1;
        if (len > max_len)
            max_len = len;
    }
    //printf("len:%d\n",max_len);
    int *gbin = calloc(max_len, sizeof(int)); //liczba g binarnie
    int m = g;
    for (int j = max_len - 1; j >= 0; j--) {
        if (m >= pow2(j)) {
            gbin[j] = 1;
            m -= pow2(j);
        }
    }//liczba g binarnie zbudowana
    int *bins = calloc(n * max_len, sizeof(int));
    for (int i = 0; i < n; i++) {
        m = t[i];
        for (int j = max_len - 1; j >= 0; j--) {
            if (m >= pow2(j)) {
                bins[i * max_len + j] = 1;
                m -= pow2(j);
            }
        }
    }
    //reset the wrong invalid bins
    int fflag = 0;
    for (int i = 0; i < n; i++) {
        fflag = 0;
        for (int j = max_len - 1; j >= 0; j--) {
            //printf("%d %d",bins[i * max_len + j], gbin[j]);
            if (bins[i * max_len + j] == 1 && gbin[j] == 0){
                fflag = 1;
                break;
            }
        }
        if (fflag){
            for (int j = max_len - 1; j >= 0; j--) {
                //printf("flag");
                bins[i * max_len + j] = 0;
            }
        }
    }
    int best_c = n + 1;
    for (int j = 0; j < max_len; j++) {
        //j czyli pozycja gbina
        int c = n + 1;
        if (gbin[j] == 1) {
            c = 0;
            for (int i2 = 0; i2 < n; i2++) {
                if (bins[i2 * max_len + j] == 1)
                    c++;
            }
        }
        //printf("c:%d\n", c);
        if (c < best_c)
            best_c = c;

    }
    printf("%d\n", best_c);
    return 0;

    printf("bins:\n");
    for (int i = 0; i < n; i++) {
        for (int j = max_len - 1; j >= 0; j--) {
            printf("%d", bins[i * max_len + j]);
        }
        printf("\n");
    }
    printf("gbin:\n");
    for (int j = max_len - 1; j >= 0; j--) {
        printf("%d", gbin[j]);
    }
    return 0;
}