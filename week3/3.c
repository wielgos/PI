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

unsigned int sum_of_digs(int n){
    int s = 0;
    int reszta;
    while (1){
        reszta = n%10;
        s += reszta*reszta;
        n -= reszta;
        if (n == 0)
            break;
        n = n/10;
    }
    if (s == 1)
        return 1;
    else if (s == 4)
        return 0;
    else
    {
        return sum_of_digs(s);
    }

}

int main() {
    int L,U,K;
    scanf("%d %d %d", &L, &U, &K);
    int f = 0;
    for (int i = L; i<=U; i++){
        if (is_prime(i)==1 && sum_of_digs(i)==1)
            f += 1;
        if (f == K)
        {
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}