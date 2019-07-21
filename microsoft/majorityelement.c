#include<stdio.h>

int getmajority(int* a, int l, int r) {
    if(l==r)
        return a[l];

    int p = getmajority(a, l, (l+r)/2);
    int q = getmajority(a, (l+r)/2+1, r);
    //if(p==q)
      //  return p;

    int x=0,y=0;
    int i;
    for(i=l;i<=r;i++) {
        if(a[i] == p)
            x++;
        if(a[i] == q)
            y++;
    }
    if(x>(r-l+1)/2)
        return p;
    else if(y>(r-l+1)/2)
        return q;
    else
        return -1;
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

    int m = getmajority(a, 0, n-1);
    m==-1?printf("\nNO MAJORITY ELEMENT"):printf("\n%d", m);

    free(a);
    return 0;
}
*/
