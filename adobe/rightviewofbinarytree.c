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

int findHeightofTree(node* T) {
    int l,r;
    if(T==NULL)
        return -1;
    if(T->l==NULL && T->r==NULL)
        return 0;
    else if(T->l==NULL && T->r)
        return 1+findHeightofTree(T->r);
    else if(T->r==NULL && T->l)
        return 1+findHeightofTree(T->l);
    else  {
        l = findHeightofTree(T->l);
        r = findHeightofTree(T->r);
        return 1+(l>r?l:r);
    }
}

void fillarray(node* T, int* idxarray, int level) {
    if(T) {
        idxarray[level] = T->key;
        fillarray(T->l, idxarray, level+1);
        fillarray(T->r, idxarray, level+1);
    }
}

void rightviewprintoftree(node* T) {
    int h, i, *idxarray;
    if(T) {
        h = findHeightofTree(T);
        h++;
        idxarray = (int*)malloc(h*sizeof(int));
        fillarray(T, idxarray, 0);
        printf("\nHeight of the tree = %d", h-1);
        printf("\nRight View of Binary Tree :  ");
        for(i=0;i<h;i++)
            printf("%d  ", idxarray[i]);
    }
    free(idxarray);
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

    rightviewprintoftree(T);
    //Tree can be freed by using post-order traversal
    freetree(T);
    return 0;
}
*/
