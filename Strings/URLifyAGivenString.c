#include <stdio.h>
#include <string.h>

void URLify(char* s) {
	int n = strlen(s), i, count = 0;
	for(i=0;i<n;i++)
		if(s[i]==' ')
			count++;
	s[n+2*count] = '\0';
	for(i=n-1;i>-1;i--) {
		if(s[i]==' ') {
			count--;
			s[i+2*count] = '%';
			s[i+1+2*count] = '2';
			s[i+2+2*count] = '0';
		}
		else
			s[i+2*count] = s[i];
	}
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001];
		scanf("%[^\n]s", a);
		URLify(a);
		printf("URLed String: %s\n", a);
	}
	return 0;
}