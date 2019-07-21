#include<stdio.h>

/*typedef struct _node {
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

int hasPathSum(node* T, int k) {
    node* x = T;
    if(x) {
        if(hasPathSum(T->l, k-x->key) || hasPathSum(T->r, k-x->key))
            return 1;
        else
            return 0;
    }
    if(k==0)
        return 1;
    else
        return 0;
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

    int k;
    printf("enter k :\n");
    scanf("%d", &k);
    //checking if there is a path having value k
    printf("\n%d", hasPathSum(T, k));

    //Tree can be freed by using post-order traversal
    freetree(T);
    return 0;
}
*/
