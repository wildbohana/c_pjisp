// unosiš niz i u nemu računaš maksimum

#include <stdio.h>
#define MAX 20

int main(){
	double a[MAX], max;
	int n,i;
	printf("Unesite broj elemenata koje želite u nizu: \n");
	scanf("%d", &n);
	if (n>0 && n<=MAX){
		for (i=0; i<n; i++){
			printf("a[%d]=", i);
			scanf("%lf", &a[i]);
			}
		max=a[0];
		for (i=0; i<n; i++){
			if (a[i]>max){
				max=a[i];
				}
			}
		printf("\nNajveći broj je %.2lf.\n", max);
		}
	else{
		printf("Uneli ste pogrešan broj.\n");
		}
return 0;}
