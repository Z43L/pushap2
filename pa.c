#include "pushswap.h"

void pa(t_node **a, t_node **b)
{
    t_node *temp;

    if (*b == NULL)  // If stack B is empty, do nothing
        return;
    
    temp = *b;       // Get the top of stack B
    *b = (*b)->next; // Move stack B's top to the next element
    temp->next = *a; // Link the old top of B to the top of stack A
    *a = temp;       // Set it as the new top of stack A
    ft_printf("pa\n");
}
