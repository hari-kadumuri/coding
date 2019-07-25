#include <stdio.h>
#include <string.h>

int ifVowel(char a) {
	if(a=='a' || a== 'e' || a=='i' || a=='o' || a=='u')
		return 1;
	return 0;
}

int ifConsonant(char a) {
	if(97<=a && a<=122 && !ifVowel(a))
		return 1;
	return 0;
}

int GoodOrBad(char* s) {
	int countConsonants = 0, countVowels = 0, n = strlen(s), i, vowelFlag = 0, consonantFlag = 0;
	for(i=0;i<n;i++) {
		if(ifVowel(s[i])) {
			countVowels++;
			countConsonants = 0;
		}
		else if(ifConsonant(s[i])) {
			countConsonants++;
			countVowels = 0;
		}
		else {
			countVowels++;
			countConsonants++;
		}
		if(countVowels>5 || countConsonants>3)
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[100];
		scanf("%s", a);
		printf("%d\n", GoodOrBad(a));
	}
	return 0;
}