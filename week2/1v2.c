#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int t[n];
    int sum = 0;
    for (int i = 0; i<= n-1; i++){
        scanf("%d", &t[i]);
    }
    for (int i = 1; i<= n-1; i++){
        sum += t[i];
    }
    int sum2 = 0;
    int res=-1;
    for (int i = 0; i<= n-1; i++){
        if (sum2 == sum){
            res = i;
            break;
        }
        sum2 += t[i];
        sum -= t[i+1];
    }
    printf("%d", res);
    return 0;
}