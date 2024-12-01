#include "push_swap.h"

int ft_find_index(t_list *stack, int value) 
{
    int i = 0;

    while (stack) {
        if (stack->content == value)
            return i; // Return the position if found
        stack = stack->next;
        i++;
    }

    // Value not found
    return -1;
}


/*
int	ft_find_index(t_list *a, int nbr)
{
	int		i;

	i = 0;
	while (a->content != nbr)
	{
		i++;
		a = a->next;
	}
	a->index = 0;
	return (i);
}
*/
