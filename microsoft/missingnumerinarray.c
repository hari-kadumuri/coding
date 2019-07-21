#include<stdio.h>

/*int main() {
    int n;
    printf("enter n :\n");
    scanf("%d", &n);
    int* a = (int*)malloc((n-1)*sizeof(int));
    int i;
    printf("\nenter array values :\n");
    for(i=0;i<n-1;i++)
        scanf("%d", &a[i]);

    int* b = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        b[i] = 0;
    for(i=0;i<n-1;i++)
        b[a[i]-1]++;
    for(i=0;i<n;i++) {
        if(b[i] == 0)
            printf("\n%d", i+1);
    }

    free(a);
    free(b);
    return 0;
}
*/
