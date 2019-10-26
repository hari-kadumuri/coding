/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

long long int func(long long int a, long long int b,long long int c,long long int k, long long int p,long long int q){
    if(p<q) {
        long long int r = (p+q)/2;
        long long int k1 = r*(a+b*(long long int)(log(r)/log(2))+c*r*r);
        if(k1 == k)
            return r;
        if(p == q)
            return 0;
        else if(k1 > k)
            return func(a, b, c, k, p, r);
        return func(a, b, c, k, r+1, q);
    }
    return 0;
}

long long int limit(long long int a, long long int b,long long int c,long long int k){

    long long int r, k1;
    for(r=1;r<pow(2,63);r=r*2) {
        k1 = r*(a+b*(long long int)(log(r)/log(2))+c*r*r);
        if(k1>=k)
            return r;
    }
}

int main()
{
    long long int a, b, c, k;
    scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
    long long int x = limit(a, b, c, k);
    long long int y = func(a, b, c, k, x/2, x);
    printf("%lld\n", y);
    return 0;
}
