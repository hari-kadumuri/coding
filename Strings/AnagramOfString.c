#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void countSortLowerCaseString(char* a) {
	int i, *x = (int*)calloc(26, sizeof(int)), n = strlen(a);
	for(i=0;i<n;i++)
		x[a[i]-97]++;
	int j = 0; i = 0;
	while(i<n && j<26) {
		if(x[j]==0) {
			j++;
		}
		else {
			a[i++] = 'a'+j;
			x[j]--;
		}
	}
}

int makeAnagrams(char* a, char* b) {
	int m = strlen(a), n = strlen(b), i = 0, j = 0, count = 0;
	countSortLowerCaseString(a);
	countSortLowerCaseString(b);
	while(i<m && j<n) {
		if(a[i]==b[j]) {
			i++;j++;
		}
		else {
			count++;
			if(a[i]>b[j]) j++;
			else i++;
		}
	}
	count += m+n-i-j;
	return count;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001], b[1001];
		scanf("%s%s", a, b);
		printf("%d\n", makeAnagrams(a, b));
	}
	return 0;
}