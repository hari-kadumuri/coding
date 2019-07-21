#include<stdio.h>
/*
int hasSubset(int* a, int n, int l, int r) {
    if(n==0) {
        if(l==r)
            return 1;
        else
            return 0;
    }
    n--;
    if(hasSubset(a, n, l+a[n], r) || hasSubset(a, n, l, r+a[n]))
       return 1;
    return 0;
}

int main() {
    int *a, n;
    printf("enter n :\n");
    scanf("%d", &n);
    int i;
    a = (int*)malloc(n*sizeof(int));
    printf("enter array :\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    if(hasSubset(a, n, 0, 0))
        printf("\nYES");
    else
        printf("\nNO");

    return 0;
}
*/
