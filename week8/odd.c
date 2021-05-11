#include <stdio.h>

unsigned long long p2(unsigned long long a){
    return a*a;
}
unsigned long long sum(unsigned long long n)
{
    if (n == 0)
        return 0;
    if (n % 2 == 1) {  //nieparzysta
        return p2((n + 1) / 2) + sum(n / 2);
    }
    else { // parzysta
        return p2(n / 2) + sum(n / 2);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%llu", sum(N));
    return 0;
}