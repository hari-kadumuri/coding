#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int reconvert(string s) {
    int n = 0;
    for(int i=0;i<s.size();i++) {
        if('0'<=s[i] && s[i]<='9')
            n = n*62+52+s[i]-'0';
        else if('a'<=s[i] && s[i]<='z')
            n = n*62+s[i]-'a';
        else
            n = n*62+26+s[i]-'A';

    }
    return n;
}

string convert(int n) {
    string s;
    while(n) {
        int x = n%62;
        if(x<26)
            s.push_back('a'+x);
        else if(x<52)
            s.push_back('A'+x-26);
        else
            s.push_back('0'+x-52);
        n = n/62;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main() {
	int T; cin>>T;
	while(T-- >0) {
	    int n;
	    cin>>n;
	    string s = convert(n);
	    cout<<s<<endl;
	    n = reconvert(s);
	    cout<<n<<endl;
	}
	return 0;
}