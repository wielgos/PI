#include <stdio.h>
#include <malloc.h>

int main() {
    /*
     * n pktow
     * wszystkie krawdzie default czarne
     * niektore krawdzie maluje na czerwone
     *
     */
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int *w = calloc(n+1, sizeof(int)); // waga czerwonosci [i] wierzcholka
    int p,q;
    for (int i = 0; i < m; i++) { //zliczam czerwonosci wierzcholkow

        scanf("%d %d", &p, &q);
        w[p]++;
        w[q]++; //zliczam czerwonosci dla danego i
    }
    int res = 0;
    for (int i =1; i <= n; i++){ //sumuje od 1, bo nie mam wierzcholka 0
        res += w[i]*(n-1-w[i]);
    }
    printf("%d", (int)(n*(n-1)*(n-2)/6 - res/2)); //wynik
    free(w);
    return 0;
}