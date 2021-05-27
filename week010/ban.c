#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

#define totalny_kox unsigned long long

void append_num(int num[], int len) {
    int remainder = 1;
    int i = len - 1;
    while (i >= 0 && remainder == 1) {
        num[i] += 1;
        num[i] = num[i] % 10;
        if (num[i] != 0)
            remainder = 0;
    }
}

int modulo(int num[], int len) {
    if (num[len - 1] % 2 == 1)
        return 1;
    else
        return 0;
}


int divide_two(int num[], int len) {
    int remainder = 0;
    int new_remainder;
    for (int i = 0; i < len; i++) {
        new_remainder = (num[i] + remainder * 10) % 2;
        num[i] = (num[i] + remainder * 10) / 2;
        remainder = new_remainder;
    }
    return remainder;
}


int is_zero(int num[], int len) {
    for (int i = 0; i < len; i++)
        if (num[i] != 0)
            return 0;
    return 1;
}

int banf(int res[], int num[], int len, int m) {
    int i = 0;
    while (i < 100 && is_zero(num, len) == 0) {
        res[i] = modulo(num, len);
        if (i % 2 == m && res[i] == 1)
            append_num(num, len);
        divide_two(num, len);
        i++;
    }

    if (is_zero(num, len) == 0)
        return 0;
    else
        return 1;
}

int main() {
    // there is no "NO" case so I ignore that
    // ^^ actually there is xddddd
    // just a hunch forsenCD
    int n, m, k;
    int *t1 = calloc(40, sizeof(int));
    int *t2 = calloc(40, sizeof(int));
    char array[35];
    scanf("%s", array);
    //got array of the number
    int num1[40];
    int num2[40];
    //printf("%s", array);
    int len = strlen(array);
    //len - leength of array

    //printf("%d", len);

    for (int i = 0; i < len; i++) {
        num1[i] = array[i] - '0';
        //printf("%d", num1[i]);
    }

    for (int i = 0; i < len; i++) {
        num2[i] = array[i] - '0';
        //printf("%d", num2[i]);
    }

    int result1[100] = {0};
//    for(int i =0; i<100; i++){
//        printf("%d", result1[i]);
//    }
    //result1,result2 filled with 0
    int is_valid1;
    is_valid1 = banf(result1, num1, len, 1);
    if (is_valid1) {
        for (int j = 0; j < 100; j++) {
            if (result1[j] == 1) {
                printf("%d ", j);
                //printf("%d ", result1[j]);
            }
        }
    } else
        printf("NO");

    printf("\n");
    int is_valid2;
    int result2[100] = {0};
    is_valid2 = banf(result2, num2, len, 0);
    if (is_valid2) {
        for (int j = 0; j < 100; j++) {
            if (result2[j] == 1) {
                printf("%d ", j);
                //printf("%d ", result2[j]);
            }
        }
    } else
        printf("NO");
    free(t1);
    free(t2);
    return 0;
}