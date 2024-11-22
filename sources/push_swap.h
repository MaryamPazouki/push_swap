#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_list
{
	long			content;
	long			index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// preprocessing functions

int		ft_atoi2(const char *str);
t_list	*ft_fill_stack(t_list *stack, char **sequence, int start_index);
int 	ft_check_duplicates(t_list *stack);
t_list	*ft_preprocess(int argc, char **argv);

void ft_error(void);






#endif