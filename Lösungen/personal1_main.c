#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int calc_arbeitszeit(int wochenarbeitszeit, int stand_vormonat, int wochensoll, char *bemerkung,int vormonat_ignorieren);
int hat_bemerkung( char * mitarbeiterbemerkung, char * gesuchtebemerkung );
int krank_oder_urlaub(char *bemerkung);

int main(int argc , char *argv[]){
    char name[100];
    int wochensoll = atoi(argv[argc-1]);
    int stand_vormonat;
    int wochenarbeitszeit;
    char bemerkung[100];
    int vormonat_ignorieren=0;
    char op;
    char *gesuchtebemerkung = NULL;
    int wahr =0;

	while((op = getopt( argc , argv ,"mab:")) != EOF){
		switch(op){
			case'm':
			wahr =1;
			break;
			case'a':
			vormonat_ignorieren = 1;
			break;
			case'b':
			gesuchtebemerkung = optarg;
			break;
			default:
			printf("ungültige Parameter \n");
		}
	}

	argc -=optind;
	argv +=optind;

    FILE *in = fopen("Mitarbeiter.csv","r");
	while(fscanf(in,"%s%i%i%s[^\n] ", name , &wochenarbeitszeit , &stand_vormonat , bemerkung) == 4){
 
        int auszug =calc_arbeitszeit( wochenarbeitszeit , stand_vormonat , wochensoll , bemerkung , vormonat_ignorieren);
        if( hat_bemerkung( bemerkung, gesuchtebemerkung) ==1 && wahr == 1 && auszug < 0){
         printf("%s %i\n",name,auszug);
        }
        if(hat_bemerkung( bemerkung, gesuchtebemerkung ) ==1 && wahr == 0){
         printf("%s %i\n",name,auszug);
        }      
    }

    fclose(in);
return 0;
}
