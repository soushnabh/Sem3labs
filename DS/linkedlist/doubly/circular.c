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

    printf("(t)raverse/(a)ppend/(p)repend/(i)nsert/(f)pop-front/(r)pop-rear/(d)elete/(q)uit\n");
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
    if (*avail == NULL) return 1;
    struct Node* new = *avail; *avail = availnext();
    new->data = val;
    if (*start == NULL) { new->next = new; new->prev = new; *start = new; return 0; }
    struct Node* tail = (*start)->prev;
    new->next = *start; new->prev = tail;
    tail->next = new; (*start)->prev = new; *start = new; return 0;
}

int append(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) return 1;
    struct Node* new = *avail; *avail = availnext();
    new->data = val;
    if (*start == NULL) { new->next = new; new->prev = new; *start = new; return 0; }
    struct Node* tail = (*start)->prev;
    new->next = *start; new->prev = tail;
    tail->next = new; (*start)->prev = new; return 0;
}

int insert_before(struct Node** start, int val, int search, struct Node** avail) {
    if (*start == NULL || *avail == NULL) return 1;
    struct Node* t = *start;
    do { if (t->data == search) break; t = t->next; } while (t != *start);
    if (t->data != search) return 1;
    struct Node* new = *avail; *avail = availnext(); new->data = val;
    new->prev = t->prev; new->next = t;
    t->prev->next = new; t->prev = new;
    if (t == *start) *start = new;
    return 0;
}

int insert_after(struct Node** start, int val, int search, struct Node** avail) {
    if (*start == NULL || *avail == NULL) return 1;
    struct Node* t = *start;
    do { if (t->data == search) break; t = t->next; } while (t != *start);
    if (t->data != search) return 1;
    struct Node* new = *avail; *avail = availnext(); new->data = val;
    new->prev = t; new->next = t->next;
    t->next->prev = new; t->next = new; return 0;
}

int pop(struct Node** start) {
    if (*start == NULL) return 1;
    struct Node* t = (*start)->prev;
    if (t == *start) *start = NULL;
    else { t->prev->next = *start; (*start)->prev = t->prev; }
    free(t); return 0;
}

int popf(struct Node** start) {
    if (*start == NULL) return 1;
    struct Node* old = *start;
    if (old->next == old) *start = NULL;
    else {
        struct Node* tail = old->prev;
        *start = old->next; (*start)->prev = tail;
        tail->next = *start;
    }
    free(old); return 0;
}

int delete_before(struct Node** start, int search) {
    if (*start == NULL) return 1;
    struct Node* t = *start;
    do { if (t->data == search) break; t = t->next; } while (t != *start);
    if (t->data != search || t->prev == t) return 1;
    struct Node* v = t->prev;
    if (v == *start) *start = t;
    v->prev->next = t; t->prev = v->prev;
    free(v); return 0;
}

int delete_after(struct Node** start, int search) {
    if (*start == NULL) return 1;
    struct Node* t = *start;
    do { if (t->data == search) break; t = t->next; } while (t != *start);
    if (t->data != search || t->next == t) return 1;
    struct Node* v = t->next;
    t->next = v->next; v->next->prev = t;
    free(v); return 0;
}
