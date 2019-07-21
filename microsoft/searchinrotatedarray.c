#include <stdio.h>
#include <stdlib.h>

int search(int* a, int l, int r, int k) {
    if(l==r) {
        if(a[l] == k)
            return l;
        else
            return -1;
    }

    int mid = (l+r)/2;
    if(k <= a[mid])
        return search(a, l, mid, k);
    else
        return search(a, mid+1, r, k);
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
    for(i=1;i<n;i++) {
        if(a[i]<a[i-1])
            break;
    }
    int r = i;
    int* b = (int*)malloc(n*sizeof(int));
    for(i=0;i<n-r;i++)
        b[i] = a[r+i];
    for(i=n-r;i<n;i++)
        b[i] = a[i+r-n];

    int k;
    printf("\nenter k :\n");
    scanf("%d", &k);

    int m = search(b, 0, n-1, k);
    if(m==-1)
        printf("\n-1");
    else if(m>=n-r)
        printf("\n%d", m-n+r);
    else
        printf("\n%d", m+r);

    free(a);
    free(b);
    return 0;
}
*/
