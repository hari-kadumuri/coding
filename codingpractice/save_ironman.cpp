#include<iostream>
#include<string.h>
using namespace std;
class ironman {
private:
    string s;
public:
     ifpalindrome(string s) {
        this->s = s;
        int n = s.length();
        int i=0,j=n-1;
        while(i<j) {
            if(!(65<=s[i]&&s[i]<=90 || 97<=s[i]&&s[i]<=122))
                i++;
            else if(!(65<=s[j]&&s[j]<=90 || 97<=s[j]&&s[j]<=122))
                j--;
            else if((65<=s[i]&&s[i]<=90 || 97<=s[i]&&s[i]<=122) && (65<=s[j]&&s[j]<=90 || 97<=s[j]&&s[j]<=122)) {
                if(!(s[i]==s[j] || s[i]==s[j]+32 || s[j]==s[i]+32)) {
                    return 0;
                }
                i++;
                j--;
            }
        }
        return 1;
    }
};
int main() {
    ironman ir;
    string s;
    cout<<"enter string :\n";
    //cout<<(int)'/';
    cin>>s;
    cout<<endl<<ir.ifpalindrome(s);
    return 0;
}
