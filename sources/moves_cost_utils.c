#include "push_swap.h"

// This function rotates both stack_a and stack_b
// in the same direction as required amount.
int	ft_cost_rarb(t_list **a, t_list **b, int c)
{
	while ((*b)->content != c && ft_find_target_a(*a, c) > 0)
			ft_rr(a, b, 0);
	while ((*b)->content != c)
			ft_rb(b, 0);
	while (ft_find_target_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_push_to_a(a, b, 0);
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
int	ft_cost_rrarrb(t_list **a, t_list **b, int c)
{
	
	while ((*b)->content != c && ft_find_target_a(*a, c) > 0)
			ft_rrr(a, b, 0);
	while ((*b)->content != c)
			ft_rrb(b, 0);
	while (ft_find_target_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_push_to_a(a, b, 0);
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
int	ft_cost_rrarb(t_list **a, t_list **b, int c)
{
	while (ft_find_target_a(*a, c) > 0)
			ft_rra(a, 0);
	while ((*b)->content != c)
			ft_rb(b, 0);
		ft_push_to_a(a, b, 0);
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
int	ft_cost_rarrb(t_list **a, t_list **b, int c)
{
	while (ft_find_target_a(*a, c) > 0)
			ft_ra(a, 0);
	while ((*b)->content != c)
			ft_rrb(b, 0);
		ft_push_to_a(a, b, 0);
	return (-1);
}





/* #include "push_swap.h"


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
*/