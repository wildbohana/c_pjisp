#include <stdio.h>
#include <string.h>
#define max 21

int jednaki(char *s1, char *s2){
	int x,y,i,j=0, k=0;
	x=strlen(s1);
	y=strlen(s2);
	if (x==y){
		for(i=0; i<=x; i++){
			if (s1[i]==s2[i]){
				j++;}
			}
		}
	if (j==i){
		k=1;}
return k;}

int main(){
	char s1[max], s2[max];
	printf("Unesite dva stringa:\n");
	printf("s1: ");
	gets(s1);
	__fpurge(stdin);
	printf("s2: ");
	gets(s2);
	if (jednaki(s1,s2)==1) {
		printf("Ovi stringovi su jednaki.\n");
		}
	else {
		printf("Ovi stringovi nisu jednaki.\n");
		}
return 0;}
