#include <stdio.h>
#include <string.h>

void sortTheStringWithLowerCases(char* s) {// runs in O(n) space
	int count[26], i, j = 0;
	for(i=0;i<26;i++)
		count[i] = 0;
	int n = strlen(s);
	for(i=0;i<n;i++)
		count[s[i]-97]++;
	i = 25;
	while(i>0) {
		if(count[i]==0)
			i--;
		else {
			s[j] = 'a'+i;
			j++;
			count[i]--;
		}
	}
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[100];
		scanf("%s", a);
		sortTheStringWithLowerCases(a);
		printf("Sorted String: %s\n", a);
	}
	return 0;
}