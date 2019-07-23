#include <stdio.h>

void checkIfPalindrome(char* a, int n) {
	int i;
	for(i=0;i<n/2;i++)
		if(a[i]!=a[n-1-i]) {
			printf("No\n");
			return;
		}
	printf("Yes\n");
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		int n;
		scanf("%d", &n);
		char a[n];
		scanf("%s", a);
		checkIfPalindrome(a, n);
	}
	return 0;
}