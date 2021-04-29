#include <stdio.h>
#include <string.h>
#define l 21

int prvi(char *s, int k){
	int i;
	printf("a)\n");
	for(i=0; i<k; i++){
		printf("%c",s[i]);
		}
	printf("\n\n");
}

int drugi(char *s, int k, int n){
	int i, x;
	x=n-k;
	printf("b)\n");
	for(i=x;i<n;i++){
		printf("%c", s[i]);
		}
	printf("\n\n");
}

treci(char *s, int k, int p){
	int i;
	printf("c)\n");
	for(i=p;i<p+k;i++){
		printf("%c",s[i]);
		}
	printf("\n\n");
}

int main(){
	char s[l];
	int k,p;
	
	printf("Unesite željeni string: ");
	__fpurge(stdin);
	gets(s);
	
	printf("Unesite k: ");
	scanf("%d", &k);
	printf("Unesite p: ");
	scanf("%d", &p);
	
	prvi(s, k);
	drugi(s, k, strlen(s));
	treci(s, k, p);
	
return 0;}
