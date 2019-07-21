#include<stdio.h>

/*struct _node {
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

    //finding middle element
    node* x = head->next;
    int p = n/2;
    while(p>0) {
        p--;
        x = x->next;
    }
    printf("\n%d", x->key);
    printf("\nhead->key = %d", head->next->key);

    freelnkdlist(head);
    return 0;
}
*/
