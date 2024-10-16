#include "pushswap.h"

void rb(t_node **b)
{
    if (*b == NULL || (*b)->next == NULL)  // If the stack has less than 2 elements, do nothing
        return;

    t_node *temp = *b;      // Pointer to the current top node
    t_node *last = *b;      // Pointer to traverse the list

    while (last->next != NULL)  // Find the last node in the stack
        last = last->next;

    *b = (*b)->next;        // Move the top to the second element
    temp->next = NULL;      // Detach the original top from the list
    last->next = temp;      // Attach the original top to the end of the list

    ft_printf("rb\n");
}
