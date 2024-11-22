#include<stdio.h>
#include<stdlib.h>





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
void radix_sort(t_list **a, t_list **b, int size) {
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
void turk_sort(t_list **a, t_list **b, int size, int num_chunks) 
{
    int base_chunk_size = size / num_chunks;
    int remaining = size % num_chunks; // Handle uneven division
    for (int chunk = 1; chunk <= num_chunks; chunk++) 
    {
        int chunk_size = base_chunk_size + (chunk == num_chunks ? remaining : 0);
        printf("\nProcessing Chunk %d:\n", chunk);

        int processed = 0;
        int total_rotations = 0;

        // Ensure we don't process more elements than the stack has
        while (processed < chunk_size && *a) {
            if ((*a)->content <= chunk * base_chunk_size) {
                push(b, pop(a)); // Push to stack 'b' if within chunk range
                processed++;
            } else {
                push(a, pop(a)); // Rotate within stack 'a'
            }
            total_rotations++;
        }
    }
}