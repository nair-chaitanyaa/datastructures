#include <stdio.h>

void main(){
    float x= 1.043989990999, y=2.01128888988809099;
    for (int i = 0; i < 10000; i++){
        x = x/y;
    }
    printf("%f\n", x);

    for (int i = 0; i < 10000; i++){
        x = x*y;
    }
    printf("%f\n", x);
}

//the more places after decimal you have, the more it gets stressed. Alongside, the higher volume of iterations also causes it to get miniscule such that it only reports 0.

