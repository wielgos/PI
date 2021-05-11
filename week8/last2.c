#include <stdio.h>

#define ULLONG_MAX 18446744073709551615

unsigned long long get_sum(unsigned long long number) {
    unsigned long long sum = number;
    while (number > 0) {
        number -= number % 10;
        number /= 10;
        sum += number;
    }
    return sum;
}

int main() {
    unsigned long long S;
    scanf("%llu", &S);
    if (S == 0 || S == 1){
        printf("%llu", S);
        return 0;
    }
    else if (S == ULLONG_MAX){
        printf("-1");
        return 0;
    }
    unsigned long long bottom = S - S / 10 - 2;
    unsigned long long i;
    for (i = bottom; i < ULLONG_MAX; i++) {
        unsigned long long test = get_sum(i);
//        printf("i %llu test %llu\n", i, test);
        if (test == S) {
            printf("%llu", i);
            return 0;
        } else if (test > S+5)
            break;
    }
    printf("-1");
    return 0;
}