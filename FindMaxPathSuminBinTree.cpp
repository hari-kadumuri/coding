// C/C++ program to find maximum path sum in Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// A utility function to allocate a new node 
struct Node* newNode(int data) 
{ 
	struct Node* newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return (newNode); 
} 

int max(int a, int b) {
    return (a>b?a:b);
}

int* modfindMaxSum(Node* root) {
    if(root==NULL) {
        int *x = new int[2];
        x[0] = 0;
        x[1] = 0;
        return x;
    }
    int maxsum = 0, *a = modfindMaxSum(root->left), *b = modfindMaxSum(root->right);

    int *x = new int[2];
    x[0] = max(a[0], max(b[0], root->data+a[1]+b[1]));
    x[1] = max(root->data, max(a[1]+root->data, b[1]+root->data));
    delete[] a, b;
    return x;
}

int findMaxSum(Node* root) {
    int *x = modfindMaxSum(root);
    int a = max(x[0], x[1]);
    delete[] x;
    return a;
}

// Driver program 
int main(void) 
{ 
	struct Node *root = newNode(10); 
	root->left	 = newNode(2); 
	root->right	 = newNode(10); 
	root->left->left = newNode(20); 
	root->left->right = newNode(1); 
	root->right->right = newNode(-25); 
	root->right->right->left = newNode(3); 
	root->right->right->right = newNode(4); 
	cout << "Max path sum is " << findMaxSum(root); 
	return 0; 
} 














