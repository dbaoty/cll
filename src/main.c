#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_t {
    size_t idx;
    int data;
    struct node_t *next;
} node_t;

void fillrr(node_t *, node_t *, size_t, int);
void freel(node_t *);
void print(node_t *);
void bbsort(node_t *);

int main(void) {
    time_t t;
    srand((unsigned) time(&t));

    node_t *head = malloc(sizeof(node_t));
    head->idx = 0;
    head->data = 0;
    head->next = NULL;
    
    node_t *new = NULL;
    fillrr(head, new, 100, 10);
    
    printf("\nBefore sort: \n");
    print(head);

    bbsort(head);

    printf("\nAfter sort: \n");
    print(head);

    printf("\n");

    freel(head);
    free(new);
    return 0;
}

void fillrr(node_t *head, node_t *new, size_t n, int range) {
    node_t *p = head;
    for (size_t i = 0; i < n - 1; ++i) {
        new = malloc(sizeof(node_t));
        new->idx = 0;
        new->data = rand() % range;
        new->next = NULL;

        p->next = new;
        p = p->next;
    }

    p->next = NULL;
}

void freel(node_t *head) {
    node_t *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print(node_t *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}


void bbsort(node_t *head) {
    node_t *p;
    size_t l = 0;

    node_t *t = head;
    while (t) {
        l += 1;
        t = t->next;
    }

    for (size_t i = 0; i < l; ++i) {
        p = head;
        int swapped = 0;

        for (size_t j = 0; j < l - i - 1; ++j) {
            node_t *q = p;
            node_t *r = p->next;

            if (q->data > r->data) {
                int tmp = q->data;
                q->data = r->data;
                r->data = tmp;
                swapped = 1;
            }

            p = p->next;
        }

        if (swapped == 0) break;
    }
}
