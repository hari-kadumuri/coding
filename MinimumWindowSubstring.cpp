#include <bits/stdc++.h>
#include <iostream>
using namespace std;

pair<int, int> func(string s, string t) {
	unordered_set<char> setT, setCheck;
	unordered_map<char, int> countS;
	for(auto x: t)
		setT.insert(x);
	int l = 0, r = 0;
	for(int i=0;i<s.size();i++) {
		if(setT.find(s[i])!=setT.end()) {
			l = i;
			break;
		}
	}
	for(int i=0;i<s.size();i++) {
		if(setT.find(s[i])!=setT.end()) {
			setCheck.insert(s[i]);
			countS[s[i]]++;
		}
		if(setCheck.size()==setT.size()) {
			r = i;
			break;
		}
	}
	int curr_min = r-l+1;
	int l1 = l, r1 = r;
	while(l<s.size()) {
		l++;
		countS[s[l1]]--;
		while(l<s.size() && setT.find(s[l])==setT.end())
			l++;
		cout<<"l1 = "<<l1<<" l = "<<l<<endl;
		if(l<s.size())
			countS[s[l]]++;
		else
			break;
		int tempr = r;
		while(countS[s[l1]]==0) {
			r++;
			if(r<s.size()) {
				if(setT.find(s[r])!=setT.end()) {
					countS[s[r]]++;
					tempr = r;
				}
			}
			else {
				r = tempr;
				break;
			}
		}
		cout<<"r1 = "<<r1<<" r = "<<r<<endl;
		if(countS[s[l1]]==0) {
			cout<<"break 2"<<endl;
			break;
		}
		if(r-l+1<curr_min) {
			cout<<"\nl1 = "<<l1<<" r1 = "<<r1<<endl;
			curr_min = r-l+1;
			l1 = l;
			r1 = r;
		}
		cout<<"curr_min = "<<curr_min<<endl;
	}
	l++;
	countS[s[l1]]--;
	while(l<s.size() && setT.find(s[l])==setT.end())
		l++;
	cout<<"l1 = "<<l1<<" l = "<<l<<endl;
	if(l<s.size())
		countS[s[l]]++;
	if(r-l+1<curr_min) {
		cout<<"\nl1 = "<<l1<<" r1 = "<<r1<<endl;
		curr_min = r-l+1;
		l1 = l;
		r1 = r;
	}
	cout<<"curr_min = "<<curr_min<<endl;
	return make_pair(l1, r1);
}

int main(int argc, char const *argv[])
{
	string s, t;
	cin>>s>>t;
	cout<<"string s:\n";
	for(int i=0;i<s.size();i++) {
		cout<<s[i]<<" -> "<<i<<endl;
	}
	cout<<"string t:\n";
	for(int i=0;i<t.size();i++) {
		cout<<t[i]<<" -> "<<i<<endl;
	}
	pair<int, int> p = func(s, t);
	cout<<"\nrange is "<<p.first<<" "<<p.second<<endl;
	for(int i=p.first;i<=p.second;i++)
		cout<<s[i];
	cout<<endl;
	return 0;
}