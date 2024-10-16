# ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"
#include <stdio.h>

// Estructura del nodo
typedef struct s_node {
    int *arr;
    int size;
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_pushswap {
    t_node *stacka;
    t_node *stackb;
    int size_a;
    int size_b;
} pushswap;


/* typedef struct s_pushswap {
    t_stack *stacka;  // Puntero al stacka
    t_stack *stackb;  // Puntero al stackb
} pushswap;
 */
#define INT_MIN -2147483648
#define INT_MAX 2147483648

void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **stacka, t_node **stackb);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **stacka, t_node **stackb) ;
void sa(t_node **a);
void sb(t_node **b);
void ss(pushswap *ps);
int get_max_bits(int *stacka, int size);
void radix_sort(pushswap *ps);
int lenstackb(pushswap pushswap);
int lenstacka(pushswap pushswap);
void index_based_sort(pushswap *ps, int size);
void assign_indices(pushswap *ps);
void push_swap(pushswap *ps);
void print_stack(t_node *stack, char name);
void push(t_node **stack, int value);
void quicksort_b(pushswap *ps, int size);
void quicksort_a(pushswap *ps, int size);
void sort_small_stack_b(pushswap *ps, int size);
void sort_small_stack_a(pushswap *ps, int size);
int get_stack_size(t_node *stack);
int find_min_position(t_node *stack);
void cabeza(pushswap *ps);
t_node	*create_node(int value);
int	has_duplicates(int *array, int size);
long	ft_atol(const char *str);
int	is_number(const char *str);
int issorted(t_node *node);
void	insertion_sort(int *array, int size);
void algo(pushswap *ps);
int **chuncks(t_node *node, int num_chuncks, pushswap *ps);
int getsize(t_node *node);
void push_swap_with_chunks(pushswap *ps, int chunk_size);
#endif