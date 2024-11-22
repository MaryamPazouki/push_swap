
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

	if (!ft_sorted(a))
		ft_sort(&a);



	ft_free(&a);
	return (0);
}