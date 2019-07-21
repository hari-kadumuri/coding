#include<iostream>
using namespace std;

typedef struct _node {
    int key;
    struct _node* next;
}node;

class graph {
public:
    void printAdjacencyListforUndirectedGraph(int v, int e, int* a, int b[]) {
        //creating adjacency list
        node** G = new node*[v];
        for(int i=0;i<v;i++) {
            G[i] = new node;
            G[i]->next = NULL;
        }
        node* p, *q;
        for(int i=0;i<e;i++) {
            p = G[a[i]];
            while(p->next != NULL)
                p=p->next;
            q = new node;
            q->key = b[i];
            q->next = NULL;
            p->next = q;

            p = G[b[i]];
            while(p->next != NULL)
                p=p->next;
            q = new node;
            q->key = a[i];
            q->next = NULL;
            p->next = q;
        }
        //printing adjacency list
        for(int i=0;i<v;i++) {
            p = G[i]->next;
            cout<<endl<<i;
            while(p != NULL) {
                cout<<" -> "<<p->key;
                p = p->next;
            }
        }
    }

    void printDependenciesforDirectedGraph(int v, int e, int* a, int *b) {
        int* T = new int[v];
        for(int i=0;i<v;i++)
            T[i] = 0;
        for(int i=0;i<e;i++) {
            T[a[i]]++;
        }
        for(int i=1;i<v;i++)
            T[i] += T[i-1];
        cout<<"\nTotal number of dependencies = "<<T[v-1];
    }
};

int main() {
    //print adjacency list
    int v, e;
    cout<<"enter v and e :\n";
    cin>>v>>e;
    int a[e], b[e];
    cout<<"enter edges :\n";
    for(int i=0;i<e;i++)
        cin>>a[i]>>b[i];
    graph G;
    G.printAdjacencyListforUndirectedGraph(v, e, a, b);
    G.printDependenciesforDirectedGraph(v, e, a, b);
    return 0;
}
