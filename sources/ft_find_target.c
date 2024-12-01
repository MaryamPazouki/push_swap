
#include "push_swap.h"

int ft_find_target_a(t_list *stack_a, int push_value) 
{
    if (!stack_a)
        return -1; // Invalid case, return error code

    t_list *current_node = stack_a;
    int i = 0;
    int min_value = ft_min(stack_a);
    int max_value = ft_max(stack_a);

    // Case: Value is larger than the max or smaller than the min -> Place before the min
    if (push_value > max_value || push_value < min_value) {
        int pos = ft_find_position(stack_a, min_value);
        printf("Push value %d > max (%d) or < min (%d). Target position: %d\n", 
               push_value, max_value, min_value, pos);
        return pos;
    }

    // Traverse the stack to find the correct insertion point
    while (current_node->next) {
        if (current_node->content < push_value && current_node->next->content > push_value) 
        {
            printf("Push value %d fits between %ld and %ld. Target position: %d\n", 
                   push_value, current_node->content, current_node->next->content, i + 1);
            return i + 1;
        }
        current_node = current_node->next;
        i++;
    }

    // If we reach the end of the list, the value belongs after the last node
    if (current_node->content < push_value) {
        printf("Push value %d belongs after %ld. Target position: %d\n", 
               push_value, current_node->content, i + 1);
        return i + 1;
    }

    return 0; // Default to the top of the stack
}










/*
int	ft_find_target_a(t_list *stack_a, int push_value)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (push_value < stack_a->content && push_value > ft_lstlast(stack_a)->content)
		i = 0;
	else if (push_value > ft_max(stack_a) || push_value < ft_min(stack_a))
		i = ft_find_position(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->content > push_value || tmp->content < push_value)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}*/







/*int ft_find_target_a(t_list *stack_a, int push_value) 
{
    if (!stack_a)
        return -1; // Invalid case, return error code

    t_list *current_node = stack_a;
    int i = 0;
    int min_value = ft_min(stack_a);
    int max_value = ft_max(stack_a);

    // Case: Value is larger than the max or smaller than the min -> Place before the min
    if (push_value > max_value || push_value < min_value) 
    {
        int min_pos = ft_find_position(stack_a, min_value);
        // printf("Push value %d -> Insert before min (%d) at position %d\n", push_value, min_value, min_pos);
        return min_pos;
    }

    // Traverse the stack to find the correct insertion point
    while (current_node->next) {
        if (current_node->content < push_value && current_node->next->content > push_value)
            return i + 1; // Found the target position
        current_node = current_node->next;
        i++;
    }

    // If we reach the end of the list, the value belongs after the last node
   if (current_node->content < push_value)
        return i + 1;

    // Default to the top of the stack if no position is found
    return 0;
}
*/



// Find the position for value to push in the stack a from stack b, based on stack_a logic
/* int ft_find_target_a(t_list *stack_a, int push_value) 
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
*/





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