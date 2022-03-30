#define QUEUE_DATASTRUCTURE
#include "queue.h"

#include <assert.h>

void queue_init(struct queue *queue) {
    assert(queue);
    queue->head.prev = queue->tail.prev = NULL;
}

struct queue_elem *queue_front(struct queue const *queue) {
    assert(queue);
    return queue->tail.prev;
}

struct queue_elem *queue_back(struct queue const *queue) {
    assert(queue);
    return queue->head.prev;
}

void queue_push(struct queue *queue, struct queue_elem *elem) {
    assert(queue);
    assert(elem);
    struct queue_elem *e = queue->head.prev;
    queue->head.prev = elem;
    elem->prev = NULL;
    if(!e) queue->tail.prev = elem;
    else e->prev = elem;
}

struct queue_elem *queue_pop(struct queue *queue) {
    assert(queue);
    assert(queue->tail.prev);
    struct queue_elem *e = queue->tail.prev;
    queue->tail.prev = e->prev;
    e->prev = NULL;
    if(!queue->tail.prev) queue->head.prev = NULL;
    return e;
}

size_t queue_size(struct queue const *queue) {
    assert(queue);
    struct queue_elem *e = queue->tail.prev;
    size_t cnt = 0;
    while(e) {
        e = e->prev;
        cnt++;
    }
    return cnt;
}

bool queue_empty(struct queue const *queue) {
    assert(queue);
    return !queue->tail.prev;
}