#include <stdio.h>
#include <string.h>

int ifNumeric(char a) {
	return (48<=a && 57>=a?1:0);
}

int extractMaximum(char* s) {
	int n = strlen(s), i, max = -1, val = 0;
	for(i=0;i<n;i++) {
		if(ifNumeric(s[i])) {
			val = val*10 + s[i]-48;
			if(i==n-1 && val>max)
				max = val;
		}
		else {
			if(i>0 && ifNumeric(s[i-1])) {
				if(val>max)
					max = val;
				val = 0;
			}
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T-->0) {
		char a[1001];
		scanf("%s", a);
		printf("%d\n", extractMaximum(a));
	}
	return 0;
}