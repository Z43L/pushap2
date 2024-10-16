#include "pushswap.h"

void sb(t_node **b)
{
    if (*b != NULL && (*b)->next != NULL)  // Ensure there are at least two nodes
    {
        int temp = (*b)->value;  // Swap the values of the top two nodes
        (*b)->value = (*b)->next->value;
        (*b)->next->value = temp;
        ft_printf("sb\n");
    }
}
