#include "push_swap.h"


int ft_max(t_list *stack)
{
    int max;

    if (!stack)
        return 0; 

    max = stack ->content;

    while(stack)
    {
        if (stack -> content > max)
            max = stack -> content;
        stack = stack -> next;
    }
    return (max);
}


int ft_min(t_list *stack)
{
    int min;

    if (!stack)
        return 0; 

    min = stack ->content;

    while(stack)
    {
        if (stack -> content < min)
            min = stack -> content;
        stack = stack -> next;
    }
    return (min);
}

