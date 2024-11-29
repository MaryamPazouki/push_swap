#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

void ft_lstclear(t_list **lst) 
{
    t_list *tmp;

    if (!lst)
        return;
    while (*lst) {
        tmp = (*lst)->next;
        free(*lst); // Free the current node
        *lst = tmp;
    }
    *lst = NULL; // Set the list pointer to NULL
}



void ft_lstadd_back(t_list **lst, t_list *new) {
    t_list *last;

    if (!lst || !new)
        return;
    if (!(*lst)) {
        *lst = new; // If the list is empty, set the new node as the head
        return;
    }
    last = *lst;
    while (last->next)
        last = last->next;
    last->next = new;    // Set the new node as the last node's next
    new->prev = last;    // Update the new node's previous pointer
}


t_list *ft_lstnew(long content) {
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content; // Assign the value to content
    node->index = -1;        // Default index value
    node->next = NULL;       // Initialize pointers
    node->prev = NULL;
    return (node);
}



t_list *ft_lstlast(t_list *lst) {
    if (!lst)
        return (NULL);
    while (lst->next != NULL) {
        lst = lst->next;
    }
    return (lst);
}




int ft_lstsize(t_list *lst) {
    int size = 0;

    while (lst) {
        lst = lst->next;
        size++;
    }
    return (size);
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

/*
int ft_strcmp(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}

*/