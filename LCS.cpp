#include <iostream>
#include<string>
using namespace std;

int max(int a,int b)
{
    if(a>b)
       return a;
    return b;
}
int LCS(string x,string y,int m,int n)
{
    if(m==1&&n==1){ 
     if(x[m] == y[n])
        return 1;
     else
       return 0;
    }
    else 
    {
        if(m == 1){
           if(x[m] == y[n])
             return 1+LCS(x,y,m,n-1);
           else
             return LCS(x,y,m,n-1);
        }
        else {
          if(n==1)
          {
            if(x[m] == y[n])
                return 1+LCS(x,y,m-1,n);
            else
                return LCS(x,y,m-1,n);
          }
          else{
            if(x[m] == y[n])
              return 1+LCS(x,y,m-1,n-1);
            else
              return max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
          }
    }
}
}

int LCS_DP(string x, string y, int m, int n) {
    int opt[m+1][n+1];
    for (int i = 0; i <= m; ++i)
        opt[i][0] = 0;
    for (int i = 0; i <= n; ++i)
        opt[0][i] = 0;
    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(x[i]==y[j])
                opt[i][j] = 1+opt[i-1][j-1];
            else
                opt[i][j] = max(opt[i-1][j], opt[i][j-1]);
        }
    }
    return opt[m][n];
}

int main() {
  //code
  int a;
  cin >> a;
  while(a--)
  {
      int m,n,i,j;
      cin >> m >> n;
      string x,y;
      cin >> x;
      cin >> y;
      cout << LCS(x,y,m,n) << endl;
      cout << LCS_DP(x,y,m,n) << endl;
      
  }
  return 0;
}