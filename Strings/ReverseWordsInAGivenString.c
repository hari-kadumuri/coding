#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseWords(char* s) {
	int n = strlen(s), wordCount = 1, i, j = 0, k = 0;
	for(i=0;i<n;i++)
		if(s[i]=='.')
			wordCount++;
	char** table = (char**)malloc(wordCount*sizeof(char*));
	for(i=0;i<wordCount;i++)
		table[i] = (char*)malloc((n+1)*sizeof(char));
	char* head = table[j];
	for(i=0;i<n;i++) {
		if(s[i]=='.') {
			head[k] = '\0';
			head = table[++j];
			k = 0;
		}
		else {
			head[k] = s[i];
			k++;
		}
		s[i] = '\0';
	}
	for(j=wordCount-1;j>=0;j--) {
		strcpy(s + strlen(s), table[j]);
		if(j>0)	strcat(s, ".");
	}
	for(i=0;i<wordCount;i++)
		free(table[i]);
	free(table);
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001];
		scanf("%s", a);
		reverseWords(a);
		printf("%s\n", a);
	}
	return 0;
}