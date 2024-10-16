#include "pushswap.h"

void rra(t_node **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;  // No hay elementos o solo hay uno

    t_node *last = *a;
    t_node *second_last = NULL;

    // Recorremos hasta encontrar el último nodo y el penúltimo
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }

    // El penúltimo nodo ahora será el último
    second_last->next = NULL;

    // Colocamos el último nodo al principio
    last->next = *a;
    *a = last;

    // Imprimimos el movimiento
    ft_printf("rra\n");
}
