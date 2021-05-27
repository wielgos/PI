#include <stdio.h>
#include <malloc.h>
#include <math.h>

int gi(int i, int j){
   return i*201 +j;
}

int main() {
    int N;
    scanf("%d", &N);
    int shift = 100;
    int len = 201;
    int *t = calloc(len*len, sizeof(int));
    for (int i=0; i<len;i++){
        for(int j=0; j<len;j++){
            t[gi(i,j)] = 0;
        }
    }
    int c=0;
    int x1,y1,x2,y2;
    for (int i=0; i<N; i++){
        scanf("%d %d %d %d",&x1, &y1 ,&x2, &y2);
        x1 = x1 + shift;
        y1 = y1 + shift;
        x2 = x2 + shift;
        y2 = y2 + shift;

        //printf("\nx1:%d y1:%d x2:%d y2:%d\n",x1, y1 ,x2, y2);
        //x1y1 to lewy dolny rog
        //x2y2 to prawy gorny rog
        //poczatkowo wszystkie biale
        //kladziemy prostokaty i zawarte w prostokacie pkt zmieniaja sie na przeciwne
        //zliczamy na koniec czarne
        int ch = 0;
        for (int k=y1+1; k<=y2; k++){
            for(int l=x1+1; l<=x2; l++){
                //printf("calc: %d %d\n",k,l);
                if (t[gi(k,l)] == 1){
                    t[gi(k,l)] = 0; //set color to white (0)
                }
                else{
                    t[gi(k,l)] = 1; //set color to black (1)
                    ch++;
                }

            }
        }
        //printf("chelper: %d", ch);
    }
    for (int i=0; i<len;i++){
        for (int j=0; j<len;j++){
            //printf("%d", t[gi(i,j)]);
            if (t[gi(i,j)] == 1){
                c++;
            }
        }
    }
    printf("%d",c);

    return 0;
}