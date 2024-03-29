#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, n;
	cin>>T;
	while(T-- >0) {
		cin>>n;
		bool* flag = new bool[n+1];
		for(int i=0;i<n+1;i++)
			flag[i] = false;
		int i = 2;
		while(i<n) {
			if(flag[i]==true)
				i++;
			else {
				int s = i*i;
				for(int j = 0; s+j < n+1; j += i)
					flag[s+j] = true;
				i++;
			}
		}
		cout<<"Prime numbers upto "<<n<<" are: ";
		for(int i=2;i<n+1;i++)
			if(flag[i]==false)
				cout<<i<<" ";
		cout<<endl;
		delete[] flag;
	}
	return 0;
}