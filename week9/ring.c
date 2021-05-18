#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>

unsigned int is_prime(int n) {
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    if (n == 1)
        return 0;
    for (int i = 3; i <= pow(n, 0.5); i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    char *s = calloc(50, sizeof(char));
    scanf("%s", s);
    //printf("%s", s);
    //najpierw wybieramy przesuniecie
    unsigned int n = strlen(s);
    char *test = calloc(n, sizeof(char));
    char *best = calloc(n, sizeof(char));
    for (int i = 0; i < n; i++) {
        best[i] = '{'; //zeby potem od razu podmienic
    }
    for (int o = 0; o < n; o++) {
        //teraz wybieramy krok ktory jest prime
        for (int p = 2; p < n; p++) {
            if (is_prime(p)) {

                for (int l = 0; l < n; l++) {
                    test[l] = s[(o + l * p) % n];
                }
                //printf("test: %s o:%d, p:%d\n", test, o, p);
                // now we got test string so we compare
                if (strcmp(test, best) < 0) {
                    for (int l = 0; l < n; l++) {
                        best[l] = test[l];
                    }
                }
            }
        }
    }
    printf("%s", best);
    free(s);
    free(test);
    return 0;
}