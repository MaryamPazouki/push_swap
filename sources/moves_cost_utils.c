#include "push_swap.h"


// This function calculates the required amount of rotation.

// Calculations are done for ra+rb cas
int ft_cost_rarb(t_list *a, t_list *b, int value)
{
    int target_position_a;
    int value_position_b;
    int cost;

    cost = 1; // Account for the `pa` operation
    target_position_a = ft_find_target_a(a, value);
    value_position_b = ft_find_position(b, value);
    
    // If positions are different, choose the larger one for rotation
    cost += (target_position_a > value_position_b) ? target_position_a : value_position_b;
    printf("ft_cost_rarb: Value=%d, Target A=%d, Position B=%d, Cost=%d\n", value, target_position_a, value_position_b, cost);
    return cost;
}


// Calculations are done for rra+rrb case.
int ft_cost_rrarrb(t_list *a, t_list *b, int value)
{
    int dist_a;
    int dist_b;
    int cost;

    cost = 1; // Account for the `pa` operation
    dist_a = ft_lstsize(a) - ft_find_target_a(a, value);
    dist_b = ft_lstsize(b) - ft_find_position(b, value);
    
    // Adjust cost based on valid positions
    if (dist_a > 0) cost += dist_a;
    if (dist_b > 0) cost += dist_b;

    return cost;
}

int ft_cost_rarrb(t_list *a, t_list *b, int value)
{
    int target_position_a;
    int value_position_b;
    int cost;

    target_position_a = ft_find_target_a(a, value);
    value_position_b = ft_find_position(b, value);

    cost = 0;
    if (value_position_b > 0) {
        cost = ft_lstsize(b) - value_position_b + 1;  // Handle `rrb`
    }
    cost += target_position_a;
    return(cost);
}


int ft_cost_rrarb(t_list *a, t_list *b, int value)
{
    int target_position_a;
    int value_position_b;
    int cost;

    target_position_a = ft_find_target_a(a, value);
    value_position_b = ft_find_position(b, value);

    cost = 0;
    if (target_position_a > 0) {
        cost = ft_lstsize(a) - target_position_a + 1;  // Handle `rra`
    }
    cost += value_position_b;
    return(cost);
}
