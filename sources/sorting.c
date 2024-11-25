#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    int content;
    struct s_list *next;
} t_list;

// Function to push a value onto the stack
void push(t_list **stack, int value)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Function to pop the top element from the stack
int pop(t_list **stack)
{
    if (*stack == NULL)
        return -1;

    t_list *top = *stack;
    int value = top->content;
    *stack = top->next;
    free(top);
    return value;
}

// Function to swap the first two elements of the stack
void sa(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *first = *stack;
        t_list *second = (*stack)->next;
        first->next = second->next;
        second->next = first;
        *stack = second;
    }
}

// Function to rotate the stack (move the top element to the bottom)
void ra(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *first = *stack;
        t_list *last = *stack;
        while (last->next)
            last = last->next;
        *stack = first->next;
        first->next = NULL;
        last->next = first;
    }
}

// Function to reverse rotate the stack (move the bottom element to the top)
void rra(t_list **stack)
{
    if (*stack && (*stack)->next)
    {
        t_list *prev = NULL;
        t_list *last = *stack;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *stack;
        *stack = last;
    }
}

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

int main()
{
    t_list *a = NULL;

    // Example: 3 numbers to be sorted
    push(&a, 2);
    push(&a, 3);
    push(&a, 1);

    printf("Before sorting:\n");
    t_list *temp = a;
    while (temp)
    {
        printf("%d ", temp->content);
        temp = temp->next;
    }
    printf("\n");

    sort_three_numbers(&a);

    printf("After sorting:\n");
    temp = a;
    while (temp)
    {
        printf("%d ", temp->content);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
