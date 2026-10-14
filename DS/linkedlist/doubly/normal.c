#include "stdio.h"
#include <stdlib.h>

struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node* availnext() {
    return malloc(sizeof(struct Node));
}

void traverse(struct Node* start);

int append(struct Node** start, int val, struct Node** avail);
int prepend(struct Node** start, int val, struct Node** avail);
int insert_before(struct Node** start, int val, int search, struct Node** avail);
int insert_after(struct Node** start, int val, int search, struct Node** avail);

int pop(struct Node** start);
int popf(struct Node** start);
int delete_before(struct Node** start, int search);
int delete_after(struct Node** start, int search);

int main() {
    struct Node* start = NULL;
    struct Node* avail = availnext();

    printf("(t)raverse/(s)earch/(a)ppend/(p)repend/(i)nsert/(f)pop-front/(r)pop-rear/(d)elete/(q)uit\n");
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
            case 'i': {
                int val, search;
                char c;
                printf("element and search and (a)fter/(b)efore: ");
                scanf("%d %d %c", &val, &search, &c);
                switch (c) {
                    case 'a': 
                        insert_after(&start, val, search, &avail);
                        break;
                    case 'b':
                        insert_before(&start, val, search, &avail);
                        break;
                    default:
                        printf("Invalid operation\n");
                }
                break;
            }
            case 't':
                traverse(start);
                break;
            case 'd': {
                int search;
                char c;
                printf("search and (a)fter/(b)efore: ");
                scanf("%d %c", &search, &c);
                switch (c) {
                    case 'a': 
                        delete_after(&start, search);
                        break;
                    case 'b':
                        delete_before(&start, search);
                        break;
                    default:
                        printf("Invalid operation\n");
                }
                break;
                        
            }
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

int prepend(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) {
        return 1;
    }
    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;
    new->prev = NULL;
    new->next = *start;
    if (*start != NULL) {
        (*start)->prev = new;
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
    new->next = NULL;
    if (*start == NULL) {
        *start = new;
    } else {
        struct Node* ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
        new->prev = ptr;
    }
    return 0;
}

int insert_before(struct Node** start, int val, int search, struct Node** avail) {
    if (*start == NULL || *avail == NULL) {
        return 1;
    }

    struct Node* target = *start;
    while (target != NULL && target->data != search) {
        target = target->next;
    }
    if (target == NULL) {
        return 1;
    }

    struct Node* new = *avail;
    *avail = availnext();

    new->data = val;
    new->prev = target->prev;
    new->next = target;

    if (target->prev != NULL) {
        target->prev->next = new;
    } else {
        *start = new;
    }

    target->prev = new;
    return 0;
}

int insert_after(struct Node** start, int val, int search, struct Node** avail) {
    if (*start == NULL || *avail == NULL) {
        return 1;
    }

    struct Node* target = *start;
    while (target != NULL && target->data != search) {
        target = target->next;
    }
    if (target == NULL) {
        return 1;
    }

    struct Node* new = *avail;
    *avail = availnext();

    new->data = val;
    new->prev = target;
    new->next = target->next;

    if (target->next != NULL) {
        target->next->prev = new;
    }

    target->next = new;
    return 0;
}

int pop(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* ptr = *start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL) {
        ptr->prev->next = NULL;
    } else {
        *start = NULL;
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

    if (*start != NULL) {
        (*start)->prev = NULL;
    }

    free(ptr);
    return 0;
}

int delete_before(struct Node** start, int search) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* target = *start;
    while (target != NULL && target->data != search) {
        target = target->next;
    }

    if (target == NULL || target->prev == NULL) {
        return 1;  // Search value not found, or it is the first node.
    }

    struct Node* victim = target->prev;
    target->prev = victim->prev;

    if (victim->prev != NULL) {
        victim->prev->next = target;
    } else {
        *start = target;
    }

    free(victim);
    return 0;
}

int delete_after(struct Node** start, int search) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* target = *start;
    while (target != NULL && target->data != search) {
        target = target->next;
    }

    if (target == NULL || target->next == NULL) {
        return 1;  // Search value not found, or it is the last node.
    }

    struct Node* victim = target->next;
    target->next = victim->next;

    if (victim->next != NULL) {
        victim->next->prev = target;
    }

    free(victim);
    return 0;
}


