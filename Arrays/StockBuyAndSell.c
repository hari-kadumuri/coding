#include <stdio.h>

void findBestPrice(int* a, int n) {
	int i, init, final;
	for(i=0;i<n-1;i++)
		if(a[i+1]-a[i]>0)
			break;
	init = i;
	while(i<n-1) {
		if(a[i+1]-a[i]<0 || (a[i+1]-a[i]>=0 && i==n-2)) {
			printf("(%d, %d) ", init, (i==n-2?n-1:i));
			init = i+1;
		}
		i++;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n, T;
	scanf("%d", &T);
	while(T-->0) {
		scanf("%d", &n);
		int a[n], i;
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
		findBestPrice(a, n);
	}
	return 0;
}