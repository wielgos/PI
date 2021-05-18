#include <stdio.h>
#include <malloc.h>
#include <math.h>

//        n-1      n-2      n-3            0
// liczba 2^(n-1), 2^(n-2), 2^(n-3) .... 2^0
//int *to_bin(int n, int m) {
//    int *bin = calloc(n, sizeof(int));
//    int s = n - 1;
//    for (int i = n - 1; i >= 0; i--) {
//        if (m >= pow(2, i)) {
//            bin[i] = 1;
//            m -= pow(2, i);
//        }
//    }
//    return bin;
//}

int to_dec(int *bin, int n) {
    int s = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (bin[i] == 1) {
            s += (int) pow(2, i);
        }
    }
    return s;
}

int main() {
    int n;
    int m;
    int counter = 0;
    scanf("%d %d", &n, &m);
//    int *bin = to_bin(n, m);
//    for(int i = n-1; i>=0; i--){
//        printf("%d", bin[i]);
//    }
    int *bin = calloc(n, sizeof(int));
    int *prevbin = calloc(n, sizeof(int));
    int *results = calloc(1000000, sizeof(int));
    int res_index = 0;
    unsigned long long upper = (int) pow(2, n - 1);
    int decimal;
    while (1) {
        //printf("basic:\n");
//        for (int i = n - 1; i >= 0; i--) {
//            printf("%d", bin[i]);
//        }
        //printf("\n");
//        decimal = to_dec(bin, n);

        //printf("check: %d\n", decimal);
        //printf("dec:%d\n", to_dec(bin, n));
//        if (decimal != 0 && m % decimal == 0 || decimal%m == 0) {
//            int flag = 0;
//            for (int u = 0; u < res_index; u++) {
//                if (decimal == results[u])
//                    flag = 1;
//            }
//            if (flag == 0) {
//                counter++;
//                //printf("found: %d\n", decimal);
//                results[res_index] = decimal;
//                res_index += 1;
//            }
//        }

        for (int i = 0; i < n; i++) {
            prevbin[i] = bin[i];
        }
        decimal = to_dec(bin, n);
        //printf("checkdec:%d\n", decimal);
        if (decimal != 0 && decimal % m != 0 && m % decimal != 0) {
            for (int i = 0; i < n; i++) { //check for flips
                //now we flip the 0 or 1
                //printf("fliptime\n");
                int comeback = bin[i];
                if (bin[i] == 1)
                    bin[i] = 0;
                else
                    bin[i] = 1;
                //printf("binflipped: ");
                for (int k = n - 1; k >= 0; k--) {
                    //printf("%d", bin[k]);
                }
                //printf("\n");
                decimal = to_dec(bin, n);
                //printf("checkflipped: %d\n", decimal);
                if (decimal != 0 && m % decimal == 0 || decimal % m == 0) {
                    int flag = 0;
                    for (int u = 0; u < res_index; u++) {
                        if (decimal == results[u])
                            flag = 1;
                    }
                    if (flag == 0) {
                        counter++;
                        //printf("found: %d\n", decimal);
                        results[res_index] = decimal;
                        res_index += 1;
                    }
                    bin[i] = comeback;
                }
            }

            for (int i = 0; i < n; i++) { //comeback to previous form
                bin[i] = prevbin[i];
            }
        }
        //append binary \/\/\/\/ 1 time
        for (int i = 0; i < 1; i++) {
            if (bin[0] == 1) {
                bin[0] = 0;
                int s = 1;
                while (bin[s] == 1) {
                    bin[s] = 0;
                    s++;

                    if (s == n) {
                        printf("%d", counter);
                        return 0;
                    }

                }
                bin[s] = 1;
            } else
                bin[0] = 1;
        }
    }
    free(bin);
    free(prevbin);
    return 0;
}