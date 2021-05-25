#include <stdio.h>

#define OFFSET 50


int get_offset(int i) {
    return i - 100;
}

int set_offset(int i) {
    return i + 100;
}


void plansza(int *t, int r, int l) {
    for (int i = l; i <= r; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
    for (int i = l; i <= r; i++) {
        printf("%d ", get_offset(i));
    }
    printf("\n-------------\n");
}

int check_end(int *t) {
    for (int i = 0; i < 14999; i++) {
        if (t[i] != 0 && t[i + 1] != 0) {
            return 0;
        }
        if (t[i] > 1 || t[i + 1] > 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t[15000];
    for (int i = 0; i < 15000; i++) {
        t[i] = 0;
    }
    int n = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m = 0;
        scanf("%d", &m);
        m += OFFSET;
        scanf("%d", &t[m]);
    }
    int size3 = 1;
    //plansza(t,0,100);
    while (size3) {
        size3 = 0;
        for (int i = 2; i < 14997; i++) {
            if (t[i] >= 3) {
                t[i - 2] += t[i] / 3;
                t[i + 2] += t[i] / 3;
                t[i] = t[i] % 3;
                if (t[i - 2] >= 3) {
                    size3 = 1;
                }
            }
        }
    }
    int j = -1;
    for (int i = 0; i < 14997; i++) {
        if (t[i] != 0) {
            j = i - 1;
        }
    }
    //plansza(t,0,100);
    while (check_end(t) == 0) {
        int work_done = 0;
        //plansza(t,0,100);
        if (t[j] > 0 && t[j + 1] > 0) {
            //printf("enter:1\n");
            //ruch w prawo
            t[j] -= 1;
            t[j + 1] -= 1;
            t[j + 2] += 1;
            j += 2;
            work_done = 1;
        } else if (t[j] == 2 && t[j - 1] > 0) {
            //printf("enter:2\n");
            j -= 1;
            work_done = 1;
        } else if (t[j] == 2 && t[j + 1] == 0) {
            //printf("enter:3\n");
            //ruch w prawo + lewo
            t[j] -= 1;
            t[j - 1] += 1;
            t[j - 2] += 1;
            t[j - 1] -= 1;
            t[j] -= 1;
            t[j + 1] += 1;
            j += 1;
            work_done = 1;
        } else if (t[j] == 3) {
            //printf("enter:4\n");
            //rozladuj
            t[j - 2] += t[j] / 3;
            t[j + 2] += t[j] / 3;
            t[j] = t[j] % 3;
            j += 2;
            work_done = 1;
        }
        int max_left = -1;
        int left = -1;
        for (int i = 0; i < 14997; i++) {
            if (t[i] && max_left == -1) {
                max_left = i;
            }
            if (t[i] && i < j) {
                left = i;
            }
        }
        if (j == max_left && work_done == 0) {
            //printf("enter:5\n");
            break;
        } else if (work_done == 0) {
            //printf("enter:6\n");
            j = left;
        }

    }
    //plansza(t,0,100);
    for (int i = 0; i < 14997; i++) {
        if (t[i] != 0) {
            printf("%d ", i - OFFSET);
        }
    }
    //plansza(t,0,100);
}