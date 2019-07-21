#include <stdio.h>

void findPairsWithGivenSum(int* a, int n, int k) {
	int i = 0, j = n-1, flag = 0;
	while(i<j) {
		int sum = a[i]+a[j];
		if(sum==k) {
			printf("%d %d\n", a[i++], a[j]);
			flag = 1;
		}
		else if(sum>k)
			j--;
		else
			i++;
	}
	if(!flag)
		printf("-1\n");
}

int main(int argc, char const *argv[])
{
	int n, T, k;
	scanf("%d", &T);
	while(T-->0) {
		scanf("%d", &n);
		int a[n], i;
		for(i=0;i<n;i++)
			scanf("%d", &a[i]);
		scanf("%d", &k);
		findPairsWithGivenSum(a, n, k);
	}
	return 0;
}