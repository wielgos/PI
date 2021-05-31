#include <stdio.h>
#include <stdlib.h>


int min(int a, int b) {
    return (a < b) * a + (a >= b) * b;
}

// inspired by
// https://www.hackerrank.com/challenges/minimum-operations/problem

int moves(int red[], int green[], int blue[], int n) {
    int dp[110][8];
    int i;
    int j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= 7; j++) {
            dp[i][j] = 1 << 30;
        }
    }
    dp[0][0] = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= 7; j++) {
            //straight up magic
            dp[i + 1][j | 1] = min(dp[i + 1][j | 1], dp[i][j] + green[i] + blue[i]);
            dp[i + 1][j | 2] = min(dp[i + 1][j | 2], dp[i][j] + red[i] + blue[i]);
            dp[i + 1][j | 4] = min(dp[i + 1][j | 4], dp[i][j] + red[i] + green[i]);
        }
    }
    j = 0;
    for (i = 0; i < n; i++) {
        if (red[i]) j |= 1;
        if (green[i]) j |= 2;
        if (blue[i]) j |= 4;
    }


    if (dp[n][j] >= (1 << 30))
        dp[n][j] = -1;

    return dp[n][j];
}

int main() {
    int n;
    scanf("%d", &n);
    int *red = calloc(n, sizeof(int));
    int *blue = calloc(n, sizeof(int));
    int *green = calloc(n, sizeof(int));
    int r, g, b;
    //I just dont know how to read those pdfs XDDDD \/ no comment for that, lost 6 tries
//    for (int i = 0; i < n; i++) {
//        scanf("%d%d%d", &r, &g, &b);
//        red[i] = r;
//        green[i] = g;
//        blue[i] = b;
//    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &r);
        red[i] = r;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &g);
        green[i] = g;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        blue[i] = b;
    }
    printf("%d", moves(red, green, blue, n));
    free(red);
    free(blue);
    free(green);
    return 0;
}