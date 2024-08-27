#include "pushswap.h"

void pa(t_pushswap *ps) 
{
    if (ps->stackb)
    {
        t_node *first_b = ps->stackb;
        ps->stackb = ps->stackb->next;
        
        first_b->next = ps->stacka;
        ps->stacka = first_b;
        
        ps->size_a++;
        ps->size_b--;
    }
}

