#include <iostream>
using namespace std;

struct node {
	int val, h;
	node *l, *r, *p;
};

node* createNode(int key) {
	node* newnode = new node;
	newnode->val = key;
	newnode->l = NULL;
	newnode->r = NULL;
	newnode->p = NULL;
	newnode->h = 0;
	return newnode;
}

int getHeight(node* root) {
	if(!root)
		return -1;
	return root->h;
}

void leftRotate(node* z) {
	node* right = z->r;
	z->r = right->l;
	right->l = z;
	right->p = z->p;
	if(z->p->l == z)
		z->p->l = right;
	else
		z->p->r = right;
	z->p = right;
}

void rightRotate(node* z) {
	node* left = z->l;
	z->l = left->r;
	left->r = z;
	left->p = z->p;
	if(z->p->l == z)
		z->p->l = left;
	else
		z->p->r = left;
	z->p = left;
}

node* BST_Insert(node* root, int key) {
	if(!root) {
		node* x = createNode(key);
		return x;
	}
	if(root->val==key)
		return root;
	else if(root->val>key)
		root->l = AVL_Insert(root->l, key);
	else
		root->r = AVL_Insert(root->r, key);
	root->h = 1+max(getHeight(root->r), getHeight(root->l));
	return root;
}

node* AVL_Insert(node* root, int key) {
	node* x = BST_Insert(root, key);
	return root;
}

void printTree(node* root, int level) {
	if(!root) return;
	for(int i=0;i<level;i++)
		cout<<"\t";
	cout<<root->val<<endl;
	printTree(root->l, level+1);
	printTree(root->r, level+1);
}

int main(int argc, char const *argv[])
{
	node* root = AVL_Insert(NULL, 10);
	printTree(root, 0);
	root = AVL_Insert(root, 20);
	printTree(root, 0);
	root = AVL_Insert(root, 30);
	root = AVL_Insert(root, 5);
	root = AVL_Insert(root, 7);
	root = AVL_Insert(root, 3);
	printTree(root, 0);
	return 0;
}