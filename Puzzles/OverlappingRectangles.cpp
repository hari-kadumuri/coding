#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, x1, y1, x2, y2, x3, y3, x4, y4;
	cin>>T;
	while(T-- >0) {
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		// two rectangles overlapp when atleast one of the points of first rectangle lie entirely in the other rectangle
		if(x3<=x1 && x4>x1 && y3>=y1 && y4<y1) // if topleft corner of first rectangle lies in second rectangle
			cout<<1;
		else if(x3<x2 && x4>=x2 && y3>=y1 && y4<y1)
			cout<<1;
		else if(x3<=x1 && x4>x1 && y4<=y2 && y3<y2)
			cout<<1;
		else if(x3<x2 && x4>=x2 && y4<=y2 && y3<y2)
			cout<<1;
		// checking if atleast one point corner pointn of second rectangle lies in first rectangle
		else if(x1<=x3 && x2>x3 && y1>=y3 && y2<y3) // if topleft corner of first rectangle lies in second rectangle
			cout<<1;
		else if(x1<x4 && x2>=x4 && y1>=y3 && y2<y3)
			cout<<1;
		else if(x1<=x3 && x2>x3 && y2<=y4 && y1<y4)
			cout<<1;
		else if(x1<x4 && x2>=x4 && y2<=y4 && y1<y4)
			cout<<1;
		else
			cout<<0;
		cout<<endl;
	}
	return 0;
}