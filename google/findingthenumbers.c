#include<stdio.h>

/*void Merge(int* a, int left, int mid, int right) {
    int i, k, i1, j, i2,c[right-left+1];
    i = k = i1 = left;
    int j1 = mid;
    j = i2 = mid+1;
    int j2 = right;
    while(i<=j1 && j<=j2) {
        if(a[i]>a[j])
            c[k++] = a[j++];
        else
            c[k++] = a[i++];
    }
    while(i<=j1)
        c[k++] = a[i++];
    while(j<=j2)
        c[k++] = a[j++];
    for(i=left;i<=right;i++)
        a[i] = c[i];
}

void mergesort(int* a, int left, int right) {
    int mid = (left+right)/2;
    if(right>left) {
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        Merge(a,left, mid, right);
    }
    else {
        int temp;
        if(a[right]>a[left]) {
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
    }
}

//method using sorting. Runs in O(nlogn) time
void findthenumbers1(int* a, int n) {
    mergesort(a, 0, n-1);

    int i=0, x, y, z = 1;
    while(1) {
        if(a[2*i] == a[2*i+1])
            i++;
        else {
            x = a[2*i];
            break;
        }
    }
    i++;
    while(1) {
        if(a[2*i-1] == a[2*i])
            i++;
        else {
            y = a[2*i-1];
            break;
        }
    }
    printf("\n\n+++ Method1");
    printf("\nTwo numbers are %d and %d", (x<y)?x:y, (x>=y)?x:y);
}

//method using counting sort technique. Runs in O(n) time under the assumption that maximum value in array a < sizeof(B)
void findthenumbers2(int* a, int n) {
    int B[1000];
    int i;
    for(i=0;i<1000;i++)
        B[i] = 0;
    for(i=0;i<n;i++)
        B[a[i]]++;
    int x,y,z=1;
    for(i=0;i<1000;i++) {
        if(B[i] == 1) {
            if(z==1)
                x = i;
            else
                y = i;
            z++;
        }
    }
    printf("\n\n+++ Method2");
    printf("\nTwo numbers are %d and %d\n", (x<y)?x:y, (x>=y)?x:y);
}

int main() {
    int n;
    printf("enter n :\n");
    scanf("%d",&n);

    int *a = (int*)malloc(n*sizeof(int));
    printf("enter array\n");
    int i;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    findthenumbers1(a, n);
    findthenumbers2(a, n);

    free(a);
    return 0;
}
*/
