#include "pushswap.h"

/* int lenstacka(pushswap pushswap)
{
    int i; 
    i = 0;
    while(pushswap.stacka[i] != '\0')
        i++;
    return i;
} */
void ra(t_pushswap *ps) 
{
    if (ps->stacka && ps->stacka->next)
    {
        t_node *first = ps->stacka;
        t_node *last = ps->stacka;

        while (last->next != NULL)
            last = last->next;

        ps->stacka = first->next;
        first->next = NULL;
        last->next = first;
    }
}
