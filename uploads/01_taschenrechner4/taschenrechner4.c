#include "taschenrechner5.h"

int summiere(int start, int ende, int intervall){
    int summe = 0;
    for(int i = start; i <= ende; i+=intervall) summe+=(i*i);
    return summe;
}

int calc(int x, int y, int interval, int mod10){
    int result = summiere(x, y, interval);
    if (mod10 == 0){
        return result;
    }
    return result%10;
}

