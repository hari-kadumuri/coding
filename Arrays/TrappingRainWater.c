#include <stdio.h>

int findTrappedWater(int* a, int n) {
	if(n<2)
		return 0;
	int left = 0, diffamount = 0, i, waterTrapped = 0;
	for(i=1;i<n;i++) {
		if(a[i]>a[left] || i==n-1) {
			waterTrapped += (a[i]>a[left]?a[left]:a[i])*(i-left-1)-diffamount;
			left = i;
			diffamount = 0;
		}
		else
			diffamount += a[i];
	}
	return waterTrapped;
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
		printf("Amount of Trapped Rain Water = %d\n", findTrappedWater(a, n));
	}
	return 0;
}