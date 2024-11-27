#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}


t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while ((lst -> next != NULL))
	{
		lst = lst -> next;
	}
	return (lst);
}



int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}


t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}


void	ft_freestr(char **str_array)
{
	int	i;

	if (!str_array)
		return;
	i = 0;
	while (str_array[i])
	{
		free(str_array[i]); // Free each string in the array
		i++;
	}
	free(str_array); // Free the array itself
}


int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2) 
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2); 
}
