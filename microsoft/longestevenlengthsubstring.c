#include<stdio.h>
#include<stdlib.h>
/*
int findevenlengthlongestsubstring(int* a, int l, int r) {
    int leftsum = 0, i, rightsum = 0, p, q;

    if(r==l+1) {
        if(a[l] == a[r])
            return 2;
        else
            return 0;
    }

    if((r-l+1)%2==0) {

        for(i=0;i<=(r-l)/2;i++) {
            leftsum += a[l+i];
            rightsum += a[r-i];
        }
        if(leftsum==rightsum)
            return (r-l+1);
    }

    p = findevenlengthlongestsubstring(a, l, r-1);
    q = findevenlengthlongestsubstring(a, l+1, r);
    if(p>q)
        return p;
    else
        return q;
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

    printf("\nlength of longest even length substring with same left sum as right sum = %d", findevenlengthlongestsubstring(a, 0, n-1));

    free(a);
    return 0;
}
*/
