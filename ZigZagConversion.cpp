#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {
	string ret;
    int idx = 0, row = 0;
    if(numRows==1)
    	return s;
    while(ret.size()<s.size() && row<numRows) {
        ret.push_back(s[idx]);
        cout<<"pushing "<<s[idx]<<" at "<<idx<<endl;
        if(idx+2*(numRows-row-1)<s.size() && idx+2*(numRows-1)!=idx+2*(numRows-row-1) && idx != idx+2*(numRows-row-1)) {
        	ret.push_back(s[idx+2*(numRows-row-1)]);
        	cout<<"pushing "<<s[idx+2*(numRows-row-1)]<<" at "<<idx+2*(numRows-row-1)<<endl;
        }
        idx = idx+2*(numRows-1);
        if(idx>=s.size()) {
            row++;
            idx = row;
        }
    }
    return ret;
}

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	cout<<convert(s, 5)<<endl;	
	return 0;
}