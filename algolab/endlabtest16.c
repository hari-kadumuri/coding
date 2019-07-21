#include<stdio.h>
#define MINUS_INFINITY -99999999

int issolvable(int* a, int *b, int n, int T, int idx, int sum) {
    if(idx == n) {
        if(sum == T)
            return 1;
        else
            return 0;
    }
    if(issolvable(a, b, n, T, idx+1, sum+a[idx]) == 1 || issolvable(a, b, n, T, idx+1, sum+b[idx]) == 1)
        return 1;
    else
        return 0;
}

int printsoln(int* a, int* b, int n, int T, int idx, int sum, int* tempa, int* tempb) {
    if(sum == T && idx == n)
        return 1;
    else if (idx == n && sum != T)
        return 0;

    if(printsoln(a, b, n, T, idx+1, sum+a[idx], tempa, tempb) == 1) {
        tempa[idx] = a[idx];
        return 1;
    }
    else if(printsoln(a, b, n, T, idx+1, sum+b[idx], tempa, tempb) == 1) {
        tempb[idx] = b[idx];
        return 1;
    }
    else
        return 0;
}

int main() {
    int n,*a,*b;
    printf("enter n :\n");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    b = (int*)malloc(n*sizeof(int));
    int i;
    printf("\nenter a :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nenter b :\n");
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    printf("\nenter T value :\n");
    int T;
    scanf("%d", &T);
    if(issolvable(a, b, n ,T, 0, 0))
        printf("\n+++ Solution exists");
    else
        printf("\n+++ Solution does not exists");
    int* tempa = (int*)malloc(n*sizeof(int));
    int* tempb = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        tempa[i] = tempb[i] = MINUS_INFINITY;
    printsoln(a, b, n, T, 0, 0, tempa, tempb);
    printf("\nA : \t");

    for(i=0;i<n;i++) {
        if(tempa[i]!=MINUS_INFINITY)
            printf("%d\t",tempa[i]);
        else
            printf("   \t");
    }
    printf("\nB : \t");
    for(i=0;i<n;i++) {
        if(tempb[i]!=MINUS_INFINITY)
            printf("%d\t",tempb[i]);
        else
            printf("   \t");
    }

    return 0;
}
