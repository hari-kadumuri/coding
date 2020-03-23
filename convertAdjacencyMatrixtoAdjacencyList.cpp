#include <iostream>
using namespace std;

struct node {
	int val;
	node* next = NULL;
};

int main(int argc, char const *argv[])
{
	int n = 5;
	int matrix[n][n] = {{0, 1, 0, 0, 1}, {1, 0, 1, 1, 1}, {0, 1, 0, 1, 0},
							{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}};
	// converting adjacency matrix to adjacency list
	node list[n];
	for(int i=0;i<n;i++) {
		list[i].val = i;
		list[i].next = NULL;
		node* curr = list+i;
		for(int j=0;j<n;j++) {
			if(matrix[i][j]) {
				curr->next = new node;
				curr->next->val = j;
				curr = curr->next;
			}
		}
	}

	// printing the list
	for(int i=0;i<n;i++) {
		cout<<endl;
		node* curr = list+i;
		cout<<curr->val;
		curr = curr->next;
		while(curr) {
			cout<<" -> "<<curr->val;
			curr = curr->next;
		}
	}
	return 0;
}