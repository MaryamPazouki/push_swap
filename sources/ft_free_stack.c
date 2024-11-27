#include "push_swap.h"

void ft_free(t_list **stack)
{
    t_list *current;
    t_list *next;

    if (stack == NULL || *stack == NULL)
        return;
    
    current = *stack;
    while(current)
    {
        next = current ->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}