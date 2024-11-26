#include "push_swap.h"


// This function calculates the required amount of rotation.

// Calculations are done for ra+rb case.
int ft_cost_rarb(t_list *a, t_list *b, int value)
{
    int target_position_a;
    int value_position_b;

    target_position_a = ft_find_target_a(a, value);
    value_position_b = ft_find_position(b, value);
    if (target_position_a < value_position_b)
        target_position_a = value_position_b;
    return(target_position_a);
}

// Calculations are done for rra+rrb case.
int ft_cost_rrarrb(t_list *a, t_list *b, int value)
{
    int dist_a;
    int dist_b;
    int cost;

    cost = 0;
    dist_a = ft_lstsize(a) - ft_find_target_a(a, value);
    dist_b = ft_lstsize(b) - ft_find_position(b, value);
    if (ft_find_target_a(a, value))
        cost = dist_a;
    if ((cost < dist_b) && ft_find_position(b, value))
        cost = dist_b;
    return(cost);
}

// Calculations are done for ra+rrb case.
int ft_cost_rarrb(t_list *a, t_list *b, int value)
{
    int target_position_a;
    int value_position_b;
    int cost;

    target_position_a = ft_find_target_a(a, value);
    value_position_b = ft_find_position(b, value);
    cost = 0;

    if (value_position_b)
        cost = ft_lstsize(b) - value_position_b;
    cost += target_position_a;
    return(cost); 
}

// Calculations are done for rra+rb case.
int ft_cost_rrarb(t_list *a, t_list *b, int value)
{
    int target_position_a;
    int value_position_b;
    int cost;

    target_position_a = ft_find_target_a(a, value);
    value_position_b = ft_find_position(b, value);
    cost = 0;

    if (target_position_a)
        cost = ft_lstsize(a) - target_position_a;
    cost += value_position_b;
    return(cost); 
}