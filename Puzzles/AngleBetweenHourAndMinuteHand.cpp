#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int T, h, m;
	cin>>T;
	while(T-- >0) {
		cin>>h>>m;
		m %= 60;
		cout<<h<<endl<<m<<endl;
		int hourAngle = 30*h+m/2, minuteAngle = 6*m, angle;
		if(hourAngle > minuteAngle)
			angle = hourAngle - minuteAngle;
		else if(minuteAngle > hourAngle)
			angle = minuteAngle - hourAngle;
		cout<<(angle>180?360-angle:angle)<<endl;
	}
	return 0;
}