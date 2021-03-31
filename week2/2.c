#include <stdio.h>

unsigned int intpow(int num, int k){
    int q = 1;
    for (int i =1; i<= k; i++){
        q = q * num;

    }
    return q;
}

unsigned int nar(int t[], int m, int base){
    int sum1 = 0;

    for (int i = m-1; i >= 0; i--){
        sum1 += t[i] * intpow(base, m-1-i);
    }
    int sum2 = 0;
    for (int i = 0; i < m; i++){
        sum2 += intpow(t[i], m);
    }
    if (sum1 == sum2)
        return 1;
    return 0;
}

void print_in_base(int t[], int m, int base){
    char num[]="0123456789ABCDEFGH";
    for (int i=0; i<m; i++)
        printf("%c", num[t[i]]);
    printf(" ");
}

int main() {
    unsigned int m;
    unsigned int base;
    unsigned int found=0;
    scanf("%d %d", &m, &base);
    int t[m];
    for (int i = 0; i<m; i++){
        t[i]=0;
    }
    t[0]=1;
    while (1){
        if (nar(t, m, base) == 1){
            found = 1;
            print_in_base(t, m, base);
        }
        // append
        if (t[m-1] < base -1)
            t[m-1]++;
        else{
            int i = m-1;
            while (t[i] == base-1){
                t[i] = 0;
                i--;
            }
            if (i == -1)
                break;
            t[i]++;
        }
    }
    if (found == 0)
        printf("NO");
    return 0;
}