// unesi broj N i broj q i ispiši sve brojeve od 1 do N koji su deljivi sa q

#include <stdio.h>

int main(){
	int n, q, i;
	printf("Unesite brojeve N i q: \n");
	scanf("%d", &n);
	scanf("%d", &q);
	
	for(i=2; i<(n+1); i++){
		if((i%q)==0){
			printf("%d\n", i);
			}
	}
	
return 0;}
