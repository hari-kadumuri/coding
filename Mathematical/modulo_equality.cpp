#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> A, B;
	int temp=0, n, x;
	cout<<"enter n:\n";
	cin>>n;
	cout<<endl<<"enter A:\n";
	while(temp++<n) {
		cin>>x;
		A.push_back(x);
	}
	temp = 0;
	cout<<endl<<"enter B:\n";
	while(temp++<n) {
		cin>>x;
		B.push_back(x);
	}
	int minB = B[0];
	for(int i=0;i<n;i++) {
		A[i] %= B[i];
		if(minB>B[i]) 
			minB = B[i];
	}
	int count = 0;
	for(int i=0;i<n;i++)
		if(A[i]>=minB) {
			count += B[i]-A[i];
			A[i] = 0;
		}
	int avg = 0;
	for(int i=0;i<n;i++)
		avg += A[i];
	avg /= n;
	int count1, count2;
	count1 = count2 = count;
	for(int i=0;i<n;i++)
		count1 += A[i]-avg<0?avg-A[i]:A[i]-avg;
	avg++;
	for(int i=0;i<n;i++)
		count2 += A[i]-avg<0?avg-A[i]:A[i]-avg;
	count = (count1>count2)?count2:count1;
	cout<<endl<<count<<endl;
	return 0;
}