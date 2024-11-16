#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Function declarations
void print_stack(t_node *stack, char name); // Add this declaration

// Function to create a new node
t_node *new_node(int value) {
    t_node *node = (t_node *)malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

// Push a value to the top of the stack
void push(t_node **stack, int value) {
    t_node *node = new_node(value);
    node->next = *stack;
    *stack = node;
}

// Pop a value from the top of the stack
int pop(t_node **stack) {
    if (!*stack)
        return -1;  // If the stack is empty, return -1
    t_node *temp = *stack;
    int value = temp->value;
    *stack = temp->next;
    free(temp);
    return value;
}

// Function to get the maximum value in a stack
int get_max(t_node *stack) {
    int max = stack->value;
    while (stack) {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

// Count the number of bits in the largest number
int get_max_bits(t_node *stack) {
    int max = get_max(stack);
    int bits = 0;
    while (max) {
        max >>= 1;
        bits++;
    }
    return bits;
}

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

        // Print stacks after chunk distribution
        printf("\nAfter distributing chunk %d:\n", chunk);
        print_stack(*a, 'A');
        print_stack(*b, 'B');

        // Sort the chunk using radix sort
        radix_sort(b, a, processed);

        // Print stacks after sorting the chunk
        printf("\nAfter sorting chunk %d:\n", chunk);
        print_stack(*a, 'A');
        print_stack(*b, 'B');
    }
}

// Print a stack
void print_stack(t_node *stack, char name) {
    printf("Stack %c: ", name);
    while (stack) {
        printf("%d ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

// Example main
int main() {
    t_node *a = NULL;
    t_node *b = NULL;

    // Example input
    push(&a, 329);
    push(&a, 457);
    push(&a, 657);
    push(&a, 839);
    push(&a, 436);
    push(&a, 720);
    push(&a, 355);

    printf("Initial Stacks:\n");
    print_stack(a, 'A');
    print_stack(b, 'B');

    // Perform Turk + Radix sort
    turk_sort(&a, &b, 7, 2); // 7 elements, 2 chunks

    printf("\nSorted Stacks:\n");
    print_stack(a, 'A');
    print_stack(b, 'B');

    return 0;
}
