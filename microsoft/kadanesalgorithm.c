#include <stdio.h>
#include <stdlib.h>

/*int main() {
    int n;
    printf("enter n :\n");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    int i;
    printf("\nenter array values :\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    //let Vn be the last index of contiguous array with largest sum
    //Dynamic Programming formula :
    //OPT(n) = max { OPT(n-1), OPT(n-1) + a[V(n-1)] + a[V(n-2)] + ............ + a[n], a[n]

    int* firstidx = (int*)malloc(n*sizeof(int));
    int* lastidx = (int*)malloc(n*sizeof(int));
    int* sum = (int*)malloc(n*sizeof(int));
    sum[0] = a[0];
    firstidx[0] = lastidx[0] = 0;
    int tempsum, j;
    for(i=1;i<n;i++) {
        tempsum = sum[i-1];
        for(j=lastidx[i-1]+1;j<=i;j++)
            tempsum += a[j];
        if(tempsum>sum[i-1] && tempsum > a[i])
        {
            sum[i] = tempsum;
            lastidx[i] = i;
            firstidx[i] = firstidx[i-1];
        }
        else if(a[i]>sum[i-1])
        {
            sum[i] = a[i];
            firstidx[i] = lastidx[i] = i;
        }
        else
        {
            sum[i] = sum[i-1];
            firstidx[i] = i-1;
            lastidx[i] = i-1;
        }
    }
    printf("\n%d", sum[n-1]);

    free(firstidx);
    free(lastidx);
    free(sum);
    free(a);
    return 0;
}
*/
