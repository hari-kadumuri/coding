#include <stdio.h>
#include <string.h>

int checkForSubSequence(char* a, char* b) {
	int i = 0, j = 0, m = strlen(a), n = strlen(b);
	while(i<m && j<n) {
		if(b[j]==a[i]) {
			i++;
			if(i==m)
				return 1;
		}
		j++;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001], b[1001];
		scanf("%s%s", a, b);
		printf("%d\n", checkForSubSequence(a, b));
	}
	return 0;
}