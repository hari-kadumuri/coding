#include <stdio.h>

void swap(int* a, int x, int y) {
	int temp;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}

int partitionIntoThreeSets(int* s, int n, int a, int b) { // partitions the array into three sets
	int i, countless = 0, countrange = 0, j, k, p;		  // first set contains elements that are less than are equal to a
	for(i=0;i<n;i++) {									  // second set contains elements that are between a and b
		if(s[i]<=a)										  // third set contains elements that are greater than or equal to b
			countless++;
		else if(s[i]<b)
			countrange++;
	}
	if(!(countless>0 && countrange>0 && n-countless-countrange>0))
		return -1;
	i = 0;
	j = countless;
	k = countless+countrange;
	for(p=0;p<n;p++) {
		if(s[p]<=a && !(p<countless))
			swap(s, i++, p);
		else if(s[p]>a && s[p]<b && !(p>=countless && p<countless+countrange))
			swap(s, j++, p);
		else if(s[p]>=b && !(p>=countless+countrange))
			swap(s, k++, p);
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int T, n, a, b;
	scanf("%d", &T);
	while(T-->0) {
		scanf("%d", &n);
		int s[n], i;
		for(i=0;i<n;i++)
			scanf("%d", &s[i]);
		scanf("%d%d", &a, &b);
		if(partitionIntoThreeSets(s, n, a, b)==-1)
			printf("Can't be Partitioned into three sets with given range");
		else {
			printf("Partitioned Array : ");
			for(i=0;i<n;i++)
				printf("%d ", s[i]);
		}
		printf("\n");
	}
	return 0;
}