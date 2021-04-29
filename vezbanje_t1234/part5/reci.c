#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ms 101

FILE *safe_open(char *name, char *mode){
	FILE *fp=fopen(name, mode);
	
	if(fp==NULL){
		printf("Došlo je do greške prilikom otvaranja fajla.");
		exit(EXIT_FAILURE);
		}
	return fp;
}

void prebrojavanje(FILE *in, FILE *out){
	int broj=0;
	char string[ms];
	int max_s=0;
	int tmp_s;
	char najduzi[ms];
	
	while(fscanf(in,"%s",string)!=EOF){
		broj++;
		tmp_s=strlen(string);
		if (max_s < tmp_s){
			max_s=tmp_s;
			strcpy(najduzi, string);
			}
		}
	fprintf(out,"Ucitano je %d stringova od kojih je najduzi: %s.\n",broj,najduzi);
}

int main(int brarg, char* arg[]){
	
	FILE *in, *out;
	
	if (brarg!=3){
		printf("Niste dobro pozvali program.");
		exit(EXIT_FAILURE);
	}
	
	in=safe_open(arg[1], "r");
	out=safe_open(arg[2], "w");
	
	prebrojavanje(in, out);
	
	fclose(in);
	fclose(out);
	
return 0;}
