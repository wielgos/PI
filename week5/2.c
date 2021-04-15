#include <stdio.h>
#include <malloc.h>

int get_index(int i, int j, int n) {
    return i * n + j;
}

//spirala

int main() {
    int n;
    scanf("%d", &n);
    int *T = calloc(n * n, sizeof(int));
    int i = 0, j = 0;
    char dir = 'D';
    for (int k = 1; k <= n * n; k++) {
        //printf("i%d, j%d, k%d\n",i,j,k);
        T[get_index(i, j, n)] = k;
        switch (dir) {
            case 'D':
                j++;
                if (j == n || T[get_index(i, j, n)] != 0) {
                    dir = 'S';
                    j--;
                    i++;
                }
                break;
            case 'S':
                i++;
                if (i == n || T[get_index(i, j, n)] != 0) {
                    dir = 'A';
                    i--;
                    j--;
                }
                break;
            case 'A':
                j--;
                if (i == n || T[get_index(i, j, n)] != 0) {
                    dir = 'W';
                    i--;
                    j++;
                }
                break;
            case 'W':
                i--;
                if (i == n || T[get_index(i, j, n)] != 0) {
                    dir = 'D';
                    i++;
                    j++;
                }
                break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", T[get_index(i, j, n)]);
        }
        printf("\n");
    }
    free(T);
    return 0;
}