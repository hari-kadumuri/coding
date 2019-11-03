#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double findDistance(vector<pair<int, int>> &points, int i, int j) {
	double sqdist = pow(points[i].first-points[j].first, 2) + pow(points[i].second-points[j].second, 2);
	return sqrt(sqdist);
}

double findMaxDistance(vector<pair<int, int>> &points) {
	double dist = 0.0;
	int n = points.size();
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			double x = findDistance(points, i, j);
			if(x>dist)
				dist = x;
		}
	}
	return dist;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<pair<int, int>> points(n);
	for(int i=0;i<n;i++) {
		cin>>points[i].first;
		cin>>points[i].second;
	}
	cout<<findMaxDistance(points)<<endl;
	return 0;
}