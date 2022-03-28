#define LIST_DATASTRUCTURE
#include <list.h>

#include <assert.h>

void list_init(struct list *list) {
    assert(list);
    list->head.prev = list->tail.next = NULL;
    list->head.next = &list->tail;
    list->tail.prev = &list->head;
}

struct list_elem *list_begin(struct list *list) {
    assert(list);
    return list->head.next;
}
struct list_elem *list_next(struct list_elem *elem) {
    assert(elem);
    return elem->next;
}
struct list_elem *list_end(struct list *list) {
    assert(list);
    return &list->tail;
}

struct list_elem *list_rbegin(struct list *list) {
    assert(list);
    return list->tail.prev;
}
struct list_elem *list_prev(struct list_elem *elem) {
    assert(elem);
    return elem->prev;
}
struct list_elem *list_rend(struct list *list) {
    assert(list);
    return &list->head;
}

struct list_elem *list_head(struct list *list) {
    assert(list);
    return &list->head;
}
struct list_elem *list_tail(struct list *list) {
    assert(list);
    return &list->tail;
}

void list_insert(struct list_elem *before, struct list_elem *elem) {
    assert(before);
    assert(before->prev);
    assert(elem);
    elem->prev = before->prev;
    elem->next = before;
    before->prev->next = elem;
    before->prev = elem;
}
void list_splice(struct list_elem *before, struct list_elem *first, struct list_elem *last) {
    assert(before);
    assert(before->prev);

    if(first == last) return;
    last = list_prev(last);

    assert(first);
    assert(first->prev && first->next);
    assert(last);
    assert(last->prev && last->next);

    first->prev->next = last->next;
    last->next->prev = first->prev;

    first->prev = before->prev;
    last->next = before;
    before->prev->next = first;
    before->prev = last;
}
void list_push_front(struct list *list, struct list_elem *elem) {
    assert(list);
    assert(elem);
    elem->prev = &list->head;
    elem->next = list->head.next;
    list->head.next->prev = elem;
    list->head.next = elem;
}
void list_push_back(struct list *list, struct list_elem *elem) {
    assert(list);
    assert(elem);
    elem->prev = list->tail.prev;
    elem->next = &list->tail;
    list->tail.prev->next = elem;
    list->tail.prev = elem;
}

struct list_elem *list_remove(struct list_elem *elem) {
    assert(elem);
    assert(elem->prev && elem->next);
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    struct list_elem *const res = elem->next;
    elem->prev = elem->next = NULL;

    return res;
}
struct list_elem *list_pop_front(struct list *list) {
    assert(list);
    assert(list->head.next != &list->tail);
    struct list_elem *const front = list->head.next;
    list->head.next = front->next;
    list->head.next->prev = &list->head;
    front->prev = front->next = NULL;

    return front;
}
struct list_elem *list_pop_back(struct list *list) {
    assert(list);
    assert(list->head.next != &list->tail);
    struct list_elem *const back = list->tail.prev;
    list->tail.prev = back->prev;
    list->tail.prev->next = &list->tail;
    back->prev = back->next = NULL;

    return back;
}

struct list_elem *list_front(struct list *list) {
    assert(list);
    assert(list->head.next != &list->tail);
    return list->head.next;
}
struct list_elem *list_back(struct list *list) {
    assert(list);
    assert(&list->head != list->tail.prev);
    return list->tail.prev;
}

size_t list_size(struct list const *list) {
    assert(list);
    size_t cnt = 0;
    for(struct list_elem *elem = list->head.next; elem != &list->tail; elem = elem->next) cnt++;
    return cnt;
}
bool list_empty(struct list const *list) {
    assert(list);
    return list->head.next == &list->tail;
}

void list_reverse(struct list *list) {
    assert(list);
    if(list->head.next == &list->tail) return;
    struct list_elem *tmp;
    for(struct list_elem *elem = list->head.next; elem != &list->tail; elem = elem->next) {
        tmp = elem->prev;
        elem->prev = elem->next;
        elem->next = tmp;
    }
    tmp = list->head.next;
    list->head.next = list->tail.prev;
    list->tail.prev = tmp;
    tmp = list->head.next->prev;
    list->head.next->prev = list->tail.prev->next;
    list->tail.prev->next = tmp;
}

// TODO: Implement it.
void list_sort(struct list *list, list_less_func *less, void *aux) {

}
// TODO: Implement it.
void list_insert_ordered(struct list *list, struct list_elem *elem, list_less_func *less, void *aux) {

}
// TODO: Implement it.
void list_unique(struct list *list, struct list *duplicates, list_less_func *less, void *aux) {

}

struct list_elem *list_max(struct list *list, list_less_func *less, void *aux) {
    assert(list);
    assert(less);
    struct list_elem *max = list->head.next;
    if(max != &list->tail) {
        for(struct list_elem *elem = max->next; elem != &list->tail; elem = elem->next) {
            if(less(max, elem, aux)) max = elem;
        }
    }
    return max;
}
struct list_elem *list_min(struct list *list, list_less_func *less, void *aux) {
    assert(list);
    assert(less);
    struct list_elem *min = list->head.next;
    if(min != &list->tail) {
        for(struct list_elem *elem = min->next; elem != &list->tail; elem = elem->next) {
            if(less(elem, min, aux)) min = elem;
        }
    }
    return min;
}