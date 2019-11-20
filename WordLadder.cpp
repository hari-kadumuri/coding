#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getDiff(string x, string y) {
    int diff = 0;
    for(int i=0;i<x.size();i++)
        diff += (x[i]==y[i]?0:1);
    return diff;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, long long int> dist;
    wordList.push_back(beginWord);
    long long int diff[wordList.size()][wordList.size()];
    for(int i=0;i<wordList.size();i++)
        for(int j=0;j<wordList.size();j++)
            diff[i][j] = getDiff(wordList[i], wordList[j]);
    for(auto x: wordList)
        dist[x] = (x==endWord?0:LONG_MAX);
    for(auto x: wordList)
        cout<<"x = "<<x<<" = "<<dist[x]<<endl;
    for(int i=0;i<wordList.size();i++) {
        if(wordList[i]==endWord)
            continue;
        long long int minval = LONG_MAX;
        for(int j=0;j<wordList.size();j++)
            minval = min(minval, diff[i][j]+dist[wordList[j]]);
        dist[wordList[i]] = minval;
    }
    for(auto x: wordList)
        cout<<"x = "<<x<<" = "<<dist[x]<<endl;
    for(int i=0;i<wordList.size();i++) {
        if(wordList[i]==endWord)
            continue;
        long long int minval = LONG_MAX;
        for(int j=0;j<wordList.size();j++)
            minval = min(minval, diff[i][j]+dist[wordList[j]]);
        dist[wordList[i]] = minval;
    }
    for(auto x: wordList)
        cout<<"x = "<<x<<" = "<<dist[x]<<endl;
    return dist[beginWord];
}

int main(int argc, char const *argv[])
{
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    cout<<ladderLength("hit", "cog", wordList)<<endl;
    return 0;
}

 // for(int i=0;i<wordList.size();i++)
    //     for(int j=0;j<wordList.size();j++)
    //         cout<<"distance between "<<wordList[i]<<" and "<<wordList[j]<<" = "<<diff[i][j]<<endl;

// long long int minval = LONG_MAX;
    // cout<<"wordList[0] = "<<wordList[0]<<endl;
    // for(int j=0;j<wordList.size();j++) {
    //     cout<<"comparing with "<<wordList[j]<<endl;
    //     cout<<"minval = "<<minval<<" expected dist = "<<diff[0][j]+dist[wordList[j]]<<endl;
    //     minval = min(minval, diff[0][j]+dist[wordList[j]]);
    //     dist[wordList[0]] = minval;
    //     cout<<"updated min val = "<<minval<<endl<<endl;
    // }
    // for(int j=0;j<wordList.size();j++) {
    //     cout<<"comparing with "<<wordList[j]<<endl;
    //     cout<<"minval = "<<minval<<" expected dist = "<<diff[0][j]+dist[wordList[j]]<<endl;
    //     minval = min(minval, diff[0][j]+dist[wordList[j]]);
    //     dist[wordList[0]] = minval;
    //     cout<<"updated min val = "<<minval<<endl<<endl;
    // }
    // cout<<"final distance = "<<dist[wordList[0]]<<endl;