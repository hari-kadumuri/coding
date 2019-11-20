#include <bits/stdc++.h>
using namespace std;

bool ifMatch(char open, char closed) {
    if(open=='(' && closed==')' || open=='{' && closed=='}' || open=='[' && closed==']')
        return true;
    return false;
}

bool isValid(string s) {
    stack<char> p;
    int i=0;
    while(i<s.size()) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            p.push(s[i]);
        else {
            if(!p.empty() && ifMatch(p.top(), s[i]))
                p.pop();
            else
                return false;
        }
        i++;
        if(p.empty())
            cout<<"hello"<<endl;
        else
            cout<<p.top()<<endl;
    }
    if(p.empty())
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    cout<<isValid("()");
    return 0;
}