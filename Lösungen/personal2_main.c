#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int calc_arbeitszeit(int wochenarbeitszeit, int stand_vormonat, int wochensoll, char *bemerkung,int vormonat_ignorieren);

int main(int argc , char *argv[]){
    int wochensoll = 40;
    char *name;
    int wochenarbeitszeit;
    int stand_vormonat;
    char* bemerkung;
    int vormonat_ignorieren;
    FILE *in = fopen(argv[1],"r");
    FILE *out[(argc-2)/2];
    int arr [(argc-2)/2]; 
    int counter =0;
    for(int i = 2;i <=argc; i+=2){
        out [counter] = fopen(argv[i],"w");
        arr[counter] = atoi(argv[i+1]);
        counter++;
     }
    int j =0;
    while(fscanf(in,"%s%i%i%s[^\n] ", name , &wochenarbeitszeit , &stand_vormonat , bemerkung) == 4){ 
        int auszug =calc_arbeitszeit( wochenarbeitszeit , stand_vormonat , wochensoll , bemerkung , vormonat_ignorieren);
        if(arr[j] == 0)
            j++;
		fprintf(out[j], "%s%i\n",name, auszug);
		arr[j]-=1;
    }   
return 0;
}
