#define STACK_DATASTRUCTURE
#include "stack.h"

#include <assert.h>

void stack_init(struct stack *stack) {
    assert(stack);
    stack->head.next = NULL;
}

struct stack_elem *stack_top(struct stack const *stack) {
    assert(stack);
    return stack->head.next;
}

void stack_push(struct stack *stack, struct stack_elem *elem) {
    assert(stack);
    assert(elem);
    elem->next = stack->head.next;
    stack->head.next = elem;
}

struct stack_elem *stack_pop(struct stack *stack) {
    assert(stack);
    assert(stack->head.next);
    struct stack_elem *elem = stack->head.next;
    stack->head.next = stack->head.next->next;
    elem->next = NULL;
    return elem;
}

size_t stack_size(struct stack const *stack) {
    assert(stack);
    size_t cnt = 0;
    struct stack_elem const *e = &stack->head;
    while(e->next) {
        e = e->next;
        cnt++;
    }
    return cnt;
}

bool stack_empty(struct stack const *stack) {
    assert(stack);
    return !stack->head.next;
}