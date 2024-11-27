
#include "push_swap.h"

// Find the position for value to push in the stack a from stack b, based on stack_a logic
int ft_find_target_a(t_list *stack_a, int push_value) 
{
    if (!stack_a)
        return -1;

    t_list *current_node = stack_a;
    t_list *next_node = stack_a->next;
    int i = 0;

    if (push_value > ft_max(stack_a) || push_value < ft_min(stack_a)) {
        // Place before the minimum value
        return ft_find_position(stack_a, ft_min(stack_a));
    }

    while (current_node && next_node)
    {
        if (current_node -> content > push_value && next_node -> content < push_value)
            return i + 1; // Return the index of the next node
        current_node = next_node;
        next_node = next_node -> next;
        i++;
    }
    return 0; // Default to placing at the top
}






/*

// Find the position for nbr_push in the stack, based on stack_b logic
int ft_find_place_b(t_stack *stack_b, int push_value) {
    if (!stack_b)
        return -1;

    t_stack *current = stack_b;
    t_stack *next = stack_b->next;
    int i = 0;

    if (push_value > ft_max(stack_b) || push_value < ft_min(stack_b)) {
        // Place after the maximum value
        return ft_find_position(stack_b, ft_max(stack_b));
    }

    while (current && next) {
        if (current->content < push_value && next->content > push_value)
            return i + 1; // Return the index of the next node
        current = next;
        next = next->next;
        i++;
    }
    return 0; // Default to placing at the top
}
*/