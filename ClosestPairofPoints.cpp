#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool compareX(pair<int, int> a, pair<int, int> b) {
	if(a.first>b.first) return false;
	else if(a.first==b.first) return a.second<b.second;
	return true;
}

bool compareY(pair<int, int> a, pair<int, int> b) {
	if(a.second>b.second) return false;
	else if(a.second==b.second) return a.first<b.first;
	return true;
}

double distance(pair<int, int> a, pair<int, int> b) {
	return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

double combine(vector<pair<int, int>> xsort, vector<pair<int, int>> ysort, int mid, double d) {
	double mindist = INT_MAX;
	for(int i=0;i<ysort.size();i++) {
		if(abs(xsort[mid].first-ysort[i].first)<=d) {
			for(int j=i+1;j<i+8 && j<ysort.size();j++) {
				mindist = min(mindist, distance(ysort[i], ysort[j]));
			}
		}
	}
	return mindist;
}

double midDistance(vector<pair<int, int>> xsort, vector<pair<int, int>> ysort, int l, int r) {
	if(l>=r) return INT_MAX;
	else if(l==r-1)
		return distance(xsort[l], xsort[r]);
	int mid = (l+r)/2;
	double d = min(midDistance(xsort, ysort, l, mid), midDistance(xsort, ysort, mid+1, r));
	return min(combine(xsort, ysort, mid, d), d);
}

int main(int argc, char const *argv[]) {
	int n; cin>>n;
	vector<pair<int, int>> points, xsort, ysort;
	for(int i=0;i<n;i++) {
		pair<int, int> p;
		cin>>p.first>>p.second;
		points.push_back(p);
	}
	// creating x sorted array
	sort(points.begin(), points.end(), compareX);
	for(int i=0;i<n;i++)
		xsort.push_back(points[i]);
	// creating y sorted array
	sort(points.begin(), points.end(), compareY);
	for(int i=0;i<n;i++)
		ysort.push_back(points[i]);
	cout<<"x-sorted: ";
	for(int i=0;i<n;i++)
		cout<<"("<<xsort[i].first<<", "<<xsort[i].second<<") ";
	cout<<"\ny-sorted: ";
	for(int i=0;i<n;i++)
		cout<<"("<<ysort[i].first<<", "<<ysort[i].second<<") ";
	cout<<"\nMinimum distance = "<<midDistance(xsort, ysort, 0, n-1)<<endl;
	return 0;
}