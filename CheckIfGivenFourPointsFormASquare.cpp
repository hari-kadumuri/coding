#include <bits/stdc++.h>
using namespace std;

float distance(float ax, float ay, float bx, float by) {
	return (float)pow(pow(ax-bx, 2) + pow(ay-by, 2), 0.5);
}

bool ifFormASquare(float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy) {
	float dist[6];
	dist[0] = distance(ax, ay, bx, by);
	dist[1] = distance(ax, ay, cx, cy);
	dist[2] = distance(ax, ay, dx, dy);
	dist[3] = distance(bx, by, cx, cy);
	dist[4] = distance(bx, by, dx, dy);
	dist[5] = distance(cx, cy, dx, dy);
	for(int i=0;i<6;i++)
		cout<<"dist["<<i<<"] = "<<dist[i]<<endl;
	int count1 = 1, count2 = 0, idx;
	for(int i=1;i<6;i++) {
		if(dist[i]==dist[0])
			count1++;
		else
			idx = i;
	}
	for(int i=0;i<6;i++)
		if(dist[i]==dist[idx])
			count2++;
	return (count1==4 && count2==2 || count1==2 && count2==4);
}

int main(int argc, char const *argv[])
{
	int T;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-->0) {
		float ax, ay, bx, by, cx, cy, dx, dy;
		cin>>ax>>ay;
		cin>>bx>>by;
		cin>>cx>>cy;
		cin>>dx>>dy;
		cout<<ifFormASquare(ax, ay, bx, by, cx, cy, dx, dy);
	}
	return 0;
}