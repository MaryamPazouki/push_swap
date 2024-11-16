#include<stdio.h>
#include<stdlib.h>

// Define a linked list node
typedef struct s_list
{
    int content;
    t_list *next;
}t_list;


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