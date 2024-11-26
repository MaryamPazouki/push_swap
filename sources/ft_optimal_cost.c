#include "push_swap.h"

int ft_optimal_cost(t_list *a, t_list *b)
{
    int cost;
    t_list *temp;

    temp = b;    
    cost = ft_cost_rrarrb(a,b,temp->content); // initialize cost

    while(temp)
    {
        if (cost > ft_cost_rarb(a,b,temp->content))
            cost = ft_cost_rarb(a,b,temp->content);
        if (cost > ft_cost_rrarb(a,b,temp->content))
            cost = ft_cost_rrarb(a,b,temp->content);
        if (cost > ft_cost_rarrb(a,b,temp->content))
            cost = ft_cost_rarrb(a,b,temp->content);
        if (cost > ft_cost_rrarrb(a,b,temp->content)
            cost = ft_cost_rrarrb(a,b,temp->content);

        temp = temp -> next;
    }
    return(cost);
}