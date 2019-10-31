#include <iostream>
using namespace std;
#include <bits/stdc++.h>

string getLPS(string s) {
    int prelen = 1, len = 0, i, j, flag = 0, i1 = 0, j1 = 0;
    for(i=1;i<s.size();i++) {
        cout<<"at i = "<<i<<" / "<<s[i]<<" j = "<<j<<" len = "<<len<<" i1 = "<<i1<<" j1 = "<<j1<<" prelen = "<<prelen<<" len = "<<len<<" flag = "<<flag<<endl;
        if(i-2>-1 && s[i]==s[i-2] && flag==0) {
            j = i-3;
            len += 3;
            flag = 1;
        }
        else if(s[i]==s[i-1] && flag==0) {
            j = i-2;
            len += 2;
            flag = 1;
        }
        else if(flag) {
            if(j>-1) {
                if(s[j]==s[i]) {
                    len += 2;
                    j--;
                }
                else {
                    if(len>prelen) {
                        prelen = len;
                        i1 = i-1;
                        j1 = j+1;
                    }
                    flag = 0;
                    len = 0;
                    i--;
                }
            }
            else {
                if(len>prelen) {
                    prelen = len;
                    i1 = i-1;
                    j1 = 0;
                }
                flag = 0;
                len = 0;
                i--;
            }
        }
    }
    if(len>prelen) {
        i1 = s.size()-1;
        j1 = j+1;
    }
    string ret;
    for(i=j1;i<=i1;i++)
        ret.push_back(s[i]);
    return ret;
}

int main() {
	//code
	int T;
	cin>>T;
	while(T-- >0) {
	    string s;
	    cin>>s;
	    cout<<getLPS(s)<<endl;
	}
	return 0;
}