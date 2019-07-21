#include<stdio.h>
#include<stdlib.h>
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

void inorderprinttree(node* T) {
    node* x = T;
    if(x) {
        inorderprinttree(x->l);
        printf("%d ", x->key);
        inorderprinttree(x->r);
    }
}

int ifidentical(node* T1, node* T2) {
    node* x = T1, *y = T2;
    if(x&&y) {
        if(x->key==y->key && ifidentical(x->l, y->l) && ifidentical(x->r, y->r))
            return 1;
        return 0;
    }
    else if(x==NULL && y)
        return 0;
    else if(x && y==NULL)
        return 0;
    else
        return 1;
}

int main() {
    int m,n;
    int i, temp;
    nodeptr T1 = NULL, T2 = NULL;
    printf("enter m :\n");
    scanf("%d", &m);
    printf("enter n :\n");
    scanf("%d", &n);
    printf("\nenter tree1 :\n");
    for(i=0;i<m;i++) {
        scanf("%d", &temp);
        T1 = bstinsert(T1, temp);
    }

    printf("\nenter tree2 :\n");
    for(i=0;i<n;i++) {
        scanf("%d", &temp);
        T2 = bstinsert(T2, temp);
    }

    printf("\n%d", ifidentical(T1, T2));

    //Tree can be freed by using post-order traversal
    freetree(T1);
    freetree(T2);
    return 0;
}
*/
