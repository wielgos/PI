#include <stdio.h>
#include <malloc.h>

int get_index(int i, int j, int n) {
    return i * n + j;
}

int main() {
    int n;
    scanf("%d", &n);
    int *T = calloc(n * n, sizeof(int));
//    int T[25] = {0, 1, 0, 1, 0,
//                 0, 0, 0, 0, 0,
//                 0, 0, 0, 0, 1,
//                 1, 0, 0, 0, 0,
//                 0, 1, 0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &T[get_index(i, j, n)]);
    }
    int maxP = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { //iteracja po calej tablicy
            if (T[get_index(i, j, n)] == 1) //jezeli spotykam jedynkę, ide dalej
                continue;
            if (maxP == 0) //jezeli wczesniej nie bylo ustalonego maxP
                maxP = 1;
            int k = i; //poczatki schodzenia w dol
            int l = j; //poczatki schodzenia w prawo

            int counter = 1; //policzone dotychczas pole

            //najpierw ide w prawo i sprawdzam max granice
            int borderD; //RIGHT BORDER
            int borderS; //DOWN BORDER
            while (l <= n - 1 && T[get_index(i, l, n)] != 1) {
                counter++;
                l++;
            }
            borderD = l;

            if (maxP < counter)
                maxP = counter;
            counter = 1;

            while (k <= n - 1 && T[get_index(k, j, n)] != 1) {
                counter++;
                k++;
            }

            if (maxP < counter)
                maxP = counter;
            counter = 1;

            borderS = k;
            l = j; //reset the value
            k = i; //reset the value
            //got initial borders
            //printf("bS: %d bD: %d maxP: %d\n", borderS, borderD, maxP);
            for (int i2 = k + 1; i2 < borderS; i2++) { //po kazdych mozliwych dlugosciach prostokata (po lewej)
                for (int j2 = l + 1; j2 < borderD; j2++) { //po kazdych mozliwych dlugosciach prostokata (z gory)
                    //printf("sum_to:i%d, j%d\n", i2, j2);
                    counter = 0;
                    int found_1 = 0;
                    // rozpoczynam sumowanie :)
                    for (int ih = k; ih <= i2; ih++) {
                        for (int jh = l; jh <= j2; jh++) {
                            if (T[get_index(ih, jh, n)] != 1) {
                                counter += 1;
                            } else {
                                counter = -1;
                                found_1 = 1;
                                break;
                            }
                        }
                        if (found_1 == 1) {
                            break;
                        }
                    }
                    if (counter > maxP) {
                        maxP = counter;
                    }
                }
            }
            if (maxP == n * n) {
                printf("%d", maxP);
                free(T);
                return 0;
            }

        }

    }
    printf("%d", maxP);
    free(T);
    return 0;
}