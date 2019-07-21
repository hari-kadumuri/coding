#include<stdio.h>
#include<time.h>
#include<math.h>

float exhprofit(float* c, int n, int leftidx, int rightidx, int daycount) {
    if(leftidx==-1&&rightidx==n)
        return 0;
    if(leftidx==-1)
        return exhprofit(c, n, leftidx, rightidx+1, daycount+1)+pow(0.9, daycount)*c[rightidx];
    if(rightidx==n)
        return exhprofit(c, n, leftidx-1, rightidx, daycount+1)+pow(0.9, daycount)*c[leftidx];
    float l = exhprofit(c, n, leftidx-1, rightidx, daycount+1)+pow(0.9, daycount)*c[leftidx];
    float r = exhprofit(c, n, leftidx, rightidx+1, daycount+1)+pow(0.9, daycount)*c[rightidx];
    if(l>r)
        return l;
    return r;
}

float grprofit(float* c, int n, int leftidx, int rightidx, int daycount) {
    if(leftidx==-1&&rightidx==n)
        return 0;
    if(leftidx==-1)
        return grprofit(c, n, leftidx, rightidx+1, daycount+1)+pow(0.9, daycount)*c[rightidx];
    if(rightidx==n)
        return grprofit(c, n, leftidx-1, rightidx, daycount+1)+pow(0.9, daycount)*c[leftidx];
    if(c[leftidx] >= c[rightidx])
        return grprofit(c, n, leftidx-1, rightidx, daycount+1)+pow(0.9, daycount)*c[leftidx];
    return grprofit(c, n, leftidx, rightidx+1, daycount+1)+pow(0.9, daycount)*c[rightidx];
}

float dpprofit(float* c, int n) {
    float T[n/2+1][n/2+1];
    T[n/2][n/2] = 0;
    int i,j;
    T[n/2][n/2-1] = pow(0.9, n/2+n/2-2)*c[n-1] + pow(0.9, n/2+n/2-1)*c[0];
    T[n/2-1][n/2] = pow(0.9, n/2+n/2-2)*c[0] + pow(0.9, n/2+n/2-1)*c[n-1];
    for(i=n/2-2;i>=0;i--)
        T[n/2][i] = c[n/2-1-i]*pow(0.9, n/2+i-1) + T[n/2][i+1];
    for(i=n/2-2;i>=0;i--)
        T[i][n/2] = c[n/2+i]*pow(0.9, n/2+i-1) + T[i+1][n/2];
    for(i=n/2-1;i>=0;i--)
        for(j=n/2-1;j>=0;j--) {
            if(T[i+1][j] + pow(0.9, i+j-1)*c[n/2+i] < T[i][j+1] + pow(0.9, i+j-1)*c[n/2-1-j])
                T[i][j] = T[i][j+1] + pow(0.9, i+j-1)*c[n/2-1-j];
            else
                T[i][j] = T[i+1][j] + pow(0.9, i+j-1)*c[n/2+i];
        }
    return T[0][0];
}

/*int main() {
    float c[100];
    int n;
    printf("Enter n :\n");
    scanf("%d", &n);
    int i;
    for(i=0;i<n;i++)
        scanf("%f", &c[i]);

    printf("\n+++ Exhaustive Search");
    printf("\n\tMaximum profit = %f", exhprofit(c, n, n/2-1, n/2, 0));

    printf("\n\n+++ Greedy Strategy");
    printf("\n\tMaximum profit = %f", grprofit(c, n, n/2-1, n/2, 0));

    printf("\n\n+++ Dynamic Programming");
    printf("\n\tMaximum profit = %f", dpprofit(c, n));
    return 0;
}
*/
