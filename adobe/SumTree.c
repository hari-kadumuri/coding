#include<stdio.h>
/*
typedef struct _node {
    int key;
    struct _node* l, *r;
}node;

typedef node* nodeptr;

nodeptr bstinsert(nodeptr T, int key) {
    nodeptr p = NULL, q = T;

    while(q) {
        p = q;
        if(q->key>key)
            q = q->l;
        else if(q->key<key)
            q = q->r;
        else
            break;

    }
    q = (nodeptr)malloc(sizeof(node));
    q->key = key;
    q->l = q->r = NULL;
    if(p==NULL)
        return q;
    else {
        if(key<p->key)
            p->l = q;
        else
            p->r = q;
    }
    return T;
}

void freetree(node* T) {
    node* x = T;
    if(x) {
        freetree(x->l);
        freetree(x->r);
        free(x);
    }
}

int getSumTree(node* T) {
    if(T == NULL)
        return 0;
    return T->key+getSumTree(T->l)+getSumTree(T->r);
}

int checkifSumTree(node* T) {
    if(T==NULL)
        return 1;
    if(T->key == getSumTree(T)/2)
        return 1;
    return 0;
}

int main() {
    int n;
    int i, temp;
    nodeptr T = NULL;
    printf("enter n :\n");
    scanf("%d", &n);
    printf("\nenter elements :\n");
    for(i=0;i<n;i++) {
        scanf("%d", &temp);
        T = bstinsert(T, temp);
    }

    printf("\n%d", checkifSumTree(T));
    //Tree can be freed by using post-order traversal
    freetree(T);
    return 0;
}
*/
