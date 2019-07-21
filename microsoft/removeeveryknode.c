#include<stdio.h>
/*
struct _node {
    int key;
    struct _node* next;
};

typedef struct _node node;

void linkedlistinsert(node* head, int key) {
    node* x = head, *p;
    while(x) {
        p =x;
        x = x->next;
    }
    x = (node*)malloc(sizeof(node));
    p->next = x;
    x->next = NULL;
    x->key = key;
}

void freelnkdlist(node* head) {
    node* x = head, *p;
    while(x) {
        p = x;
        x = x->next;
        free(p);
    }
}


void printlinkedlist(node* head) {
    printf("\nreversed linked list :  ");
    if(head->next!=NULL) {
        node* x = head->next;
        while(x) {
            printf("%d  ", x->key);
            x = x->next;
        }
    }
    else {
        printf("NULL");
    }
}

int main() {
    int n;
    printf("enter n :\n");
    scanf("%d", &n);
    printf("\nenter elements :\n");
    int i, temp;
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    for(i=0;i<n;i++) {
        scanf("%d", &temp);
        linkedlistinsert(head, temp);
    }

    int k;
    printf("enter k :\n");
    scanf("%d", &k);
    node* x = head->next, *p = head;
    //removing every kth node
    for(i=1;i<=n;i++) {
        if(i%k==0) {
            p->next = x->next;
            free(x);
            x = p->next;
        }
        else {
            p = x;
            x = x->next;
        }
    }

    //printing reduced list
    printlinkedlist(head);

    freelnkdlist(head);
    return 0;
}
*/
