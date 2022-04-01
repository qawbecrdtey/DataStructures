#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#ifdef QUEUE_DATASTRUCTURE

#include <predef.h>

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct queue_elem {
    struct queue_elem *prev;
};

struct queue {
    struct queue_elem head;
    struct queue_elem tail;
};

#define queue_entry(QUEUE_ELEM, STRUCT, MEMBER) \
((STRUCT*)((uint8_t*)&(QUEUE_ELEM)->prev - offsetof(STRUCT, MEMBER.prev)))

void queue_init(struct queue*);

struct queue_elem *queue_front(struct queue const*);
struct queue_elem *queue_back(struct queue const*);

void queue_push(struct queue*, struct queue_elem*);
struct queue_elem *queue_pop(struct queue*);

size_t queue_size(struct queue const*);
bool queue_empty(struct queue const*);

#ifdef __cplusplus
}
#endif

#endif

#endif
