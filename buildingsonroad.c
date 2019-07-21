#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n, i;
	printf("enter n: ");
	scanf("%d", &n);
	int h[n], Imp[n];
	printf("enter heights:\n");
	for(i=0;i<n;i++)
		scanf("%d", &h[i]);
	Imp[n-1] = h[n-1];
	for(i=n-2;i>=0;i--) {
		if(h[i]==0) {
			Imp[i] = 0;
			continue;
		}
		int j, maxj = i+1;
		for(j=i+2;j<=i+h[i]&&j<n;j++) {
			if(Imp[j]+j>Imp[maxj]+maxj)
				maxj = j;
		}
		if(i+h[i]>=n && h[i]>maxj-i+Imp[maxj])
			Imp[i] = h[i];
		else
			Imp[i] = Imp[maxj]+maxj-i;
	}
	printf("Impact array: ");
	for(i=0;i<n;i++)
		printf("%d ", Imp[i]);
	printf("\n");
	return 0;
}