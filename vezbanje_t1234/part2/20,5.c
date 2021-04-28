// unos matrica A i B i ispis matrice C=A*B

#include <stdio.h>
#define MAX 10

int main(){
	int n, i, j, k;
	int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	printf("Unesite veličinu kvadratnih matrica: \n");
	scanf("%d", &n);
	printf("Unos matrice A: \n");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("A[%d][%d]=", i, j);
			scanf("%d",&A[i][j]);
			}
		}
	printf("Unos matrice B: \n");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("B[%d][%d]=", i, j);
			scanf("%d",&B[i][j]);
			}
		}
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			C[i][j]=A[i][j]+B[i][j];
			}
		}
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("%d\t", C[i][j]);
			}
		printf("\n");
		}
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			C[i][j]=0;
			for (k=0; k<n; k++){
				C[i][j]+=A[i][k]*B[i][j];
				}
			}
		}
	printf("Ispis matrice C=A*B: \n");
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			printf("%d\t", C[i][j]);
			}
		printf("\n");
		}
return 0;}
