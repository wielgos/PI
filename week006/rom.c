#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*
 * we: MDCLXVI MCMXCIX
 * wy: MMMDCLXV
 */

char r1[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
char *r2[] = {"CM", "CD", "XC", "XL", "IX", "IV", "I"};
int r1v[] = {1000, 500, 100, 50, 10, 5, 1};
int r2v[] = {900, 400, 90, 40, 9, 4, 1};


int rom_to_int(char *t) {
    unsigned int len = strlen(t);
    int j = 0;
    int result = 0;
    int i = 0;
    while (i <= len - 1) {
        if (t[i] == r1[j]) {
            result += r1v[j];
            i++;
        } else if (t[i] == r2[j][0] && t[i + 1] == r2[j][1]) {
            result += r2v[j];
            i += 2;
        } else
            j++;
    }
    return result;
}

void print_int_to_rom(int v){
    char *result = calloc(15, sizeof(char));
    int i = 0;
    int j = 0;
    while (v>0){
        if (v >= r1v[j]){
            v -= r1v[j];
            result[i] = r1[j];
            i++;
        }
        else if ( v >= r2v[j]){
            v -= r2v[j];
            result[i] = r2[j][0];
            result[i+1] = r2[j][1];
            j++;
            i+=2;
        }
        else{
            j++;
        }
    }
    printf("%s", result);

}
int main() {

    char *rom1 = calloc(7, sizeof(char));
    char *rom2 = calloc(7, sizeof(char));

    scanf("%s%s", rom1,rom2);
    print_int_to_rom(rom_to_int(rom1)+rom_to_int(rom2));
    free(rom1);
    free(rom2);
    return 0;
}