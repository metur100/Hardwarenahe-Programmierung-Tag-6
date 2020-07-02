#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int krank_oder_urlaub(char *bemerkung){
    
    if(strcmp("urlaub",bemerkung)==0 ||strcmp("krank",bemerkung)==0)
        return 1;
    return 0;
}

int hat_bemerkung( char * mitarbeiterbemerkung, char * gesuchtebemerkung ){
    if(gesuchtebemerkung == NULL)
        return 1;
    printf("mit: %s, gesucht: %s\n", mitarbeiterbemerkung, gesuchtebemerkung);
    if(strcmp(mitarbeiterbemerkung , gesuchtebemerkung)==0)
        return 1;
    return 0;
}

int calc_arbeitszeit(int wochenarbeitszeit, int stand_vormonat, int wochensoll, char *bemerkung,int vormonat_ignorieren){
    int result;
    if(krank_oder_urlaub(bemerkung)==0){
        if(vormonat_ignorieren == 1){
            result = wochenarbeitszeit - wochensoll;
        }
        if(vormonat_ignorieren == 0){
            result = wochenarbeitszeit - wochensoll + stand_vormonat;
        }
    }
     if(krank_oder_urlaub(bemerkung)==1){
        if(vormonat_ignorieren == 1){
            result = wochenarbeitszeit;
        }
        if(vormonat_ignorieren == 0){
            result = wochenarbeitszeit + stand_vormonat;
        }
    }
return result;
}
