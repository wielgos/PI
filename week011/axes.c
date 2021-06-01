#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>


// essa maker online pozdrawiam
// mw squad

#define ull unsigned long long
#define PI 3.1415
#define abs(a) (((a) < 0) ? -(a) : (a))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int fpointcreate(double x1, double y1, double x2, double y2, int id, double *P1, double *P2) {
    P1[id] = (x1 + x2) / 2;
    P2[id] = (y1 + y2) / 2;
    return 0;
}

int syms(double *X, double *Y, int *res, int n, int id) {
    for (int i = 1; i < 2 * n - 1; i += 2)
        fpointcreate(X[i - 1], Y[i - 1], X[i + 1], Y[i + 1], i, X, Y);
    fpointcreate(X[0], Y[0], X[2 * n - 2], Y[2 * n - 2], 2 * n - 1, X, Y);
    int counter = 0;
    int i = 0;
    while (i < n) {
        int counter2 = 1;
        double point_x = X[i];
        double point_y = Y[i];
        double point2_x = X[i + n];
        double point2_y = Y[i + n];
        int j = 1;
        while (j < n) {
            int t1 = (i + j) % (2 * n);
            int t2;
            if ((i - j) < 0) //correct
                t2 = 2 * n + (i - j);
            else
                t2 = (i - j);
//            printf("t1 %d", t1);
//            printf("t2 %d", t2);
            double test1_x = X[t1];
            double test1_y = Y[t1];
            double test2_x = X[t2];
            double test2_y = Y[t2];
//            printf("test1_x:%lf", test1_x);
//            printf("test1_y:%lf", test1_y);
//            printf("test2_x:%lf", test2_x);
//            printf("test2_y:%lf", test2_y);
            if (dist(test1_x, test1_y, point_x, point_y) != dist(test2_x, test2_y, point_x, point_y)) {
                counter2 = 0;
//                printf("failed1");
                break;
            }
            if (dist(test1_x, test1_y, point2_x, point2_y) != dist(test2_x, test2_y, point2_x, point2_y)) {
                counter2 = 0;
//                printf("failed2");
                break;
            }
            j++;
        }
//        printf("c2:%d", counter2);
        counter += counter2;
        i++;
    }
//    printf("c:%d", counter);
    res[id] = counter;
    return 0;
}


int main() {
    int t;
    scanf("%d", &t);
    int *res = calloc(10000, sizeof(int));
    double *X = calloc(200000, sizeof(double));
    double *Y = calloc(200000, sizeof(double));
    int n;
    int i = 0;
    while (i < t) {
        scanf("%d", &n);
        int j = 0;
        while (j < n) {
            scanf("%lf %lf", &X[2 * j], &Y[2 * j]);
            j++;
        }
        syms(X, Y, res, n, i); //get solution for i
        i++; // go for next ones
    }
    for (int k = 0; k < t; k++)
        printf("%d\n", res[k]); // print results
    // free variables
    free(X);
    free(res);
    free(Y);
    return 0;
}