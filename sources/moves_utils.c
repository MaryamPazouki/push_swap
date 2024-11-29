
#include "push_swap.h"

// General swap function for any stack
// General swap function for any stack
void ft_swap(t_list **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_list *first = *stack;
    t_list *second = first->next;

    // Perform the swap
    first->next = second->next;  // Link the first node to the node after the second
    second->next = first;        // Link the second node to the first
    *stack = second;             // Update the stack's top pointer to point to the new top (second node)
}

// Swap two elements of stack a
void ft_sa(t_list **a, int j)
{
    ft_swap(a);  // Perform the swap
    if (j == 0)
        write(1, "sa\n", 3);  // Print the swap operation for stack a
}

// Swap two elements of stack b
void ft_sb(t_list **b, int j)
{
    ft_swap(b);  // Perform the swap
    if (j == 0)
        write(1, "sb\n", 3);  // Print the swap operation for stack b
}


// Swap both stack a and stack b at the same time
void ft_ss(t_list **a, t_list **b, int j)
{
    if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
    ft_swap(a);  // Swap stack a
    ft_swap(b);  // Swap stack b
    if (j == 0)
        write(1, "ss\n", 3);  // Print "ss" for both stacks
}


//------------------------rotate------------------------------------------------------------------------

// rotate a and b: shift up all elements of stack a/b by 1. The first element becomes the last one.

void ft_rotate(t_list **stack)
{
    // Handle edge cases: empty stack or a single-node stack
    if (*stack == NULL || (*stack) -> next == NULL)
        return; 

    t_list *first;  
    t_list *stack_last;

    first = *stack; // Store the first node
    stack_last = *stack;  // Initialize to find the last node

     // Traverse to the last node
    while(stack_last -> next != NULL)
    {
        stack_last = stack_last -> next; 
    }
   
    // Update the last node's next to point to the first node
    stack_last -> next = first;

    // Update the stack pointer to the new top
    *stack = first -> next;

    // Disconnect the first node
    first -> next = NULL;
}

// rotate two elements of stack b
void ft_ra(t_list **a, int j)
{
    ft_rotate(a);  // Perform the rotate
    if (j == 0)
        write(1, "ra\n", 3);  // Print the swap operation for stack a
}

// rotate two elements of stack b
void ft_rb(t_list **b, int j)
{
    ft_rotate(b);  // Perform the rotate
    if (j == 0)
        write(1, "rb\n", 3);  // Print the rotate operation for stack b
}


// rotate both stack a and stack b at the same time
void ft_rr(t_list **a, t_list **b, int j)
{
    if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
    ft_rotate(a);  // rotate stack a
    ft_rotate(b);  // rotate stack b
    if (j == 0)
        write(1, "rr\n", 3);  // Print "ss" for both stacks
}



//----------------------------------reverse-------------------------------------------------

// Reverse rotate: shift down all elements of a stack by 1
void ft_reverse(t_list **stack) 
{
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        return;

    t_list *prev = NULL;  
    t_list *current = *stack;

    // Traverse to the last node
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // Update the second-to-last node to disconnect the last node
    prev->next = NULL;

    // Make the last node the new head
    current->next = *stack;
    *stack = current;
}

// Helper function for reverse rotate with logging
void ft_reverse_and_log(t_list **stack, int j, const char *log_message) 
{
    if (stack && *stack && (*stack)->next) {
        ft_reverse(stack);
        if (j == 0 && log_message)
            write(1, log_message, ft_strlen(log_message));
    }
}

void ft_rra(t_list **a, int j)
{
    ft_reverse_and_log(a, j, "rra\n");
}

void ft_rrb(t_list **b, int j)
{
    ft_reverse_and_log(b, j, "rrb\n");
}

void ft_rrr(t_list **a, t_list **b, int j)
{
    int rotated = 0;

    if (a && *a && (*a)->next) {
        ft_reverse(a);
        rotated = 1;
    }
    if (b && *b && (*b)->next) {
        ft_reverse(b);
        rotated = 1;
    }

    if (j == 0 && rotated)
        write(1, "rrr\n", 4);
}

// ------------------PUSH-------------------------------------------------------------

// ft_pa - Push the top element of stack b onto stack a.
void ft_push_to_a(t_list **a, t_list **b, int j)
{
    t_list *temp;

    // Check if stack b is empty
    if (b == NULL || *b == NULL)
        return;

    // Pop the top element from stack b
    temp = *b;           // Store the top element of stack b
    *b = (*b)->next;     // Advance stack b's top pointer

    // Push the element onto stack a
    temp->next = *a;     // Link the popped element to the current top of stack a
    *a = temp;           // Update stack a's top pointer

    // Print the operation if j is 0
    if (j == 0)
        write(1, "pa\n", 3);
}

// ft_pb - Push the top element of stack a onto stack b.
void ft_push_to_b(t_list **a, t_list **b, int j)
{
    t_list *temp;

    // Check if stack a is empty
    if (a == NULL || *a == NULL)
        return;

    // Pop the top element from stack a
    temp = *a;           // Store the top element of stack a
    *a = (*a)->next;     // Advance stack a's top pointer

    // Push the element onto stack b
    temp->next = *b;     // Link the popped element to the current top of stack b
    *b = temp;           // Update stack b's top pointer

    // Print the operation if j is 0
    if (j == 0)
        write(1, "pb\n", 3);
}

