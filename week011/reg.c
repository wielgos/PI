#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

#define ull unsigned long long
#define PI 3.1415
#define abs(a) (((a) < 0) ? -(a) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int pow2(int k) {
    if (k == 0)
        return 1;
    return 2 * pow2(k - 1);
}


int bid = 9999999;
char bop[100];


char *rek(int n, char op[], int index, int t) {
    if (index > 98)
        return "NO";
    if (n == t) {
        if (index < bid) {
            bid = index;
            strcpy(bop, op);
        } else if (index == bid) {
            if (strcmp(op, bop) < 0) {
                strcpy(bop, op);
            }
        }
        return "YES";
    }
    if (n == 0 || n > t) {
        return "NO";
    }
    if (n < t) {
        if (n + n <= t) {
            op[index] = '+';
            rek(n + n, op, index + 1, t);
        }
        if (n * n <= t) {
            op[index] = '*';
            rek(n * n, op, index + 1, t);
        }
        return "NO";
    }
    return "NO";
}


int main() {
    int s, t;
    scanf("%d %d", &s, &t);
    char op[100];
    rek(s, op, 0, t);
    memset(op, 0, sizeof(char));
    int prev = bid;
    rek(1, op, 0, t);
    if (bid == 9999999) {
        printf("NO");
        return 0;
    }
    if (bid < prev)
        printf("/");
    for (int i = 0; i < bid; i++) {
        printf("%c", bop[i]);
    }
    return 0;
}