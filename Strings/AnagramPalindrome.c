#include <stdio.h>
#include <string.h>

void merge(char* a, int left, int mid, int right) {
    int i, k, i1, j, i2;
    char c[right-left+1];
    i = k = i1 = left;
    int j1 = mid;
    j = i2 = mid+1;
    int j2 = right;
    while(i<=j1 && j<=j2) {
        if(a[i]>a[j])
            c[k++] = a[j++];
        else
            c[k++] = a[i++];
    }
    while(i<=j1)
        c[k++] = a[i++];
    while(j<=j2)
        c[k++] = a[j++];
    for(i=left;i<=right;i++)
        a[i] = c[i];
}

void sortTheString(char* a, int left, int right) {	// mergesort function to sort characters in a string based on their ASCII values
    int mid = (left+right)/2;
    if(right>left) {
        sortTheString(a, left, mid);
        sortTheString(a, mid+1, right);
        merge(a,left, mid, right);
    }
    else {
        char temp;
        if(a[right]>a[left]) {
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
    }
}

void checkIfAnagramPalindromeBySort(char* a) {	// runs in O(nlogn) without using extra space
	int i, n, flag = 0;
	n = strlen(a);
	sortTheString(a, 0, n-1);

	i = 1;
	while(i<n) {
		if(a[i]!=a[i-1]) {
			if(flag==0)
				flag = 1;
			else {
				printf("No\n");
				return;
			}
			i++;
		}
		else
			i += 2;
	}
	printf("Yes\n");
}

void checkIfAnagramPalindromeInLinearTime(char* a) {	// runs in O(n) time but uses extra space
	int i, n, flag = 0;
	n = strlen(a);
	int x[128];	// Total 128 different characters are present in ASCII table.
						// x stores the number of occurences of each character in a
	for(i=0;i<128;i++)	// initialising each character's occurences to zero
		x[i] = 0;
	for(i=0;i<n;i++)	// incrementing the count of each characters according to their presence in the strings a and b
		x[a[i]]++;
	for(i=0;i<128;i++)	// if a and b are anagrams then x and y should be same
		if(x[i]%2==1) {
			if(flag==0)
				flag = 1;
			else{
				printf("No\n");
				return;
			}
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
		printf("Sorting algorithm response: ");
		checkIfAnagramPalindromeBySort(a);
		printf("Linear Time algorithm response: ");
		checkIfAnagramPalindromeInLinearTime(a);
	}
	return 0;
}