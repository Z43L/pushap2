#include "pushswap.h"
void pb(t_pushswap *ps) 
{
    if (ps->stacka)
    {
        t_node *first_a = ps->stacka;
        ps->stacka = ps->stacka->next;
        
        first_a->next = ps->stackb;
        ps->stackb = first_a;
        
        ps->size_a--;
        ps->size_b++;
    }
}
