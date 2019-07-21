#include <iostream>
using namespace std;
// The following code runs in O(n^2) time complexity and O(n) space complexity. Try to reduce the time complexity or space complexity.
int main(int argc, char const *argv[])
{
	int T, n;cin>>T;
	while(T-- >0) {
		cin>>n;
		int count = 0;
		bool *flag = new bool[n+1];
		for (int i = 0; i < n+1; ++i)
			flag[i] = false;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i%j==0)
					flag[i] = !flag[i];
		for (int i = 1; i < n+1; ++i)
			if(flag[i]==true)
				count++;
		cout<<count<<endl;
		delete[] flag;
	}
	return 0;
}