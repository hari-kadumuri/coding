#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findUncommonCharacters(char* a, char* b) {
	int m = strlen(a), n = strlen(b), i, j, *x = (int*)calloc(26, sizeof(int)), *y = (int*)calloc(26, sizeof(int));
	for(i=0;i<m;i++)
		x[a[i]-97] = 1;
	for(i=0;i<n;i++)
		y[b[i]-97] = 1;
	for(i=0;i<26;i++)
		if(x[i]==0 && y[i]!=0 || x[i]!=0 && y[i]==0)
			printf("%c", i+'a');
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001], b[1001];
		scanf("%s%s", a, b);
		findUncommonCharacters(a, b);
	}
	return 0;
}