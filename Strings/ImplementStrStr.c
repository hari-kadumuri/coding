#include <stdio.h>
#include <string.h>

int StrStr(char* s, char* x) {
	int i = 0, j = 0, m = strlen(s), n = strlen(x);
	while(i<m && j<n) {
		if(s[i]==x[j]) {
			j++;
			if(j==n)
				return i-n+1;
		}
		else
			j = 0;
		i++;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001], b[1001];
		scanf("%s%s", a, b);
		printf("%d\n", StrStr(a, b));
	}
	return 0;
}