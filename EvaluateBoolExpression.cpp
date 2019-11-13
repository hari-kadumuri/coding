#include <iostream>
using namespace std;

bool evaluate(string s) {
    bool x;
    if(s[1]=='A')
        x = s[0] & s[2];
    if(s[1]=='B')
        x = s[0] | s[2];
    if(s[1]=='C')
        x = s[0] ^ s[2];
    for(int i=1;i<s.size();i += 2) {
        cout<<i<<" -> "<<s[i]<<endl;
    }
    for(int i=3;i<s.size();i += 2) {
        if(s[i]=='A') {
           x  = x & (s[i+1]-'0');
        }
        if(s[i]=='B') {
           x  = x | (s[i+1]-'0');
        }
        if(s[i]=='C') {
           x  = x ^ (s[i+1]-'0');
        }
        cout<<"x at i = "<<i<<": "<<x<<endl;
    }
    return x;
}

int main() {
	int T; cin>>T;
	while(T-- >0) {
	    string s;
	    cin>>s;
	    cout<<evaluate(s)<<endl;
	}
	return 0;
}