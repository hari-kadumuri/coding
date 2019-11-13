#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int numnodes = 0;

struct node {
	char val;
	node* left;
	node* right;
	int idx;
	node(char val) {
		this->idx = numnodes++;
		// cout<<idx<<" = "<<numnodes-1<<endl;
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

node* getATree() {
	node* root = new node('a');
	root->left = new node('b');
	root->right = new node('b');
	root->left->left = new node('c');
	root->left->left->right = new node('a');
	root->right->left = new node('a');
	root->right->left->left = new node('c');
	root->right->left->right = new node('b');
	root->right->right = new node('d');
	root->right->right->left = new node('a');
	root->right->right->right = new node('b');
	return root;
}

void modfunc(node* root, int n, vector<int> v, vector<int>& count, vector<bool>& leaf) {
	if(!root) return;
	count[root->idx]++;
	if(v[root->val-'a']!=-1)
		count[v[root->val-'a']]++;
	v[root->val-'a'] = root->idx;
	if(!root->left && !root->right)
		leaf[root->idx]=true;
	modfunc(root->left, n, v, count, leaf);
	modfunc(root->right, n, v, count, leaf);
}

void printTree(node* root, vector<int>& count, int level) {
	if(!root) return;
	for(int i=0;i<level;i++)
		cout<<"\t";
	cout<<root->idx<<" -> "<<root->val<<", "<<count[root->idx]<<endl;
	printTree(root->left, count, level+1);
	printTree(root->right, count, level+1);
}

void func(node* root, int n) {
	vector<int> v(26, -1), count(n, 0);
	vector<bool> leaf(n, false);
	modfunc(root, n, v, count, leaf);
	cout<<"Tree: format is <index -> value, number of nodes with this node as parent>"<<endl;
	printTree(root, count, 0);
	cout<<"Final Output Array:"<<endl;
	for(int i=0;i<n;i++)
		if(!leaf[i])
			cout<<i<<" -> "<<count[i]<<"\n";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	node* root = getATree();
	func(root, 11);
	cout<<numnodes<<endl;
	return 0;
}