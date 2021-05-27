#include <stdio.h>


int waga(int t[], int n, int w,int pos){
    if (w == 0){
        return 1;
    }
    if (pos == n){
        return 0;
    }
    return waga(t, n, w + t[pos], pos +1) + waga(t, n, w - t[pos], pos+1);
}

int main() {
    unsigned int n, w;
    scanf("%d %d", &n, &w);
    int t[n];
    for (int i=0; i<n; i++){
        scanf("%d", &t[i]);
    }
    if (waga(t, n, w, 0)>0)
        printf("YES");
    else
        printf("NO");
    return 0;
}