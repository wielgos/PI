#include <stdio.h>

unsigned int check(int num, int n, int m){
    if(num%m == 0){ //dont check num if its already an multiplier
        return 0; //invalid
    }
    for (int i = 0; i<n; i++){ //we switch on n positions
        num ^= 1 << i; //toggle switch(on/off) i-ty bit
        if (num%m ==0 && num != 0) // 0modsmth would cause problems
            return 1;
        num ^= 1 << i; //back to previous state
    }
    return 0;

}
int main() {
    int n;
    int m;
    int c = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i<1<<n; i++){
        if (check(i,n,m))
            c++;
    }
    printf("%d", c);

    return 0;
}