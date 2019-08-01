#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkRotation(char* a, char* b) {
	int m = strlen(a), n = strlen(b);
	char* x = (char*)malloc(m*sizeof(char));
	x[0] = '\0';
	strcat(x, a);
	strcat(x, a);
	// now b should contain in a if b is rotation of a
	int p = (strstr(x, b)?1:0);
	free(x);
	return p;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001], b[1001];
		scanf("%s%s", a, b);
		printf("%d\n", checkRotation(a, b));
	}
	return 0;
}