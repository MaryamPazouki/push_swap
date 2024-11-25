#include "push_swap.h"


// Function to sort a stack of 3 numbers
void sort_three_numbers(t_list **a)
{
    int first = (*a)->content;
    int second = (*a)->next->content;
    int third = (*a)->next->next->content;

    if (first > second && second < third && first < third)
    {
        ft_sa(a); // 2 1 3 -> 1 2 3
        return;
    }

    if (first < second && second > third && first < third)
    {
        ft_ra(a); // 2 3 1 -> 1 2 3
        return;
    }

    if (first > second && second > third)
    {
        ft_sa(a); // 3 2 1 -> 2 1 3
        ft_rra(a); // 2 1 3 -> 1 2 3
        return;
    }

    if (first > second && second < third && first > third)
    {
        ft_rra(a); // 3 1 2 -> 1 2 3
        return;
    }

    if (first < second && second > third && first > third)
    {
        ft_ra(a); // 1 3 2 -> 3 2 1 -> 2 1 3
        ft_ra(a);
        ft_sa(a); // 2 1 3 -> 1 2 3
        return;
    }
}