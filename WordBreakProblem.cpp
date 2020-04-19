#include <bits/stdc++.h>
using namespace std;

bool contains(string str, string dict[], int size) {
	for(int i=0;i<size;i++)
		if(dict[i]==str) return true;
	return false;
}

// function that uses trie to solve
struct node {
	char val = '-';
	bool flag = false;
	node* next[26] = {NULL};
};

node* constructTrie(string dict[], int dictsize) {
	node* root = new node;
	root->flag = true;
	for(int i=0;i<dictsize;i++) {
		node* p = root;
		for(int j=0;j<dict[i].size();j++) {
			if(!(p->next)[dict[i][j]-'a']) {
				(p->next)[dict[i][j]-'a'] = new node;
				(p->next)[dict[i][j]-'a']->val = dict[i][j];
			}
			if(j==dict[i].size()-1) (p->next)[dict[i][j]-'a']->flag = true;
			p = (p->next)[dict[i][j]-'a'];
		}
	}
	return root;
}

bool traverseTrie(string str, node* root, int i) {
	cout<<i<<": "<<endl;
	if(i>=str.size()) return true;
	if(!(root->next)[str[i]-'a']) return false;
	cout<<"comparing "<<str[i]<<" and "<<(root->next)[str[i]-'a']->val<<endl;
	if(i==str.size()-1) return (root->next)[str[i]-'a']->flag;
	return traverseTrie(str, (root->next)[str[i]-'a'], i+1);
}

void inOrderPrintTrie(node* root, int level) {
	if(!root) return;
	for(int i=0;i<level;i++)
		cout<<"\t|";
	cout<<root->val<<endl;
	for(int i=0;i<26;i++)
		inOrderPrintTrie((root->next)[i], level+1);
}

void deleteTrie(node* root) {
	if(!root) return;
	for(int i=0;i<26;i++)
		deleteTrie((root->next)[i]);
	delete root;
}

// function that uses dp to solve
bool checkIfValidDP(string str, string dict[], int i, int j, int dictsize) {
	bool flag[str.size()+1];
	memset(flag, false, sizeof(flag));
	int size = str.size();
	flag[size] = true;
	for(int i=size-1;i>=0;i--)
		for(int j=1;j<=size-i;j++)
			flag[i] = flag[i] || (contains(str.substr(i, j), dict, dictsize) && flag[i+j]);
	return flag[0];
}

int main(int argc, char const *argv[])
{
	string dict[12] = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
	string str = "ilikesamsung";
	cout<<(checkIfValidDP(str, dict, 0, str.length(), 12)?"yes":"no")<<endl;
	return 0;
}