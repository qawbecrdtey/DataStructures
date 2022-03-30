#ifndef DATASTRUCTURES_LIST_H
#define DATASTRUCTURES_LIST_H

#ifdef LIST_DATASTRUCTURE

#include <predef.h>

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct list_elem {
    struct list_elem *prev;
    struct list_elem *next;
};

struct list {
    struct list_elem head;
    struct list_elem tail;
};

#define list_entry(LIST_ELEM, STRUCT, MEMBER) \
((STRUCT*)((uint8_t*)&(LIST_ELEM)->next - offsetof(STRUCT, MEMBER.next)))

void list_init(struct list*);

struct list_elem *list_begin(struct list*);
struct list_elem *list_next(struct list_elem*);
struct list_elem *list_end(struct list*);

struct list_elem *list_rbegin(struct list*);
struct list_elem *list_prev(struct list_elem*);
struct list_elem *list_rend(struct list*);

struct list_elem *list_head(struct list*);
struct list_elem *list_tail(struct list*);

void list_insert(struct list_elem*, struct list_elem*);
void list_splice(struct list_elem*, struct list_elem*, struct list_elem*);
void list_push_front(struct list*, struct list_elem*);
void list_push_back(struct list*, struct list_elem*);

struct list_elem *list_remove(struct list_elem*);
struct list_elem *list_pop_front(struct list*);
struct list_elem *list_pop_back(struct list*);

struct list_elem *list_front(struct list*);
struct list_elem *list_back(struct list*);

size_t list_size(struct list const*);
bool list_empty(struct list const*);

void list_reverse(struct list*);

typedef bool list_less_func(struct list_elem const*, struct list_elem const*, void*);

void list_sort(struct list*, list_less_func*, void*);
void list_insert_ordered(struct list*, struct list_elem*, list_less_func*, void*);
void list_unique(struct list*, struct list*, list_less_func*, void*);

struct list_elem *list_max(struct list*, list_less_func*, void*);
struct list_elem *list_min(struct list*, list_less_func*, void*);

#ifdef __cplusplus
}
#endif

#endif

#endif
