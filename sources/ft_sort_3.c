#include "push_swap.h"


// Function to sort a stack of 3 numbers
void sort_three_numbers(t_list **a)
{
    int first = (*a)->content;
    int second = (*a)->next->content;
    int third = (*a)->next->next->content;

    if (first < second && second < third)
        return; // Already sorted

    if (first > second && second < third && first < third)
    {
        sa(a); // 2 1 3 -> 1 2 3
        return;
    }

    if (first < second && second > third && first < third)
    {
        ra(a); // 2 3 1 -> 1 2 3
        return;
    }

    if (first > second && second > third)
    {
        sa(a); // 3 2 1 -> 2 1 3
        rra(a); // 2 1 3 -> 1 2 3
        return;
    }

    if (first > second && second < third && first > third)
    {
        rra(a); // 3 1 2 -> 1 2 3
        return;
    }

    if (first < second && second > third && first > third)
    {
        ra(a); // 1 3 2 -> 3 2 1 -> 2 1 3
        sa(a); // 2 1 3 -> 1 2 3
        return;
    }
}