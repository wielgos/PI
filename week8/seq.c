#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
    char *string = calloc(50, sizeof(char));
    char *result = calloc(50, sizeof(char));
    scanf("%s", string);
//    for (int i = 0; i < strlen(string); i++) {
//        printf("%c ", string[i]);
//    }
//    printf("\n");
    int start = 0;
    int resindex = 0;
    int len = strlen(string);
    while (start < len) {
        char max = string[start];
        int index = start;
        for (int i = start + 1; i < len; i++) {
            if (string[i] > max) {
                max = string[i];
                index = i;
            }
        }
        //now i got the max string
        result[resindex] = max;
        resindex++;
        start = index+1;
    }
    for (int i = 0; i < strlen(result); i++) {
        printf("%c", result[i]);
    }
    free(result);
    free(string);
}