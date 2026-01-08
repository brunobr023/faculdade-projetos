/*
 operacaoListaLigada.c
 Basic singly-linked list operations (integer payload).
 Create, insert, remove, find, print, destroy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    size_t size;
} List;

/* Create an empty list */
List *list_create(void) {
    List *l = (List *)malloc(sizeof(List));
    if (!l) return NULL;
    l->head = NULL;
    l->size = 0;
    return l;
}

/* Free all nodes and the list struct */
void list_destroy(List *l) {
    if (!l) return;
    Node *cur = l->head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(l);
}

/* Remove all nodes but keep list struct */
void list_clear(List *l) {
    if (!l) return;
    Node *cur = l->head;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    l->head = NULL;
    l->size = 0;
}

/* Create a new node */
static Node *node_create(int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    if (!n) return NULL;
    n->value = v;
    n->next = NULL;
    return n;
}

/* Insert at front. Returns 0 on success, -1 on failure */
int list_push_front(List *l, int v) {
    if (!l) return -1;
    Node *n = node_create(v);
    if (!n) return -1;
    n->next = l->head;
    l->head = n;
    l->size++;
    return 0;
}

/* Insert at back. Returns 0 on success, -1 on failure */
int list_push_back(List *l, int v) {
    if (!l) return -1;
    Node *n = node_create(v);
    if (!n) return -1;
    if (!l->head) {
        l->head = n;
    } else {
        Node *cur = l->head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
    l->size++;
    return 0;
}

/* Insert at index (0..size). Returns 0 on success, -1 on failure */
int list_insert_at(List *l, size_t index, int v) {
    if (!l) return -1;
    if (index > l->size) return -1;
    if (index == 0) return list_push_front(l, v);
    Node *cur = l->head;
    for (size_t i = 0; i + 1 < index; ++i) cur = cur->next;
    Node *n = node_create(v);
    if (!n) return -1;
    n->next = cur->next;
    cur->next = n;
    l->size++;
    return 0;
}

/* Remove first occurrence of value. Returns 0 if removed, -1 if not found or error */
int list_remove_value(List *l, int v) {
    if (!l || !l->head) return -1;
    Node *cur = l->head;
    Node *prev = NULL;
    while (cur) {
        if (cur->value == v) {
            if (prev) prev->next = cur->next;
            else l->head = cur->next;
            free(cur);
            l->size--;
            return 0;
        }
        prev = cur;
        cur = cur->next;
    }
    return -1;
}

/* Remove at index. If out != NULL it receives removed value.
   Returns 0 on success, -1 on failure. */
int list_remove_at(List *l, size_t index, int *out) {
    if (!l || index >= l->size) return -1;
    Node *cur = l->head;
    Node *prev = NULL;
    for (size_t i = 0; i < index; ++i) {
        prev = cur;
        cur = cur->next;
    }
    if (prev) prev->next = cur->next;
    else l->head = cur->next;
    if (out) *out = cur->value;
    free(cur);
    l->size--;
    return 0;
}

/* Find first index of value; returns index or -1 if not found */
ssize_t list_find(const List *l, int v) {
    if (!l) return -1;
    Node *cur = l->head;
    size_t idx = 0;
    while (cur) {
        if (cur->value == v) return (ssize_t)idx;
        cur = cur->next;
        idx++;
    }
    return -1;
}

/* Print list values (for debugging) */
void list_print(const List *l) {
    if (!l) {
        printf("(null)\n");
        return;
    }
    printf("[");
    Node *cur = l->head;
    while (cur) {
        printf("%d", cur->value);
        if (cur->next) printf(", ");
        cur = cur->next;
    }
    printf("]\n");
}

/* Return number of elements */
size_t list_size(const List *l) {
    return l ? l->size : 0;
}

/* Check empty */
int list_is_empty(const List *l) {
    return !l || l->size == 0;
}

/* Example usage (uncomment to test compiling this file standalone) */
/*
int main(void) {
    List *l = list_create();
    list_push_back(l, 10);
    list_push_front(l, 5);
    list_insert_at(l, 1, 7);
    list_print(l); // [5, 7, 10]
    int val;
    list_remove_at(l, 1, &val);
    printf("removed %d\n", val);
    list_print(l); // [5, 10]
    list_destroy(l);
    return 0;
}
*/