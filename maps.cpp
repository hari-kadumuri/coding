#include <bits/stdc++.h>
using namespace std;

struct node {
	int x;
	int y;

};

// bool comp(node a, node b) {
// 	return (a.y>b.y?true:false);
// }

struct comp {
    bool operator()(node a, node b) {
        return a.x < b.x;
    }
};

int main(int argc, char const *argv[])
{
	// map<node, int, comp> m;
	// while(1) {
	// 	node tmp;
	// 	cin>>tmp.x>>tmp.y;
	// 	if(tmp.x==-1)
	// 		break;
	// 	m[tmp]++;
	// }
	// // for(auto x: m)
	// // 	cout<<x.first<<" occurs "<<x.second<<endl;

	// //unordered_map is same as map
	set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(2);
	s.insert(1);
	s.insert(1);
	cout<<"break\n";
	for(auto x: s)
		cout<<x<<endl;
	cout<<"position of 3 = "<<*(s.find(3))<<endl;
	*(s.find(3)) = 5;
	for(auto x: s)
		cout<<x<<endl;
	return 0;
}