#include "push_swap.h"


/*
void ft_update_cost(t_list *a, t_list *b, int *cost, char **operation, 
                    int (*cost_function)(t_list *, t_list *, int), const char *op_name, int value) 
{
    int current_cost;
    
    current_cost = cost_function(a, b, value);

    if (current_cost < *cost) {
        *cost = current_cost;
        *operation = (char *)op_name; // Update operation to the new optimal one
    }
}


void ft_calculate_cost(t_list *a, t_list *b, int *cost, char **operation, int value) {
    // Check cost for each operation and update the optimal one
    ft_update_cost(a, b, cost, operation, ft_cost_rarb, "rarb", value);
    ft_update_cost(a, b, cost, operation, ft_cost_rrarb, "rrarb", value);
    ft_update_cost(a, b, cost, operation, ft_cost_rarrb, "rarrb", value);
    ft_update_cost(a, b, cost, operation, ft_cost_rrarrb, "rrarrb", value);
}


char *ft_optimal_cost(t_list *a, t_list *b) 
{
    t_list *temp;
    int cost;
    char *operation;

    temp = b;
    cost = ft_cost_rrarrb(a, b, temp->content); // Initialize with a default cost
    operation = "rrarrb"; // Default operation

    while (temp) {
        ft_calculate_cost(a, b, &cost, &operation, temp->content); // Check all costs
        temp = temp->next; // Move to the next node in stack `b`
    }

    return operation; // Return the optimal operation as a string
}

*/

int ft_optimal_cost(t_list *a, t_list *b)
{
    int cost;
    t_list *temp;

    temp = b;    
    cost = ft_cost_rrarrb(a,b,temp->content); // initialize cost
    printf("Calculating cost for value %ld: rarb=%d, rrarrb=%d, rarrb=%d, rrarb=%d\n", 
       temp->content, ft_cost_rarb(a,b,temp->content), ft_cost_rrarrb(a,b,temp->content), ft_cost_rarrb(a,b,temp->content), ft_cost_rrarb(a,b,temp->content));

    while(temp)
    {
        if (cost > ft_cost_rarb(a,b,temp->content))
            cost = ft_cost_rarb(a,b,temp->content);
        if (cost > ft_cost_rrarb(a,b,temp->content))
            cost = ft_cost_rrarb(a,b,temp->content);
        if (cost > ft_cost_rarrb(a,b,temp->content))
            cost = ft_cost_rarrb(a,b,temp->content);
        if (cost > ft_cost_rrarrb(a,b,temp->content))
            cost = ft_cost_rrarrb(a,b,temp->content);
        temp = temp -> next;
    }
    return(cost);
}
