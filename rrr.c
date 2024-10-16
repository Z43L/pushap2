#include "pushswap.h"
void rrr(t_node **stacka, t_node **stackb)
{
    rra(stacka);  // Rotate stacka downwards
    rrb(stackb);  // Rotate stackb downwards
    ft_printf("rrr\n");
}
