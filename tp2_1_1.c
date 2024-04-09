#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(){
    // codigo a completar
    srand(time(NULL));
    #define N 20
    int i;
    double vt[N];
    for(i = 0;i<N; i++){
        vt[i]=1+rand()%100;
        printf("%f ", vt[i]);
    }

    return 0; 
}