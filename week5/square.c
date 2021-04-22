#include <stdio.h>
#include <malloc.h>

int get_index(int i, int j, int n) {
    return i * n + j;
}

//square
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
//    int T[16] = {3, 2, 3, 4,
//                 2, 3, 4, 3,
//                 1, 4, 5, 6,
//                 1, 1, 2, 1};
    int *T = calloc(n * n, sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &T[get_index(i, j, n)]);
    }
    int *I = calloc(n * n - 4 * (n - 1), sizeof(int));
    int *J = calloc(n * n - 4 * (n - 1), sizeof(int));
    int sum;
    int counter = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            for (int l = 1; l < n; l++) { //kolejne kwadraty
                sum = 0;
                int start_i = i - l;
                int start_j = j - l;
                if (i - l >= 0 && i + l <= n - 1 && j - l >= 0 && j + l <= n - 1) {
                    //begin to sum
//                    printf("\nstart: %d %d\n", start_i, start_j);
                    for (int x = start_j; x <= start_j + 2 * l; x++) {
//                        printf("a %d %d\n", start_i, x);
//                        printf("a %d %d\n", start_i+2*l, x);
                        sum += T[get_index(start_i, x, n)];
                        sum += T[get_index(start_i + 2 * l, x, n)];
                    }
                    for (int x = start_i + 1; x < start_i + 2 * l; x++) {
//                        printf("a %d %d\n", x, start_j);
//                        printf("a %d %d\n", x, start_j + 2 * l);
                        sum += T[get_index(x, start_j, n)];
                        sum += T[get_index(x, start_j + 2 * l, n)];
                    }
//                    printf("%d %d sum is %d\n", i, j ,sum);
                    if (sum == k) {
                        //("cor %d %d\n", i, j, counter);
                        I[counter] = i;
                        J[counter] = j;
                        counter++;
                    }
                } else
                    break;
            }

        }
    }
    printf("%d\n", counter);
    for (int i = 0; i < counter; i++)
        printf("%d %d\n", I[i], J[i]);
    free(I);
    free(J);
    free(T);
    return 0;
}