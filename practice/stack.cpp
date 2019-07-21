#include<iostream>
using namespace std;
#define max 5
int S[max];
int top = -1;

class Stack {
public:
    public Stack() {
    }
    int isempty() {
        if(top<0)
            return 1;
        else
            return 0;
    }

    int isfull() {
        if(top>=max-1)
            return 1;
        else
            return 0;
    }

    void pop() {
        if(isempty())
            cout<<"\nStack is empty. Further popping is not possible...!!";
        else
            top--;
    }

    void push(int x) {
        if(isfull())
            cout<<"\nStack is full. Further pushing is not possible...!!";
        else {
            top++;
            S[top] = x;
        }
    }

    int getTop() {
        return S[top];
    }

    void getStackState() {
        if(isempty())
            cout<<"\nStack is empty...!!";
        else if(isfull())
            cout<<endl<<"Stack is full...!!";
        else
            cout<<"\nStack is not empty and not full...!!";
    }

    void printStack() {
        cout<<endl<<"Stack :\t";
        while(!isempty()) {
            cout<<getTop()<<"\t";
            pop();
        }
    }
};

int main() {
    Stack stck = new Stack();
    stck.push(5);
    stck.push(7);
    stck.push(8);
    stck.push(11);
    stck.pop();
    stck.getStackState();
    stck.printStack();
    return 0;
}
