// za prirodan broj n se izračunava S=1*2 + 2*3*4 + ... + (n+0)*(n+1)*...*(n+n)

#include <stdio.h>

int main(){
	int n, x=1, y=2, s=0, limit;
	printf("Unesite prirodan broj n: \n");
	scanf("%d", &n);
	limit=2*n;
	while (x<limit){
		s=s+(x*y);
		x++, y++;
		}
	printf("%d\n", s);
return 0;}
