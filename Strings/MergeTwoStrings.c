#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* MergeTheStrings(char* a, char* b) {// runs in O(sum of lengths of a and b) time
	int m = strlen(a), n = strlen(b), i = 0, j = 0, k = 0;
	char *c = (char*)malloc((m+n+1)*sizeof(char));
	while(1) {
		if(k%2==0) {
			if(i<m)
				c[k] = a[i++];
			else if(j<n)
				c[k] = b[j++];
			else
				break;
		}
		else {
			if(j<n)
				c[k] = b[j++];
			else if(i<m)
				c[k] = a[i++];
			else
				break;
		}
		k++;
	}
	c[k+1] = '\0';
	return c;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[100], b[100];
		scanf("%s%s", a, b);
		char *c = MergeTheStrings(a, b);
		printf("Merged String: %s\n", c);
		free(c);
	}
	return 0;
}