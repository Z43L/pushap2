#include "pushswap.h"
void pb(t_node **stack_a, t_node **stack_b) {
    if (!*stack_a)
        return;
    t_node *temp = *stack_a;
    
    *stack_a = temp->next;
    temp->next = *stack_b;
    *stack_b = temp;
}
