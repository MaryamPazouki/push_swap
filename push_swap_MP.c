#include<stdio.h>
#include<stdlib.h>



// Define a linked list node
typedef struct s_list
{
    int content;
    t_list *next;
}t_list; 


void swap_stack(t_list **stack) 
{
    if (*stack == NULL || (*stack) -> next == NULL)
        return;
    t_list *first;
    t_list *second;

    // Pointers to the first and second nodes
    first = *stack;
    second = first->next;

    // Perform the swap
    first->next = second->next; // Link the first node to the node after the second
    second->next = first;       // Link the second node to the first
    *stack = second;            // Update the stack's top pointer to point to the new top (second node)
}

void ss(t_list **stack_a, t_list **stack_b)
{
    swap_stack(stack_a);
    swap_stack(stack_b);
}


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

//----------------------------------------------------------

// Function to get the maximum value in a stack
int get_max(t_list *stack)
{
    int max;

    max = stack -> content;
    while (stack)
    {           
        if(stack-> content > max)
        {
            max = stack -> content;
        }
        stack = stack -> next;
    }
}


// Count the number of bits in the largest number
int get_max_bits(t_list *stack)
{
    int  max;
    
    max = get_max(stack);
    int bits = 0;
    while(max)
    {
        max >>= 1;
        bits++;
    }
    return(bits);
}




////--------------------sorting alg -----------------------------------


// Radix sort using two stacks
void radix_sort(t_node **a, t_node **b, int size) {
    int max_bits = get_max_bits(*a);
    for (int i = 0; i < max_bits; i++) {
        for (int j = 0; j < size; j++) {
            int num = pop(a);
            if (((num >> i) & 1) == 1)
                push(a, num); // Keep in stack 'a'
            else
                push(b, num); // Move to stack 'b'
        }
        while (*b)
            push(a, pop(b)); // Move everything back to stack 'a'
    }
}

// Split into chunks using the Turk algorithm
void turk_sort(t_node **a, t_node **b, int size, int num_chunks) {
    int base_chunk_size = size / num_chunks;
    int remaining = size % num_chunks; // Handle uneven division
    for (int chunk = 1; chunk <= num_chunks; chunk++) {
        int chunk_size = base_chunk_size + (chunk == num_chunks ? remaining : 0);
        printf("\nProcessing Chunk %d:\n", chunk);

        int processed = 0;
        int total_rotations = 0;

        // Ensure we don't process more elements than the stack has
        while (processed < chunk_size && *a) {
            if ((*a)->value <= chunk * base_chunk_size) {
                push(b, pop(a)); // Push to stack 'b' if within chunk range
                processed++;
            } else {
                push(a, pop(a)); // Rotate within stack 'a'
            }
            total_rotations++;
        }