#include <stdio.h>
#include <math.h>

unsigned int is_prime(int n){
    if (n==2)
        return 1;
    if (n%2==0)
        return 0;
    if (n==1)
        return 0;
    for (int i=3; i<=pow(n, 0.5);i+=2){
        if (n%i==0)
            return 0;
    }
    return 1;
}

unsigned int check_dig(int n){
    int prev=11,cur,a;
    while (1){
        cur = n%10;
        if (cur>prev)
            return 0;
        n = n - cur;
        if (n == 0)
            return 1;
        n = n/10;
        prev = cur;
    }
}


int main() {
    int n;
    scanf("%d",&n);
    if (n >= 3)
        printf("2\n");
    for (int i=3; i<n; i+=2){
        if (check_dig(i)==1 && is_prime(i)==1)
            printf("%d\n", i);
    }
    return 0;
}