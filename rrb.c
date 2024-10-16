#include "pushswap.h"

void rrb(t_node **b)
{
    if (*b == NULL || (*b)->next == NULL)  // If the stack has less than 2 elements, do nothing
        return;

    t_node *second_last = NULL;  // Pointer to track the second last node
    t_node *last = *b;           // Pointer to track the last node

    // Traverse the stack to find the last and second-to-last nodes
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }

    // Re-arrange pointers to rotate the stack downwards
    second_last->next = NULL;  // Detach the last node from the second-to-last node
    last->next = *b;           // Move the last node to the top of the stack
    *b = last;                 // Update the top of the stack

    ft_printf("rrb\n");
}
