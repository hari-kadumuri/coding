#include<stdio.h>

/*int main() {
    int n;
    printf("\nenter n :\n");
    scanf("%d",&n);

    int *a = (int*)malloc(n*sizeof(int));
    printf("enter array\n");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int T;
    printf("\nenter T\t");
    scanf("%d",&T);

    //finding contiguous sub array with sum = T
    int start=0, sum = a[0];
    for(i=1;i<=n;i++) {
        while(sum>T && start<i-1) {
            sum -= a[start];
            start++;
        }
        if(sum == T) {
            printf("\nsum is found between %d and %d", start, i-1);
            break;
        }
        if(i<n)
            sum += a[i];
    }

    return 0;
}
*/
