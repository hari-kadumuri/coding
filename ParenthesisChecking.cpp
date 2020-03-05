// Program to read an exp and checking parenthesis syntax using linked list stack implementation
#include <bits/stdc++.h>
using namespace std;

struct node {
	char val;
	node* down;
	node() {
		this->down = NULL;
	}
	node(char c) {
		this->down = NULL;
		this->val = c;
	}
	node(node* down) {
		this->down = down;
	}
	node(char c, node* down) {
		this->down = down;
		this->val = c;
	}
};

bool isOpenBracket(char c) {
	return (c=='(' || c=='[' || c=='{');
}

bool isCompatible(char open, char closed) {
	switch(open) {
		case '(':
			return (closed==')');
			break;
		case '[':
			return (closed==']');
			break;
		case '{':
			return (closed=='}');
			break;
	}
}

node* push(node* top, char c) {
	node* newnode = new node(c, top);
	top = newnode;
	return top;
}

node* pop(node* top) {
	node* x = top;
	top = top->down;
	delete x;
	return top;
}

string evaluate(string exp) {
	node* top = NULL;
	for(int i=0;i<exp.size();i++) {
		if(isOpenBracket(exp[i])) {
			top = push(top, exp[i]);
		}
		else {
			if(isCompatible(top->val, exp[i]))
				top = pop(top);
			else
				return "no";
		}
	}
	return (top==NULL?"yes":"no");
}

int main(int argc, char const *argv[])
{
	string exp;
	cin>>exp;
	cout<<evaluate(exp)<<endl;
	return 0;
}