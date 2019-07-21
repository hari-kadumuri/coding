#include<stdio.h>

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

void fillarray(nodeptr T, int n, int* a, int* count) {
    nodeptr x = T;
    if(x) {
        fillarray(x->l, n, a, count);
        a[*count] = x->key;
        *count = *count+1;
        fillarray(x->r, n, a, count);
    }
}

int checkifbst(nodeptr T, int n) {
    int a[n];
    int* countptr, count = 0;
    countptr = &count;
    fillarray(T, n ,a, countptr);
    int i;
    for(i=1;i<n;i++) {
        if(a[i]<a[i-1])
            return 0;
    }
	free(a);
    free(count);
    return 1;
}

void freetree(node* T) {
    node* x = T;
    if(x) {
        freetree(x->l);
        freetree(x->r);
        free(x);
    }
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

    //constructing duplicate tree
    nodeptr T1 = (nodeptr)malloc(sizeof(node));
    T1->key = 5;
    node* Tl = (node*)malloc(sizeof(node));
    node* Tr = (node*)malloc(sizeof(node));
    Tl->key = 56;
    Tr->key = 10;
    Tl->l = Tl->r = Tr->l = Tr->r = NULL;
    T1->l = Tl;
    T1->r = Tr;
    //check if the given tree is bst using in-order traversal. pre-order traversal results in sorted output
    printf("\nchecking if given tree is bst : ");
    printf("%d", checkifbst(T, n));

    //checking if T1 is a bst
    printf("\nchecking if T1 is bst : ");
    printf("%d", checkifbst(T1, 3));

    //Tree can be freed by using post-order traversal
    freetree(T);
    return 0;
}
