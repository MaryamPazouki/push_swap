#include "push_swap.h"

t_list *ft_push_alltill3_ab(t_list **a, t_list *b)
{
    int size_a;

    size_a = ft_lstsize(*a); 
    if (!ft_check_sorted(*a))
    {
        while(size_a-- > 3)
        {
            ft_push_to_b(a, b, 1);
            size_a--;
        }
    }
    return (b);  // Return the address of b, which is a pointer to the stack b
}


t_list **ft_sort_a(t_list **a, t_list **b)
{
    char *opt_cost;
    t_list *temp;

    temp = *b;
    while (temp) {
        opt_cost = ft_optimal_cost(*a, *b);  // Get the optimal move

        if (ft_strcmp(opt_cost, "rarb") == 0)
            ft_move_rarb(*a, *b, (*b)->content); 
        else if (ft_strcmp(opt_cost, "rrarb") == 0)
            ft_move_rrarb(*a, *b, (*b)->content);
        else if (ft_strcmp(opt_cost, "rarrb") == 0)
            ft_move_rarrb(*a, *b, (*b)->content);
        else if (ft_strcmp(opt_cost, "rrarrb") == 0)
            ft_move_rrarrb(*a, *b, (*b)->content);
        else
            temp = temp->next;  // Move to the next element
    }
    return a;  // Return the address of a, which is a pointer to the stack a
}


t_list *ft_last_sort_a(t_list **a)
{
    int i;

    i = ft_find_position(a, ft_min(*a));

	if (i < ft_lstsize(a) / 2)
	{
		while ((*a)->content != ft_min(*a))
		    ft_ra(a, 0);
	}
	else
	{
		while ((*a)->content != ft_min(*a))
		    ft_rra(a, 0);
	}
    return(*a);			
}


void ft_sort(t_list **stack_a)
{
    t_list *stack_b;

    stack_b = NULL;

    if (ft_lstsize(*stack_a) == 2)
        ft_sa(stack_a, 0);
    else
    {   
        stack_b = ft_push_alltill3_ab(stack_a, stack_b);
        stack_a = ft_sort_a(stack_a, &stack_b);
        stack_a = ft_last_sort_a(stack_a);
    }
}