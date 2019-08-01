#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkIfKAnagrams(char* a, char* b, int k) {
	int m = strlen(a), n = strlen(b), i, diff = 0;
	if(m!=n)
		return 0;
	int* x = (int*)calloc(26, sizeof(int));
	int* y = (int*)calloc(26, sizeof(int));
	for(i=0;i<n;i++) {
		x[a[i]-97]++;
		y[b[i]-97]++;
	}
	for(i=0;i<26;i++)
		if(x[i]>y[i])
			diff += x[i]-y[i];
	free(x);
	free(y);
	return (diff>k?0:1);
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001], b[1001];
		int k;
		scanf("%s%s%d", a, b, &k);
		printf("%d\n", checkIfKAnagrams(a, b, k));
	}
	return 0;
}