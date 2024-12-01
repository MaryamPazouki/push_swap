
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	
	// here we check all aspect of correct arguments
	a = ft_preprocess(argc, argv);
	if (!a)
	{
		ft_free(&a);
		ft_error();
	}
	// check if stack a is already sorted! 
	if (!ft_check_sorted(a))
		ft_sort(&a);
	
	t_list *temp = a;
    while (temp)
    {
        printf("%ld ", temp->content); // Print the content of each node
        temp = temp->next;            // Move to the next node
    }
    printf("\n");

	ft_free(&a);
	return (0);
}

// ARG=$(shuf -i 1-1000 -n 700) && ./push_swap $ARG | wc -l