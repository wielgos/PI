#include <stdio.h>

void iloczyn_fib(int n){
    int fib1=0,fib2=1;
    int temp;
    while (fib1*fib2 < n){
        temp = fib2;
        fib2=fib1+fib2;
        fib1=temp;
    }
    if (fib1*fib2 == n)
        printf("YES");
    else
        printf("NO");
}


int main() {
    int n;
    scanf("%d", &n);
    iloczyn_fib(n);
    return 0;
}