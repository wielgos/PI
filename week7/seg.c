#include <stdio.h>
#include <malloc.h>

int gi(int i, int j, int n) {
    return i * n + j;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *t = calloc(n * n, sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &t[gi(i, j, n)]);
        }
    }
    int s = 0;
    int maxs = -99999999;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //kolumny:

            for (int l = 0; l < k; l++) {
                int index = (i + l) % n;
                s += t[gi(index, j, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;

            for (int l = 0; l < k; l++) {
                int index = (i - l) % n;
                if (index < 0)
                    index = n + index;
                s += t[gi(index, j, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;


            // wiersz
            for (int l = 0; l < k; l++) {
                int index = (j + l) % n;
                s += t[gi(i, index, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;

            for (int l = 0; l < k; l++) {
                int index = (j - l) % n;
                if (index < 0)
                    index = n + index;
                s += t[gi(i, index, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;

            // przekatne prawo dol / prawo gora

            for (int l = 0; l < k; l++) {
                int index1 = (i + l) % n;
                int index2 = (j + l) % n;
                s += t[gi(index1, index2, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;

            for (int l = 0; l < k; l++) {
                int index1 = (i - l) % n;
                int index2 = (j + l) % n;
                if (index1 < 0)
                    index1 = n + index1;
                s += t[gi(index1, index2, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;
            // przekatne lewo dol / lewo gora

            for (int l = 0; l < k; l++) {
                int index1 = (i + l) % n;
                int index2 = (j - l) % n;
                if (index2 < 0)
                    index2 = n + index2;
                s += t[gi(index1, index2, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;

            for (int l = 0; l < k; l++) {
                int index1 = (abs(i - l)) % n;
                int index2 = (abs(j - l)) % n;
                if (index1 < 0)
                    index1 = n + index1;
                if (index2 < 0)
                    index2 = n + index2;
                s += t[gi(index1, index2, n)];
            }
            if (s > maxs)
                maxs = s;
            s = 0;
        }
    }
    printf("%d", maxs);
    return 0;
}