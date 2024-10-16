#include "pushswap.h"
void sa(t_node **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;  // No hay suficientes elementos para hacer swap

    t_node *first = *a;
    t_node *second = (*a)->next;

    // Intercambiamos los dos primeros nodos
    first->next = second->next;
    second->next = first;
    *a = second;

    // Imprimimos el movimiento
    ft_printf("sa\n");
}
