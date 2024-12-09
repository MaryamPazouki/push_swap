#include "push_swap.h"

//Converts a string to an integer, handling spaces, signs, and overflows.

int	ft_atoi_long(const char *str)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;

	// Skip whitespace characters
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;

	// Handle optional sign
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;

	// Convert characters to integer
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error(); // Invalid character
		result = result * 10 + (*str - '0');
		if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
			ft_error(); // Overflow
		str++;
	}

	return (int)(sign * result);
}

//Fills a stack with integers from a sequence of strings.

t_list	*ft_fill_stack(t_list *stack, char **sequence, int start_index)
{
	int		i;
	long		value; // Pointer to hold allocated integer.

	i = start_index;
	while (sequence[i])
	{
		value = ft_atoi_long(sequence[i]); // Assign the integer value.
		ft_lstadd_back(&stack, ft_lstnew(value)); // Pass the pointer to ft_lstnew.
		i++;
	}
	return (stack);
}


int ft_check_duplicates(t_list *stack)
{
	t_list *current;
	t_list *checker;


	current = stack;
	while(current)
	{
		checker = current->next;
		while(checker)
		{
			if (checker->content == current -> content)
				return(1);
			checker = checker -> next;
		}
		current = current -> next;
	}
	return(0);
}

/**
 * Processes command-line arguments to initialize a stack.
 * Handles both single-quoted input (argc == 2) and multiple arguments (argc > 2).
 */
t_list *ft_preprocess(int argc, char **argv)
{
    t_list *stack;
    char **split_sequence;

    stack = NULL;

    if (argc < 2)
        ft_error(); // No input provided

    if (argc == 2)
    {
        // Handle single quoted string
        split_sequence = ft_split(argv[1], ' ');
        if (!split_sequence)
            ft_error(); // Allocation error

        stack = ft_fill_stack(stack, split_sequence, 0);
        
        // Free each string in the split sequence array
        ft_freestr(split_sequence); // Assuming ft_freestr frees each string in the array
        // free(split_sequence); // Free the array itself
    }
    else
    {
        // Handle multiple arguments
        stack = ft_fill_stack(stack, argv, 1); // Skip argv[0] (program name)
    }

    // Check for duplicate values in the stack
    if (ft_check_duplicates(stack))
        ft_error(); // Duplicate found, terminate with error

    return stack;
}

