#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, d, m, y; cin>>T;
	while(T-- >0) {
		cin>>d>>m>>y;
		// This algorithm uses Zeller's Rule to find the day which is f = k + [(13*m-1)/5] + D + [D/4] + [C/4] - 2*C
		// where [.] denotes the greatest integer function
		int k = d;
		m = (m+10)%12;
		int D = (m==11 || m==12)?y%100-1:y%100;
		int C = y/100;
		int f = k + (int)((13*m-1)/5) + D + (int)(D/4) + (int)(C/4) - 2*C;
		f %= 7; f = (f<0)?f+7:f;
		switch(f) {
			case 0:
				cout<<"Sunday";
				break;
			case 1:
				cout<<"Monday";
				break;
			case 2:
				cout<<"Tuesday";
				break;
			case 3:
				cout<<"Wednesday";
				break;
			case 4:
				cout<<"Thursday";
				break;
			case 5:
				cout<<"Friday";
				break;
			case 6:
				cout<<"Saturday";
				break;
		}
		cout<<endl;
	}
	return 0;
}