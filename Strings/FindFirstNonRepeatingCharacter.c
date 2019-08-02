#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findFirstNonRepeatingCharacter(char* s) {
	int n = strlen(s), i, *x = (int*)calloc(26, sizeof(int));
	for(i=0;i<n;i++)
		x[s[i]-97]++;
	for(i=0;i<n;i++) {
		if(x[s[i]-97]==1) {
			printf("%c\n", s[i]);
			break;
		}
		if(i==n-1)
			printf("-1\n");
	}
	free(x);
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001];
		scanf("%s", a);
		findFirstNonRepeatingCharacter(a);
	}
	return 0;
}