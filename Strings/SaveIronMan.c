#include <stdio.h>
#include <string.h>

int ifAlphaNumeric(char c) {
	return (48<=c && c<=57 || 65<=c && c<= 90 || 97<=c && c<= 122?1:0);
}

int ifEqualIgnoreCase(char a, char b) {
	return (a==b || a+32==b || b+32==a?1:0);
}

void checkIfAlphaNumericPalindrome(char* s) {
	int i = 0, j = strlen(s)-1;
	while(i<j) {
		if(!ifAlphaNumeric(s[i])) {
			i++;
			continue;
		}
		if(!ifAlphaNumeric(s[j])) {
			j--;
			continue;
		}
		if(!ifEqualIgnoreCase(s[i], s[j])) {
			printf("failing at %c, %c\n", s[i], s[j]);
			printf("No\n");
			return;
		}
		i++;
		j--;
	}
	printf("Yes\n");
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[100];
		scanf("%s", a);
		checkIfAlphaNumericPalindrome(a);
	}
	return 0;
}