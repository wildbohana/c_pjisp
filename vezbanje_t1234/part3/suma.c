#include <stdio.h>

int main(){
	int n, i, j, pom=1, s=0;
	printf("Unesite broj n: ");
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		for(j=0;j<=i;j++){
			pom*=(i+j);		// * nije pokazivač nego puta jednako
			s+=pom;
			pom=1;
			}		
		}
	printf("Suma je: %d.", s);
return 0;}
