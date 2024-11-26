#include "push_swap.h"



int ft_move_rarb(t_list *a, t_list*b, int value)
{
    while ((*b)-> content != value && ft_find_target_a(*a, value) > 0 )
        ft_rr(a, b, 0);
    while ((*b)-> content != value)
        ft_rb(b, 0);
    while (ft_find_target_a(*a, value) > 0)
        ft_ra(a,0);
    ft_push_to_a(a, b, 0);
    return(-1);
}

int ft_move_rrarb(t_list *a, t_list *b, int value)
{
    while((*b)-> content != value)
        ft_rb(b, 0);
    while (ft_find_target_a(*a, value) > 0)
        ft_rr(a,0);
    ft_push_to_a(a,b,0);
    return(-1);
}

int ft_move_rarrb(t_list *a, t_list *b, int value)
{
    while((*b)-> content != value)
        ft_rrb(b, 0);
    while (ft_find_target_a(*a, value) > 0)
        ft_ra(a,0);
    ft_push_to_a(a,b,0);
    return(-1);
}


int ft_move_rrarrb(t_list *a, t_list*b, int value)
{
    while ((*b)-> content != value && ft_find_target_a(*a, value) > 0 )
        ft_rrr(a, b, 0);
    while ((*b)-> content != value)
        ft_rrb(b, 0);
    while (ft_find_target_a(*a, value) > 0)
        ft_rra(a,0);
    ft_push_to_a(a, b, 0);
    return(-1);
}