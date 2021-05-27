#include <stdio.h>

int f(int tab[][2], int input[], int i) {
    int a;
    int b;
    if (tab[i][0] < 0)
        a = input[-tab[i][0] - 1];
    else
        a = f(tab, input, tab[i][0] - 1);
    if (tab[i][1] < 0)
        b = input[-tab[i][1] - 1];
    else
        b = f(tab, input, tab[i][1] - 1);
    return a ^ b;
}

void append_bin(int tab[], int size) {
    int i = size - 1;
    while (i >= 0) {
        if (tab[i] == 0) {
            tab[i] = 1;
            return;
        } else
            tab[i] = 0;
        i--;
    }
}

int check_end(int a[], int b[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, m, endgate;
    scanf("%d %d %d", &n, &m, &endgate);
//  printf("%d %d %d", &n, &m, &endgate);
    int tab[m][2];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &tab[i][0], &tab[i][1]);
    }
    char b1[n + 1], b2[n + 1];
    scanf("%s", b1);
    scanf("%s", b2);
//    printf("%s", b1);
//    printf("%s", b2);
    int counter = 0;
    int k[n], l[n];
    for (int i = n; i >= 0; i--) {
        //1st
        if (b1[i] == 49)
            k[i] = 1;
        else
            k[i] = 0;
        //2nd
        if (b2[i] == 49)
            l[i] = 1;
        else
            l[i] = 0;
    }
//        printf("%d", check_end(k,l,n));
    while (check_end(k, l, n) == 0) {
        //main loop
//        printf("%d", check_end(k,l,n));
        counter += f(tab, k, endgate - 1);
        append_bin(k, n);
    }
//    printf("%d", counter);
    counter += f(tab, k, endgate - 1);
    printf("%d", counter);
    return 0;
}