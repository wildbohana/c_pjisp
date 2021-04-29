#include <stdio.h>
#include <string.h>

int pon(char *str, char kar){
	int n=0, i;
	for(i=0; i<strlen(str); i++){
		if(str[i]==kar){
			n++;}
		}
return n;}

int main(){
	char str[30], kar;
	printf("Unesite jedan karakter: ");
	scanf("%c", &kar);
	__fpurge(stdin);
	printf("Unesite jedan string: ");
	gets(str);
	printf("Ovaj karakter se u ovom stringu ponavlja ovoliko puta: %d\n", pon(str, kar));
return 0;}
