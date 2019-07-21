#include<stdio.h>

/*int main() {
    int n;
    printf("enter n :\n");
    scanf("%d", &n);
    int* a = (int*)malloc(n*sizeof(int));
    int i;
    printf("\nenter array values :\n");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);

    int sum = 0, factor = 1;
    for(i=n-1;i>=0;i--) {
        sum += factor*a[i];
        factor *= 2;
    }

    if(sum%3 == 0)
        printf("\n1");
    else
        printf("\n0");

    free(a);
    return 0;
}
*/
