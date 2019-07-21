#include<stdio.h>
#include<stdlib.h>
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

node* reversealinkedlist(node* head, int n) {
    node* head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    int i;
    node* x = head, *p;
    for(i=0;i<n;i++) {
        x = head;
        while(x->next) {
            p = x;
            x = x->next;
        }
        if(x == NULL)
            break;
        linkedlistinsert(head2, x->key);
        p->next = NULL;
        free(x);
    }
    return head2;
}

void printlinkedlist(node* head) {
    node* x = head->next;
    printf("\nlinked list :  ");
    while(x) {
        printf("%d  ", x->key);
        x = x->next;
    }
}

node* mergelinkedlists(node* head1, node* head2) {
    node* x = head1->next, *y = head2->next;
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    node* k = head, *p = head;
    int temp;
    while(x!=NULL && y!=NULL) {
        if(x->key < y->key) {
            temp = x->key;
            x = x->next;
        }
        else {
            temp = y->key;
            y = y->next;
        }
        p = (node*)malloc(sizeof(node));
        p->key = temp;
        k->next = p;
        p->next = NULL;
        k = p;
    }
    while(x) {
        p = (node*)malloc(sizeof(node));
        p->key = x->key;
        k->next = p;
        p->next = NULL;
        k = p;
        x = x->next;
    }
    while(y) {
        p = (node*)malloc(sizeof(node));
        p->key = y->key;
        k->next = p;
        p->next = NULL;
        k = p;
        y = y->next;
    }
    return head;
}

int main() {
    int m,n;
    printf("enter m :\n");
    scanf("%d", &m);
    printf("enter n :\n");
    scanf("%d", &n);
    printf("\nenter list 1 :\n");
    int i, temp;

    node* head1 = (node*)malloc(sizeof(node));
    head1->next = NULL;
    for(i=0;i<m;i++) {
        scanf("%d", &temp);
        linkedlistinsert(head1, temp);
    }

    printf("\nenter list 2 :\n");
    node* head2 = (node*)malloc(sizeof(node));
    head2->next = NULL;
    for(i=0;i<n;i++) {
        scanf("%d", &temp);
        linkedlistinsert(head2, temp);
    }
    printlinkedlist(head1);
    printlinkedlist(head2);
    //merging two linked lists
    node* head = mergelinkedlists(head1, head2);

    //reversing them
    head = reversealinkedlist(head, m+n);

    printlinkedlist(head);
    freelnkdlist(head);
    return 0;
}
*/
