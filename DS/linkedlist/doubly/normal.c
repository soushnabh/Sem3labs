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
    if (*avail == NULL) return 1;
    struct Node* new = *avail; *avail = availnext();
    new->data = val; new->prev = NULL; new->next = *start;
    if (*start) (*start)->prev = new;
    *start = new; return 0;
}

int append(struct Node** start, int val, struct Node** avail) {
    if (*avail == NULL) return 1;
    struct Node* new = *avail; *avail = availnext();
    new->data = val; new->next = NULL;
    if (*start == NULL) { new->prev = NULL; *start = new; return 0; }
    struct Node* p = *start;
    while (p->next) p = p->next;
    p->next = new; new->prev = p; return 0;
}

int insert_before(struct Node** start, int val, int search, struct Node** avail) {
    if (*start == NULL || *avail == NULL) return 1;
    struct Node* t = *start;
    while (t && t->data != search) t = t->next;
    if (t == NULL) return 1;
    struct Node* new = *avail; *avail = availnext(); new->data = val;
    new->prev = t->prev; new->next = t;
    if (t->prev) t->prev->next = new; else *start = new;
    t->prev = new; return 0;
}

int insert_after(struct Node** start, int val, int search, struct Node** avail) {
    if (*start == NULL || *avail == NULL) return 1;
    struct Node* t = *start;
    while (t && t->data != search) t = t->next;
    if (t == NULL) return 1;
    struct Node* new = *avail; *avail = availnext(); new->data = val;
    new->prev = t; new->next = t->next;
    if (t->next) t->next->prev = new;
    t->next = new; return 0;
}

int pop(struct Node** start) {
    if (*start == NULL) return 1;
    struct Node* t = *start;
    while (t->next) t = t->next;
    if (t->prev) t->prev->next = NULL; else *start = NULL;
    free(t); return 0;
}

int popf(struct Node** start) {
    if (*start == NULL) return 1;
    struct Node* t = *start; *start = t->next;
    if (*start) (*start)->prev = NULL;
    free(t); return 0;
}

int delete_before(struct Node** start, int search) {
    if (*start == NULL) return 1;
    struct Node* t = *start;
    while (t && t->data != search) t = t->next;
    if (t == NULL || t->prev == NULL) return 1;
    struct Node* v = t->prev;
    t->prev = v->prev;
    if (v->prev) v->prev->next = t; else *start = t;
    free(v); return 0;
}

int delete_after(struct Node** start, int search) {
    if (*start == NULL) return 1;
    struct Node* t = *start;
    while (t && t->data != search) t = t->next;
    if (t == NULL || t->next == NULL) return 1;
    struct Node* v = t->next;
    t->next = v->next;
    if (v->next) v->next->prev = t;
    free(v); return 0;
}
