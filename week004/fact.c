#include <stdio.h>
#include <malloc.h>

int main() {
    int n;
    int save;
    scanf("%d", &n);
    if(n<0) return 0;
    else if (n<2) {
        printf("%d",n);
        return 0;
    }
    int *t = calloc(158, sizeof(int));
    int k = 0;
    save = n;
    while (1) {
        t[k] = n % 10;
        n = n - n % 10;
        if (n == 0)
            break;
        n = n / 10;
        k++;
    }
    int max_index = k + 1;

    n = save;
//    printf("index %d v\n", max_index);
//    for (int l = 0; l < 10; l++)
//        printf("%d ", t[l]);
//    printf("\n");

    while (n > 1) {
        n--;
        int i = 0;
        while (i < max_index) {
            t[i] = t[i] * n;
            i++;
        }
        i = 0;
        while (i < max_index) {
            while (t[i] >= 10) {
                t[i] -= 10;
                t[i + 1] += 1;
                if(i+2 > max_index)
                    max_index = i + 2;
            }
            i++;
        }
//        printf("index %d v\n", max_index);
//        for (int l = 0; l < 10; l++)
//            printf("%d ", t[l]);
//        printf("\n");
    }
    for (int i = max_index-1; i >= 0; i--)
        printf("%d", t[i]);
    return 0;
}