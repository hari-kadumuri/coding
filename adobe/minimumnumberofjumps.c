#include<stdio.h>
#include<stdlib.h>
/*
int getMinJumps(int* a, int n) {
    int **T = (int**)malloc((n+1)*sizeof(int*));
    int i,j;
    for(i=0;i<=n;i++)
        T[i] = (int*)malloc(n*sizeof(int));
    for(i=0;i<=n;i++) {
        for(j=0;j<=n;j++) {
            if(i+a[i]>=j)
                T[i][j] = 1;
            else
                T[i][j] = 0;
            if(i==j)
                T[i][j] = 0;
        }
    }

    int *b = (int*)malloc(n*sizeof(int));
    b[0] = 0;
    int min;
    for(i=1;i<n;i++) {
        min = 999999;
        for(j=0;j<i;j++) {
            if(T[j][i]==1 && 1+b[j]<min)
                min = 1+b[j];
        }
        b[i] = min;
    }

    free(b);
    for(i=0;i<=n;i++)
        free(T[i]);
    free(T);
    return min;
}

int main() {
    int n, *a;
    printf("enter n :\n");
    scanf("%d", &n);
    a = (int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("\nMinimum number of jumps = %d", getMinJumps(a, n));
    return 0;
}
*/
