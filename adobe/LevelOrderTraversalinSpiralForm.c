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
    if(T==NULL)
        return -1;
    if(T->l==NULL && T->r==NULL)
        return 0;
    else if(T->l==NULL && T->r)
        return 1+findHeightofTree(T->r);
    else if(T->r==NULL && T->l)
        return 1+findHeightofTree(T->l);
    else
        return 1+findHeightofTree(T->r)+findHeightofTree(T->l);

}

void fillprintarray(node* T, int** p, int* idxarray, int level) {
    if(T) {
        p[level][idxarray[level]] = T->key;
        idxarray[level]++;
        fillprintarray(T->l, p, idxarray, level+1);
        fillprintarray(T->r, p, idxarray, level+1);
    }
}

void LevelOrderSpiralPrintTree(node* T) {
    int h, i, j, *idxarray;
    if(T) {
        h = findHeightofTree(T);
        h++;
        idxarray = (int*)malloc(h*sizeof(int));
        int **p = (int**)malloc(h*sizeof(int*));
        for(i=0;i<h;i++) {
            p[i] = (int*)malloc(pow(2, h-1)*sizeof(int));
            idxarray[i] = 0;
        }
        fillprintarray(T, p, idxarray, 0);
        //printing spirally
        for(i=0;i<=h;i++) {
            if(i%2==0) {
                for(j=idxarray[i]-1;j>=0;j--)
                    printf("%d  ", p[i][j]);
            }
            else {
                for(j=0;j<idxarray[i];j++)
                    printf("%d  ", p[i][j]);
            }
        }
    }
    free(idxarray);
    for(i=0;i<h;i++)
        free(p[i]);
    free(p);
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

    LevelOrderSpiralPrintTree(T);
    //Tree can be freed by using post-order traversal
    freetree(T);
    return 0;
}
*/
