#include "pushswap.h"

void ra(t_node **stack) {
    if (!*stack || !(*stack)->next)
        return;
    t_node *first = *stack;
    t_node *last = *stack;
    while (last->next)
        last = last->next;
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}