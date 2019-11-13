#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int premax = -1, count = 0;
    bool exist[256] = {false};
    int j = 0, i=0;
    while(j<s.size()) {
        if(exist[s[j]]) {
            if(count>premax)
                premax = count;
            while(exist[s[j]]) {
                exist[s[i]] = false;
                i++;
                count--;
            }
        }
        count++;
        exist[s[j]] = true;
        j++;
    }
    return max(premax, count);
}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}