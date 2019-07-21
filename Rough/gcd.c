#include<stdio.h>

int find_gcd(int x, int y) {
    int temp;
    while(x!=y) {
        if(x>y)
            x = x-y;
        else
            y = y-x;
    }
    return x;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", find_gcd(x, y));
    return 0;
}
