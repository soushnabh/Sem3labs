#include "stdio.h"
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* availnext() {
    return malloc(sizeof(struct Node));
}

void traverse(struct Node* start);

int append(struct Node** start, int val, struct Node** avail);
int prepend(struct Node** start, int val, struct Node** avail);

int pop(struct Node** start);
int popf(struct Node** start);

int main() {
    struct Node* start = NULL;
    struct Node* avail = availnext();

    printf("(t)raverse/(a)ppend/(p)repend/(f)pop-front/(r)pop-rear/(q)uit\n");
    char op;
    while (1) {
        scanf(" %c", &op);
        switch (op) {
            case 'a': {
                int val;
                printf("element: ");
                scanf("%d", &val);
                append(&start, val, &avail);
                break;
            }
            case 'p': {
                int val;
                printf("element: ");
                scanf("%d", &val);
                prepend(&start, val, &avail);
                break;
            }
            case 'f':
                popf(&start);
                break;
            case 'r':
                pop(&start);
                break;
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
        while (ptr->next != start) {
            printf("%d, ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d]\n", ptr->data);
    }
}

int prepend(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) {
        return 1;
    }
    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;
    if (*start != NULL) {
        struct Node* ptr = *start;
        while (ptr->next != *start) {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = *start;
    } else {
        new->next = new;
    }
    *start = new;
    return 0;
}

int append(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) {
        return 1;
    }
    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;
    if (*start != NULL) {
        struct Node* ptr = *start;
        while (ptr->next != *start) {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->next = *start;
    } else {
        new->next = new;
        *start = new;
    }
    return 0;
}

int pop(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }
    struct Node* ptr = *start;
    struct Node* preptr = ptr;
    if (ptr->next == *start) {
        *start = NULL;
    } else {
        while (ptr->next != *start) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = *start;
    }
    free(ptr);
    return 0;
}

int popf(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }
    struct Node* ptr = *start;
    while (ptr->next != *start) {
        ptr = ptr->next;
    }
    ptr->next = (*start)->next;
    if (ptr->next == *start) {
        free(*start);
        *start = NULL;
    } else {
        free(*start);
        *start = ptr->next;
    }
    return 0;
}
