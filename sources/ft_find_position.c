#include "push_swap.h"


int ft_find_position(t_list *stack, int value)
{
    int i = 0;

    // Traverse the stack to find the number
    while (stack)
    {
        if (stack->content == value)
            return i; // Return the position if found
        stack = stack->next;
        i++;
    }

    // If the number is not found, return -1
    return -1;
}

