#include<stdio.h>

void Merge(int* a, int left, int mid, int right) {
    int i, k, i1, j, i2,c[right-left+1];
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

void mergesort(int* a, int left, int right) {
    int mid = (left+right)/2;
    if(right>left) {
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        Merge(a,left, mid, right);
    }
    else {
        int temp;
        if(a[right]>a[left]) {
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
    }
}

/*int main() {
    int n;
    printf("enter n :\n");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    int i;
    printf("\nenter array values :\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    mergesort(a, 0, n-1);
    printf("\nenter x :\n");
    int x;
    scanf("%d", &x);

    int j;
    for(i=0,j=n-1;i<j;1) {
        if(a[i]+a[j]>x)
            j--;
        else if(a[i]+a[j]<x)
            i++;
        else {
            printf("Two numbers are : %d  %d", a[i], a[j]);
            break;
        }
    }
    if(i==j)
        printf("such numbers does not exist...!!");

    free(a);
    return 0;
}
*/
