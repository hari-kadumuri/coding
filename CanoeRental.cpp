#include <iostream>
using namespace std;

int findMinCost(int** cost, int n) {
    int price[n];
    price[0] = 0;
    for(int i=1;i<n;i++) {
        int min = 99999999;
        price[i] = cost[0][i];
        for(int j=0;j<=i;j++) {
            if(price[j]+cost[j][i] < min)
                min = price[j]+cost[j][i];
        }
        price[i] = min;
    }
    return price[n-1];
}

int main() {
	int n;
    cin>>n;
    int **cost = new int*[n];
    for(int i=0;i<n;i++) {
        cost[i] = new int[n];
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    }
    cout<<findMinCost(cost, n)<<endl;
    for(int i=0;i<n;i++)
        delete[] cost[i];
    delete cost;
	return 0;
}