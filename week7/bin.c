#include <stdio.h>
#include <malloc.h>


int main() {
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    int *t = calloc(n, sizeof(int));
    int i = 1;
    int flag_im = 0;
    while (i < k) {
        if (t[n - 1] == 0)
            t[n - 1] = 1;
        else {
            t[n - 1] = 0;
            int start = n - 2;
            while (t[start] == 1) {
                t[start] = 0;
                start--;
                if (start < 0) {
                    start++;
                    flag_im = 1;
                    break;
                }
            }
            t[start] = 1;
        }
        int correct = 1;
        for (int l = 0; l < n - 1; l++) {
            if (t[l] == 1 && t[l + 1] == 1)
                correct = 0;
        }

        if (correct) {
            i++;
//            for (int i = 0; i < n; i++)
//                printf("%d", t[i]);
//            printf("\n");
        }
        if (flag_im == 1)
            break;
    }
    if (flag_im) {
        printf("-1");
    } else {
        for (int i = 0; i < n; i++)
            printf("%d", t[i]);
    }
    free(t);
    return 0;
}