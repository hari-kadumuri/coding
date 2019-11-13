#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string getEvenPalindrome(string s) {
    int maxval = -1, i1 = s.size(), j1 = -1;
    for(int i=0;i<s.size();i++) {
        int count = 0;
        for(int j=i-1;j>-1 && 2*i-j-1<s.size();j--) {
            if(s[j]==s[2*i-j-1])
                count += 2;
            else
                break;
        }
        if(count>maxval) {
            maxval = count;
            i1 = i-count/2;
            j1 = i+count/2-1;
        }
    }
    string ret;
    for(int k=i1;k<=j1 && i1<=j1;k++)
        ret.push_back(s[k]);
    return ret;
}

string getOddPalindrome(string s) {
    int maxval = -1, i1 = 0, j1 = 0;
    for(int i=0;i<s.size();i++) {
        int count = 1;
        for(int j=i-1;j>-1 && 2*i-j<s.size();j--) {
            if(s[j]==s[2*i-j])
                count += 2;
            else
                break;
        }
        if(count>maxval) {
            maxval = count;
            i1 = i-count/2;
            j1 = i+count/2;
        }
    }
    string ret;
    for(int k=i1;k<=j1;k++)
        ret.push_back(s[k]);
    return ret;
}

string getLPS(string s) {
    string evenS = getEvenPalindrome(s);
    string oddS = getOddPalindrome(s);
    cout<<evenS<<endl;
    cout<<oddS<<endl;
    cout<<"returned"<<endl;
    return (evenS.size()>oddS.size()?evenS:oddS);
}

int main() {
	//code
	int T;
	cin>>T;
	while(T-- >0) {
	    string s;
	    cin>>s;
        for(int i=0;i<s.size();i++)
            cout<<i<<" -> "<<s[i]<<endl;
	    cout<<getLPS(s)<<endl;
	}
	return 0;
}