#include "pushswap.h"
void rr(t_node **stacka, t_node **stackb)
{
    ra(stacka);  // Rotate stacka upwards
    rb(stackb);  // Rotate stackb upwards
    ft_printf("rr\n");
}
