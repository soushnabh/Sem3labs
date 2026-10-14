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
    if (start == NULL) {
        printf("empty\n");
        return;
    }

    struct Node* ptr = start;
    printf("[");
    do {
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != start) {
            printf(", ");
        }
    } while (ptr != start);
    printf("]\n");
}

int prepend(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) {
        return 1;
    }

    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;

    if (*start == NULL) {
        new->next = new;
        new->prev = new;
        *start = new;
    } else {
        struct Node* tail = (*start)->prev;

        new->next = *start;
        new->prev = tail;
        tail->next = new;
        (*start)->prev = new;
        *start = new;
    }

    return 0;
}

int append(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) {
        return 1;
    }

    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;

    if (*start == NULL) {
        new->next = new;
        new->prev = new;
        *start = new;
    } else {
        struct Node* tail = (*start)->prev;

        new->next = *start;
        new->prev = tail;
        tail->next = new;
        (*start)->prev = new;
    }

    return 0;
}

int insert_before(struct Node** start, int val, int search,
                  struct Node** avail) {
    if (*start == NULL || *avail == NULL) {
        return 1;
    }

    struct Node* target = *start;
    do {
        if (target->data == search) {
            break;
        }
        target = target->next;
    } while (target != *start);

    if (target->data != search) {
        return 1;
    }

    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;

    new->prev = target->prev;
    new->next = target;
    target->prev->next = new;
    target->prev = new;

    if (target == *start) {
        *start = new;
    }

    return 0;
}

int insert_after(struct Node** start, int val, int search,
                 struct Node** avail) {
    if (*start == NULL || *avail == NULL) {
        return 1;
    }

    struct Node* target = *start;
    do {
        if (target->data == search) {
            break;
        }
        target = target->next;
    } while (target != *start);

    if (target->data != search) {
        return 1;
    }

    struct Node* new = *avail;
    *avail = availnext();
    new->data = val;

    new->prev = target;
    new->next = target->next;
    target->next->prev = new;
    target->next = new;

    return 0;
}

int pop(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* tail = (*start)->prev;

    if (tail == *start) {
        *start = NULL;
    } else {
        tail->prev->next = *start;
        (*start)->prev = tail->prev;
    }

    free(tail);
    return 0;
}

int popf(struct Node** start) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* old_start = *start;

    if (old_start->next == old_start) {
        *start = NULL;
    } else {
        struct Node* tail = old_start->prev;
        *start = old_start->next;
        (*start)->prev = tail;
        tail->next = *start;
    }

    free(old_start);
    return 0;
}

int delete_before(struct Node** start, int search) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* target = *start;
    do {
        if (target->data == search) {
            break;
        }
        target = target->next;
    } while (target != *start);

    if (target->data != search || target->prev == target) {
        return 1;  // Not found, or there is no other node before it.
    }

    struct Node* victim = target->prev;

    if (victim == *start) {
        *start = target;
    }

    victim->prev->next = target;
    target->prev = victim->prev;
    free(victim);

    return 0;
}

int delete_after(struct Node** start, int search) {
    if (*start == NULL) {
        return 1;
    }

    struct Node* target = *start;
    do {
        if (target->data == search) {
            break;
        }
        target = target->next;
    } while (target != *start);

    if (target->data != search || target->next == target) {
        return 1;  // Not found, or there is no other node after it.
    }

    struct Node* victim = target->next;

    target->next = victim->next;
    victim->next->prev = target;
    free(victim);

    return 0;
}
