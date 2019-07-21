#include <iostream>
#include <cmath>
using namespace std;

double distance(int x1, int y1, int x2, int y2) {
	return pow(pow(y2-y1, 2) + pow(x2-x1, 2), 0.5);
}

bool ifperpendicular(int x1 , int y1, int x2, int y2, int x3, int y3) {
	if(x2==x3) {
		if(y1==x2)
			return true;
		else
			return false;
	}
	else if(x1==x2) {
		if(y2==y3)
			return true;
		else
			return false;
	}
	if(((y3-y2)/(x3-x2))*((y2-y1)/(x2-x1)) == -1)
		return true;
	else
		return false;
}

int main(int argc, char const *argv[])
{
	int T, x1, y1, x2, y2, x3, y3, x4, y4;
	cin>>T;
	while(T-- >0) {
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		// 3 arrangements can be possible
		double d12 = distance(x1, y1, x2, y2); double d23 = distance(x2, y2, x3, y3); double d34 = distance(x3, y3, x4, y4);
		double d41 = distance(x4, y4, x1, y1); double d13 = distance(x1, y1, x3, y3); double d24 = distance(x2, y2, x4, y4);
		// 1st arrangement is 1, 2, 3, 4 in cyclic order
		if(d12==d23 && d23==d34 && d34==d41 && ifperpendicular(x1, y1, x2, y2, x3, y3))
			cout<<"YES";
		// 2nd arrangement is 1, 2, 4, 3 in cyclic order
		else if (d12==d24 && d24==d34 && d34==d13 && ifperpendicular(x1, y1, x2, y2, x4, y4))
			cout<<"YES";
		// 3rd arrangement is 1, 3, 2, 4 in cyclic order
		else if (d13==d23 && d23==d24 && d24==d41 && ifperpendicular(x1, y1, x3, y3, x2, y2))
			cout<<"YES";
		// there is no other possible arrangement. so it is not a square
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}