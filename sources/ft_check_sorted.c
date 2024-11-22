#include "push_swap.h"

int ft_check_sorted(t_list *stack)
{
    t_list *temp;

    while(stack)
    {
        temp = stack -> next;
        while(temp)
        {
            if (stack -> content >  temp-> content)
            {
                return(0);
            }
            temp= temp -> next;
        }
        stack = stack -> next;    
    }
    ft_error();  // Trigger error if the stack is already sorted
    return (0);  // This line is never reached but added for completeness
}