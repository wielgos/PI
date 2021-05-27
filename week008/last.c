#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

unsigned int get_sum(unsigned int number){
    unsigned int sum = number;
    if (number == 0)
        return 0;
    while (number > 0) {
        number -= number % 10;
        number /= 10;
        sum += number;
    }
    return sum;
}

int min(a,b){
    if (a<b)
        return a;
    return b;
}

int max(a,b){
    if (a>b)
        return a;
    return b;
}

int main() {
    int S;
    scanf("%d", &S);
    if (S == 0){
        printf("0");
        return 0;
    }
    int digs = floor(log10(S)+1);
    unsigned int bottom = min((int)pow(10,(digs-1)), 0);
    unsigned int top = max((int)pow(10,(digs+1)),1);
    //printf("%d %d\n", bottom, top);

    for (unsigned int i = bottom; i<=top; i++){

        unsigned int test = get_sum(i);
        printf("%d %d  -> %d\n", i, test, S-i/10-i/100-i/1000-i/10000);
        if (test == S)
        {
            printf("%d", i);
            return 0;
        }
        else if (test > S+10)
            break;
    }
    printf("-1");
    return 0;
}