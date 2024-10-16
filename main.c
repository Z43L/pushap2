#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"



int	init_stack(pushswap *ps, int argc, char **argv)
{
	int		i;
	char	**split_values;
	long	value;
	t_node	*new_node;
	int		*values;
	int		count = 0;

	ps->stacka = NULL;
	ps->stackb = NULL;
	ps->size_a = 0;
	ps->size_b = 0;

	// Contar el número total de valores en todos los argumentos
	for (i = 1; i < argc; i++) {
		split_values = ft_split(argv[i], ' ');
		for (int j = 0; split_values[j]; j++) {
			count++;
		}
		free(split_values);
	}

	// Asignar un array para los valores
	values = malloc(count * sizeof(int));
	if (!values)
		return (0);

	// Procesar y agregar cada valor a stacka
	int k = 0;
	for (i = 1; i < argc; i++) {
		split_values = ft_split(argv[i], ' ');
		for (int j = 0; split_values[j]; j++) {
			value = ft_atol(split_values[j]);
            /* ft_printf("el valor añadido es %d \n", value); */
			if (value < INT_MIN || value > INT_MAX) {
				ft_putstr_fd("Error\n", 2);
				free(split_values);
				free(values);
				return (0);
			}
			values[k] = (int)value;
			new_node = create_node(values[k]);
			new_node->next = ps->stacka;
			ps->stacka = new_node;
			ps->size_a++;
			k++;
		}
		free(split_values);
	}

	// Verificar duplicados
	if (has_duplicates(values, count)) {
		ft_putstr_fd("Error\n", 2);
		free(values);
		return (0);
	}
	free(values);
	return (1);
}

// free_stack.c
void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
int is_sorted(t_node *stack)
{
    t_node *current = stack;

    while (current != NULL && current->next != NULL)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }

    return 1;
}

void printstaka(t_node *stacka)
{
    t_node *current = stacka;
    
    ft_printf("el stack ordenado es: ");
    while (current != NULL)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
   

}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s numbers...\n", argv[0]);
        return 1;
    }

    pushswap ps;
    ps.stacka = NULL;
    ps.stackb = NULL;

    // Parse input numbers and create stack a
    for (int i = argc - 1; i > 0; i--) {
        int value = atoi(argv[i]);
        t_node *new_node = malloc(sizeof(t_node));
        new_node->value = value;
        new_node->next = ps.stacka;
        ps.stacka = new_node;
    }

    if (issorted(ps.stacka)) {
        printf("Stack is already sorted.\n");
        return 0;
    }
    while (issorted(ps.stacka)==0 ) {
        algo(&ps);
    }

    printstaka(ps.stackb);
    // Free the stacks
    t_node *current;
    while (ps.stacka) {
        current = ps.stacka;
        ps.stacka = ps.stacka->next;
        free(current);
    }
    while (ps.stackb) {
        current = ps.stackb;
        ps.stackb = ps.stackb->next;
        free(current);
    }

    return 0;
}
