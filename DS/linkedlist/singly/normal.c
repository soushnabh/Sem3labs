#include "stdio.h"
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* start);
struct Node* search(struct Node* start, int search);

int append(struct Node** start, int val);
int prepend(struct Node** start, int val);
int insert(struct Node** start, int val, int search);

int pop(struct Node** start);
int popf(struct Node** start);

int main() {
    struct Node* start = NULL;

    printf("(t)raverse/(s)earch/(a)ppend/(p)repend/(i)nsert/(f)pop-front/(r)pop-rear/(q)uit\n");
    char op;
    while (1) {
        scanf(" %c", &op);
        switch (op) {
            case 'a': {
                int val;
                printf("element: ");
                scanf("%d", &val);
                append(&start, val);
                break;
            }
            case 'p': {
                int val;
                printf("element: ");
                scanf("%d", &val);
                prepend(&start, val);
                break;
            }
            case 'f':
                popf(&start);
                break;
            case 'r':
                pop(&start);
                break;
            case 'i': {
                int val, after;
                printf("element and search: ");
                scanf("%d %d", &val, &after);
                insert(&start, val, after);
                break;
            }
            case 's': {
                int val;
                printf("element: ");
                scanf("%d", &val);
                struct Node *found = search(start, val);
                if (found != NULL)
                    printf("%d\n", found->data);
                else
                    printf("Not found\n");
                break;
            }
            case 't':
                traverse(start);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}

void traverse(struct Node* start) {
    struct Node* ptr = start;
    if (ptr == NULL) {
        printf("empty\n");
    } else {
        printf("[");
        while (ptr->next != NULL) {
            printf("%d, ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d]\n", ptr->data);
    }
}

struct Node* search(struct Node* start, int search) {
    struct Node* ptr = start;
    struct Node* pos = NULL;
    while (ptr!=NULL) {
        if (ptr->data == search) {
            pos = ptr;
            break;
        } else {
            ptr = ptr->next;
        }
    }
    return pos;
}

int prepend(struct Node** start, int val) {
    struct Node* new = malloc(sizeof(struct Node));
    if (new == NULL) {
        return 1;
    }
    new->data = val;
    new->next = *start;
    *start = new;
    return 0;
}

int append(struct Node** start, int val) {
    struct Node* new = malloc(sizeof(struct Node));
    if (new == NULL) {
        return 1;
    }
    new->data = val;
    new->next = NULL;
    if (*start == NULL) {
        *start = new;
    } else {
        struct Node* ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    return 0;
}

int insert(struct Node** start, int val, int search) {
    struct Node* new = malloc(sizeof(struct Node));
    if (new == NULL) {
        return 1;
    }
    new->data = val;
    struct Node* preptr = *start;
    if (*start == NULL) {
        return 1;
    } else {
        while (preptr->next != NULL && preptr->data!=search) {
            preptr = preptr->next;
        }
        if (preptr->data==search){
            struct Node* ptr = preptr->next;
            preptr->next = new;
            new->next = ptr;
        }
    }
    return 0;
}

int pop(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }
    struct Node* ptr = *start;
    struct Node* preptr = ptr;
    if (ptr->next == NULL) {
        *start = NULL;
    } else {
        while (ptr->next != NULL) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
    }
    free(ptr);
    return 0;
}

int popf(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }
    struct Node* ptr = *start;
    *start = ptr->next;
    free(ptr);
    return 0;
}
