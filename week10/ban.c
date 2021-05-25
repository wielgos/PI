#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define ull unsigned long long


int main() {
    long long n;
    scanf("%lld", &n);
    int *r = calloc(10000, sizeof(int));
    int stop = 0;
    long long restore = n;
    while (n != 0) {

        int remainder = n % (-2);
        n /= (-2);
        if (remainder < 0) {
            remainder += 2;
            n += 1;
        }
        r[stop] = remainder;
        stop++;
    }
    for (int i = 0; i < stop; i++) {
        if (r[i] == 1)
            printf("%d ", i);

    }
    printf("\n");
    memset(r, 0, 10000 * sizeof(int));
    stop = 0;
    n = (-1) * restore;
    while (n != 0) {

        int remainder = n % (-2);
        n /= (-2);
        if (remainder < 0) {
            remainder += 2;
            n += 1;
        }
        r[stop] = remainder;
        stop++;
    }
    for (int i = 0; i < stop; i++) {
        if (r[i] == 1)
            printf("%d ", i);

    }

    return 0;
}