#include <stdio.h>
//wadliwe bo jednak to są liczby całkowite, nie naturalne jak w opisie :)

int half(int t[], int n){
    int i = 0;
    int j = n-1;
    int diff = t[0] - t[n-1];
    while (i +1 != j){
        if (diff < 0){
            i++;
            diff += t[i];
        }
        else {
            j--;
            diff -= t[j];
        }
    }
    return i+1;

}

int main() {
    int n;
    scanf("%d", &n);
    int t[n];
    for (int i=0; i<=n-1; i++){
        scanf("%d", &t[i]);
    }
    printf("%d", half(t,n));
    return 0;
}