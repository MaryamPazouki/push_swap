#include "push_swap.h"

void ft_push_alltill3_ab(t_list **a, t_list **b) 
{
    int size_a;

    size_a = ft_lstsize(*a);
    while (size_a > 3) {
        ft_push_to_b(a, b, 1); // Push from stack_a to stack_b
        size_a--;
    }
}

void ft_sort_a(t_list **a, t_list **b) {
    t_list *temp;
    int opt_cost;

    while (*b) { // Continue until stack_b is empty
        temp = *b;
        opt_cost = ft_optimal_cost(*a, *b);

        if (opt_cost == ft_cost_rarb(*a, *b, temp->content))
            ft_move_rarb(a, b, temp->content);
        else if (opt_cost == ft_cost_rrarb(*a, *b, temp->content))
            ft_move_rrarb(a, b, temp->content);
        else if (opt_cost == ft_cost_rarrb(*a, *b, temp->content))
            ft_move_rarrb(a, b, temp->content);
        else if (opt_cost == ft_cost_rrarrb(*a, *b, temp->content))
            ft_move_rrarrb(a, b, temp->content);
    }
}

void ft_last_sort_a(t_list **a) {
    int i;

    i = ft_find_position(*a, ft_min(*a));
    if (i < ft_lstsize(*a) / 2) {
        while ((*a)->content != ft_min(*a))
            ft_ra(a, 0);
    } else {
        while ((*a)->content != ft_min(*a))
            ft_rra(a, 0);
    }
}

void ft_sort(t_list **stack_a) {
    t_list *stack_b = NULL;

    if (ft_lstsize(*stack_a) == 2) {
        ft_sa(stack_a, 0);
    } else {
        ft_push_alltill3_ab(stack_a, &stack_b); // Pass both stacks
        ft_sort_a(stack_a, &stack_b);          // Sort the stacks
        ft_last_sort_a(stack_a);               // Final adjustment
    }
}
