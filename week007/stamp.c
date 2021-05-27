#include <stdio.h>
#include <malloc.h>
int gi(int i, int j, int n) {
    return i * n + j;
}

int main() {
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);
    int *t = calloc(n * n, sizeof(int));
    int *p = calloc(k * l, sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &t[gi(i, j, n)]);
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &p[gi(i, j, l)]);
        }
    }
    int s;
    int maxs = -999999999;
    int curr_i;
    int curr_j;
    int flag_end = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s = 0;
            flag_end = 0;
            //printf("---attach at %d %d\n", i, j);
            for (int g = 0; g<k; g++){
//                printf("g: %d k: %d\n", g, k);
                for (int h= 0; h<l; h++){
                    curr_i = i + g;
                    curr_j = j + h;
//                    printf("checkfor: %d %d\n", curr_i, curr_j);
                    if (curr_i > n-1 || curr_j > n-1){
                        //printf("ending at: %d %d\n", curr_i, curr_j);
                        flag_end = 1;
                        break;
                    }
                    if (p[gi(g,h,l)]==1){
                        //printf("add: %d %d\n", curr_i, curr_j);
                        s+= t[gi(curr_i,curr_j,n)];
//                        printf("*adding:%d\n", t[gi(curr_i,curr_j,n)]);
                    }
                }
                if (flag_end)
                    break;
            }
//            printf("flag: %d\n", flag_end);
//            printf("sum: %d\n", s);
            if (flag_end)
                continue;
            if (s > maxs){
                maxs = s;
            }

        }
    }
    printf("%d", maxs);
    return 0;
}