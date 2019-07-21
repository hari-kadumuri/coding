#include <stdio.h>
#include <stdlib.h>
/*
void maxheapify(int a[], int i, int n) {
    int l = 2*i+1, r = l+1,temp;
    if(r<n) {
        if(a[l]>a[i]&&a[l]>a[r]) {
            temp = a[i];
            a[i] = a[l];
            a[l] = temp;
            maxheapify(a, l, n);
        }
        else if(a[r]>a[i]) {
            temp = a[i];
            a[i] = a[r];
            a[r] = temp;
            maxheapify(a, r, n);
        }
    }
    else if(l<n) {
        if(a[l]>a[i]) {
            temp = a[i];
            a[i] = a[l];
            a[l] = temp;

        }
    }
}

void makemaxheap(int* a, int n) {
    int i;
    for(i=n/2;i>=0;i--)
        maxheapify(a,i,n);
}

void printklargest(int* a, int n, int k) {
    int i;
    printf("\n");
    for(i=0;i<k;i++) {
        makemaxheap(a, n);
        printf("%d ", a[0]);
        a[0] = -999999;
    }
}

int main() {
    int n;
    printf("enter n :\n");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    int i;
    printf("\nenter array values :\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    int k;
    printf("\nenter k :\n");
    scanf("%d", &k);
    printklargest(a, n, k);
    free(a);
    return 0;
}
*/
