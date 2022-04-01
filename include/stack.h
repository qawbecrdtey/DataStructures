#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#ifdef STACK_DATASTRUCTURE

#include <predef.h>

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct stack_elem {
    struct stack_elem *next;
};

struct stack {
    struct stack_elem head;
};

#define stack_entry(STACK_ELEM, STRUCT, MEMBER) \
((STRUCT*)((uint8_t*)&(STACK_ELEM)->next - offsetof(STRUCT, MEMBER.next)))

void stack_init(struct stack*);

struct stack_elem *stack_top(struct stack const*);

void stack_push(struct stack*, struct stack_elem*);
struct stack_elem *stack_pop(struct stack*);

size_t stack_size(struct stack const*);
bool stack_empty(struct stack const*);

#ifdef __cplusplus
}
#endif

#endif

#endif
