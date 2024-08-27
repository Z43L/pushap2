# ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "LIBFT/libft.h"
#include "FT_PRINTF/src/ft_printf.h"


typedef struct s_node {
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_pushswap {
    t_node *stacka;
    t_node *stackb;
    int size_a;
    int size_b;
} t_pushswap;



void pa(t_pushswap *ps) ;
void pb(t_pushswap *ps) ;
void ra(t_pushswap *ps) ;
t_pushswap rb(t_pushswap pushswap);
t_pushswap rr(t_pushswap pushswap);
t_pushswap rra(t_pushswap pushswap);
t_pushswap rrb(t_pushswap pushswap);
t_pushswap rrr(t_pushswap pushswap);
t_pushswap sa(t_pushswap pushswap);
t_pushswap sb(t_pushswap pushswap);
t_pushswap ss(t_pushswap pushswap);
int get_max_bits(t_pushswap *ps);
void radix_sort(t_pushswap *ps) ;
int lenstackb(t_pushswap pushswap);
int lenstacka(t_pushswap pushswap);
void print_stack(int *stack, int size, char name);

#endif