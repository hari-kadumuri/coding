#include<stdio.h>

int main() {
    int n;
    char *a;
    int* sum, *oba, *fidx, *lidx;
    scanf("%d",&n);
    a = (char*)malloc(n*sizeof(char));
    sum = (int*)malloc(n*sizeof(int));
    oba = (int*)malloc(n*sizeof(int));
    fidx = (int*)malloc(n*sizeof(int));
    lidx = (int*)malloc(n*sizeof(int));

    int i;
    for(i=0;i<n;i++)
        scanf("%c",&a[i]);

    //finding the max length of valid parenthesis
    int j=0;
    while(j<n && a[j]!='(') {
        j++;
        printf("hii");
    }
    sum[j] = 1;
    oba[j] = 1;
    fidx[j] = -1;
    lidx[j] = -1;
    for(i=j+1;i<n;i++) {
        if(a[i] == '(') {
            sum[i] = sum[i-1]+1;
            oba[i] = oba[i-1]+1;
        }
        else {
            sum[i] = sum[i-1]-1;
            if(sum[i] == 0) {
                oba[i] = 0;
                if(lidx + 2*oba[i-1] == i) {
                    fidx[i] = fidx[i-1];
                    lidx[i] = i;
                }
                else {
                    if(lidx[i-1]-fidx[i-1]+1 <= 2*oba[i-1]) {
                        lidx[i] = i;
                        fidx[i] = i-oba[i-1];
                    }
                }
            }
        }
    }
    printf("\nMax length of valid parenthesis = %d", lidx[n-1] - fidx[n-1] + 1);
    return 0;
}
