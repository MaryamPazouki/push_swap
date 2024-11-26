#include "push_swap.h"


int ft_find_position(t_list *stack, int nbr)
{
    int i = 0;

    // Traverse the stack to find the number
    while (stack)
    {
        if (stack->content == nbr)
            return i; // Return the position if found
        stack = stack->next;
        i++;
    }

    // If the number is not found, return -1
    return -1;
}

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

// Find the position for nbr_push in the stack, based on stack_a logic
int ft_find_place_a(t_stack *stack_a, int push_value) 
{
    if (!stack_a)
        return -1;

    t_stack *current = stack_a;
    t_stack *next = stack_a->next;
    int i = 0;

    if (push_value > ft_max(stack_a) || push_value < ft_min(stack_a)) {
        // Place before the minimum value
        return ft_find_position(stack_a, ft_min(stack_a));
    }

    while (current && next)
    {
        if (current->nbr > push_value && next->nbr < push_value)
            return i + 1; // Return the index of the next node
        current = next;
        next = next->next;
        i++;
    }
    return 0; // Default to placing at the top
}
