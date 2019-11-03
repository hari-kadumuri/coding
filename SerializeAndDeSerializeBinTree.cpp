#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

Node* modDeserialize(vector<int> &A, int* idx) {
    if(A[*idx]==-1)
        return NULL;
    Node* newnode = new Node;
    newnode->data = A[*idx];
    cout<<"at newnode->data = "<<newnode->data<<endl;
    (*idx)++;
    cout<<"calling left, idx = "<<*idx<<endl;
    newnode->left = modDeserialize(A, idx);
    *idx = *idx+1;
    cout<<"calling right, idx = "<<*idx<<endl;
    newnode->right = modDeserialize(A, idx);
    return newnode;
}

Node* deSerialize(vector<int> &A)
{
   //Your code here
//   for(int i=0;i<A.size();i++) cout<<A[i]<<" ";
//   return NULL;
    if(A.size()==0 || A[0]==-1)
        return NULL;
    int idx = 0;
    Node* x = modDeserialize(A, &idx);
    return x;
}

void inorderPrint(Node* root, int level) {
	if(!root) return;
	for(int i=0;i<level;i++)
		cout<<"\t"	;
	cout<<root->data<<endl;
	inorderPrint(root->left, level+1);
	inorderPrint(root->right, level+1);
}

int main(int argc, char const *argv[])
{
	int n = 13, i = 0;
	vector<int> a;
	a.push_back(20);
	a.push_back(8);
	a.push_back(4);
	a.push_back(-1);
	a.push_back(-1);
	a.push_back(12);
	a.push_back(10);
	a.push_back(-1);
	a.push_back(-1);
	a.push_back(14);
	a.push_back(-1);
	a.push_back(-1);
	a.push_back(-1);
	Node* root = deSerialize(a);
	cout<<"printing tree:\n";
	inorderPrint(root, 0);
	return 0;
}