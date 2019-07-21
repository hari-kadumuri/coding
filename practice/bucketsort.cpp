#include<iostream>
using namespace std;

typedef struct _node {
    int a;
    struct _node* next;
}node;
typedef struct _node* nodeptr;

void bucketinsert(nodeptr* B, int val) {
    nodeptr headptr = B[(int)(10*val)];
    cout<<endl<<(int)(10*val);
    while(headptr->next)
        headptr = headptr->next;
    nodeptr newnode = new node;
    headptr->next = newnode;
    newnode->a = val;
    newnode->next = NULL;
    cout<<newnode->next;
}

void sortlinkedlist(nodeptr head) {
    int i=0,n=0;
    float max, temp;
    nodeptr x = head;
    cout<<"hii";
    while(x->next) {
        n++;
        cout<<"in the n++ loop hii\n";
    }
    cout<<"hii";
    for(i=0;i<n;i++) {
        x = head->next;
        while(x->next)
            if(x->a>x->next->a) {
                temp = x->a;
                x->a = x->next->a;
                x->next->a = temp;
            }
    }
    cout<<"hii";
}

void bucketsort(float *a, int n) {
    nodeptr B[10];
    cout<<"hii";
    for(int i=0;i<10;i++) {
        B[i] = new node;
        B[i]->next = NULL;
    }
    cout<<"hii";
    for(int i=0;i<n;i++)
        bucketinsert(B, a[i]);
    cout<<"hii";
    for(int i=0;i<10;i++)
        sortlinkedlist(B[i]);
    cout<<"sorted complete hii";
    int j=0, i=0;
    nodeptr head = B[j]->next;
    while(i<n) {
        if(head)
            a[i++] = head->a;
        else
            head = B[j++]->next;
    }
}

int main() {
    int n;
    cout<<"Enter n value :\n";
    cin>>n;
    float a[n];
    cout<<"Enter array values :\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    bucketsort(a, n);
    cout<<"\nBucket Sorted Array :\t";
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\t";
    delete []a;
    return 0;
}
