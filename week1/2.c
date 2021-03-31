#include <stdio.h>
#include <math.h>

unsigned int sum_of_divisors(int n)
{
    int s=0;
    for (int i=1; i<pow(n, 0.5); i+=1){
        if (n % i == 0){
            if (n / i == i)
                s += i;
            else
                s += i + n / i;
        }
    }
    return s-n;
}


int main() {
    int m,n,found=0,index=0;
    int numbers[100];
    scanf("%d %d",&m, &n);
    for (int i=m; i<=n; i++){
        if (sum_of_divisors(i)==i)
        {
            found+=1;
            numbers[index]=i;
            index+=1;
        }
    }
    printf("%d\n",found);
    for (int i=0; i<index; i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}