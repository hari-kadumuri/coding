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
    printf("\nreversed linked list :  ");
    while(x) {
        printf("%d  ", x->key);
        x = x->next;
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

    head = reversealinkedlist(head, n);

    //printing reverse linked list
    printlinkedlist(head);

    freelnkdlist(head);
    return 0;
}
*/
