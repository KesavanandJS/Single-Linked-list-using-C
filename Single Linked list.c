#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// FRONT ADD
struct node* badd(struct node* start, int d) {
    struct node *fr = malloc(sizeof(struct node));
    fr->data = d;
    fr->link = start;
    start = fr;
    return start;
}

// FRONT DELETE 
struct node* bdel(struct node* start) {
    if (start == NULL) {
        printf("LIST IS EMPTY !");
    } else {
        struct node* tem = start;
        start = start->link;
        free(tem);
    }
    return start;
}

// END ADD
void eadd(int ed, struct node* start) {
    struct node *e = malloc(sizeof(struct node));
    struct node* tem = start;
    e->data = ed;
    e->link = NULL;

    while (tem->link != NULL) {
        tem = tem->link;
    }
    tem->link = e;
}

// END DELETE 
struct node* edel(struct node* start) {
    if (start == NULL) {
        printf("LIST IS EMPTY !");
    } else if (start->link == NULL) {
        free(start);
        start = NULL;
    } else {
        struct node* x = start;
        struct node* y = start;
        while (y->link != NULL) {
            x = y;
            y = y->link;
        }
        x->link = NULL;
        free(y);
    }
    return start;
}

// MIDDLE ADD
void madd(struct node* start, int md) {
    struct node *m = malloc(sizeof(struct node));
    m->data = md;
    struct node *p = start;
    int i = 1, pos;
    printf("Enter position (>1): ");
    scanf("%d", &pos);
    while (i < pos - 1 && p != NULL) {
        p = p->link;
        i++;
    }
    if (p != NULL) {
        m->link = p->link;
        p->link = m;
    } else {
        printf("Position out of range\n");
        free(m);
    }
}

// MIDDLE DELETE
struct node* mdel(struct node* start, int pos) {
    if (start == NULL) {
        printf("LIST IS EMPTY !");
        return start;
    }
    
    struct node* p = start;
    struct node* q = NULL;
    int i = 1;
    
    if (pos == 1) {
        start = bdel(start);
        return start;
    }
    
    while (i < pos && p != NULL) {
        q = p;
        p = p->link;
        i++;
    }
    
    if (p == NULL) {
        printf("Position out of range\n");
    } else {
        q->link = p->link;
        free(p);
    }
    
    return start;
}

// DISPLAY
void display(struct node* start) {
    struct node* pr = start;
    while (pr != NULL) {
        printf("%d  ", pr->data);
        pr = pr->link;
    }
    printf("\n");
}

int main() {
    int n, n1, i, data, md, ed, pos, op;

    struct node *start = NULL;
    start = malloc(sizeof(struct node));

    start->data = 1;
    start->link = NULL;

    struct node *new = NULL;
    new = malloc(sizeof(struct node));
    new->data = 2;
    new->link = NULL;
    start->link = new;

    do {
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("Enter 0 for exit !\n");
        printf("Enter your choice : ");
        scanf("%d", &n);
        if (n >= 4) {
            printf("Enter correct option!! \n\n");
        } else {
            switch (n) {
                case 1:
                    printf("\t----SELECT REQUIRED OPERATION----\n\n");
                    printf("1. Insertion at beginning.\n");
                    printf("2. Insertion at middle.\n");
                    printf("3. Insertion at end.\n");
                    printf("Enter 0 for exit !\n");
                    printf("Enter your choice : ");
                    scanf("%d", &n1);
                    //-----ADDING IN FRONT
                    if (n1 == 1) {
                        printf("\t\tINSERTING NODE AT BEGINNING !!\n\n");
                        printf("Provide data for inserting node : ");
                        scanf("%d", &data);
                        start = badd(start, data);
                        printf("AFTER ADDING NODE AT BEGINNING :\n\n");
                        display(start);
                    }
                    //-------ADDING IN MIDDLE
                    else if (n1 == 2) {
                        printf("\t\tINSERTING NODE AT MIDDLE !!\n\n");
                        printf("Provide data for inserting node : ");
                        scanf("%d", &md);

                        madd(start, md);
                        printf("AFTER ADDING NODE AT MIDDLE :\n\n");
                        display(start);
                    }
                    //------ADDING IN END
                    else if (n1 == 3) {
                        printf("\t\tINSERTING NODE AT END !!\n\n");
                        printf("Provide data for inserting node : ");
                        scanf("%d", &ed);
                        eadd(ed, start);
                        printf("AFTER ADDING NODE AT END :\n\n");
                        display(start);
                    }
                    break;

                case 2:
                    printf("\t----SELECT REQUIRED OPERATION----\n\n");
                    printf("1. Deletion at beginning.\n");
                    printf("2. Deletion at middle.\n");
                    printf("3. Deletion at end.\n");
                    printf("Enter 0 for exit !\n");
                    printf("Enter your choice : ");
                    scanf("%d", &n1);
                    //-----  IN FRONT
                    if (n1 == 1) {
                        printf("\t\tDELETING NODE AT BEGINNING !!\n\n");

                        start = bdel(start);
                        printf("AFTER DELETING NODE AT BEGINNING :\n\n");
                        display(start);
                    }
                    //-------  IN MIDDLE
                    else if (n1 == 2) {
                        printf("\t\tDELETING NODE AT MIDDLE !!\n\n");
                        printf("Enter position to delete (>1): ");
                        scanf("%d", &pos);
                        
                        start = mdel(start, pos);
                        printf("AFTER DELETING NODE AT MIDDLE :\n\n");
                        display(start);
                    }
                    //------  IN END
                    else if (n1 == 3) {
                        printf("\t\tDELETING NODE AT END !!\n\n");

                        start = edel(start);
                        printf("AFTER DELETING NODE AT END :\n\n");
                        display(start);
                    }
                    break;

                case 3:
                    display(start);
                    break;

                default:
                    printf("------Thank you------\n\n");
                    break;
            }
        }
        printf("\n\nDo you want to continue operation (press 1): ");
        scanf("%d", &op);
        if (op != 1) {
            printf("-------Thank you-------");
        }
    } while (op == 1);

    return 0;
}