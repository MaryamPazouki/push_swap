#include "push_swap.h"


int ft_find_pos(t_list *stack, int nbr)
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




// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.
