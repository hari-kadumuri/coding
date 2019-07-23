#include <stdio.h>
#include <string.h>

void convertToUpperCase(char* s) {
	int i, n = strlen(s);
	for(i=0;i<n;i++)
		if(i==0 || i>0 && s[i-1]==' ')
			s[i] = (s[i]>=65 && s[i]<=90?s[i]:s[i]-32);
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char s[100];
		scanf("%[^\n]s", s);
		printf("s = %s\n", s);
		convertToUpperCase(s);
		printf("Converted String: %s\n", s);
	}
	return 0;
}