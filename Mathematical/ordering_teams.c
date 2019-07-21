#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(int argc, char const *argv[])
{
	int a[3], b[3], c[3], i;
	scanf("%d%d%d", &a[0], &a[1], &a[2]);
	scanf("%d%d%d", &b[0], &b[1], &b[2]);
	scanf("%d%d%d", &c[0], &c[1], &c[2]);
	int idx[3];
	idx[0] = 0;idx[1] = 1;idx[2] = 2;
	if(a[0]>a[1]) {
		swap(&idx[0], &idx[1]);
		swap(&a[0], &a[1]);
	}
	if(a[1]>a[2]) {
		swap(&idx[1], &idx[2]);
		swap(&a[1], &a[2]);
	}
	if(a[0]>a[1]) {
		swap(&idx[0], &idx[1]);
		swap(&a[0], &a[1]);
	}
	if(b[idx[0]]>b[idx[1]] || b[idx[1]]>b[idx[2]] || c[idx[0]]>c[idx[1]] || c[idx[1]]>c[idx[2]]) {
		printf("no\n");
		return 0;
	}
	printf("yes\n");
	return 0;
}