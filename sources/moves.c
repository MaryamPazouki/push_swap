
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
    ft_swap(a);  // Swap stack a
    ft_swap(b);  // Swap stack b
    if (j == 0)
        write(1, "ss\n", 3);  // Print "ss" for both stacks
}


// ------------------PUSH-------------------------------------------------------------

// both functions Pa and Pb : push_a and push_b
void push_stack(t_list **source, t_list **goal)
{
    
    if (*source == NULL || source == NULL)
        return;
    
    t_list *swap;

    swap = *source;

    *source = swap -> next;
    swap -> next = *goal;
    *goal = swap;
}


// rotate a and b: shift up all elements of stack a/b by 1. The first element becomes the last one.

void rotate_stack(t_list **stack)
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

//ra and rb at the same time.
void rr(t_list **stack_a, t_list **stack_b)
{
    rotate_stack(stack_a);
    rotate_stack(stack_b);
}


//reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.

void reverse_stack(t_list **stack) 
{
    // Handle edge cases: empty stack or a single-node stack
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_list *prev;
    t_list *current;

    prev = NULL;  // To keep track of the second-to-last node
    current = *stack;   // Pointer to traverse the stack

    // Traverse to the last node, keeping track of the second-to-last node
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


// rra and rrb at the same time.
void rrr(t_list **stack_a, t_list **stack_b)
{
    reverse_stack(stack_a);
    reverse_stack(stack_b);
}


//------------------------------ function to move and creat -------------------------
// Function to create a new node
t_list *new_node(int value)
{
    t_list *node;

    node = (t_list *) malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node -> content = value;
    node -> next = NULL;
}

// Push a value to the top of the stack
void push(t_list **stack, int value)
{
    t_list *node;

    node = new_node(value);
    node-> next = *stack;
    *stack = node;
}


// Pop a value from the top of the stack

int pop(t_list **stack)
{
    t_list *temp;
    int value;

    temp = *stack;
    value = temp-> content;
    *stack = temp ->next;
    free(temp);
    return value;
}
