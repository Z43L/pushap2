#include   "pushswap.h"

int get_max_bits(t_pushswap *ps) 
{
    int max = 0;
    t_node *current = ps->stacka;

    while (current != NULL)
    {
        if (current->index > max)
            max = current->index;
        current = current->next;
    }

    int bits = 0;
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void radix_sort(t_pushswap *ps) 
{
    int max_bits = get_max_bits(ps);
    int i = 0;

    while (i < max_bits)
    {
        int size_a = ps->size_a;

        while (size_a--)
        {
            int num = ps->stacka->index;

            if (((num >> i) & 1) == 1)
            {
                ra(ps);
                ft_printf("ra\n");
            }
            else
            {
                pb(ps);
                ft_printf("pb\n");
            }
        }

        while (ps->size_b > 0)
        {
            pa(ps);
            ft_printf("pa\n");
        }

        i++;
    }
}
