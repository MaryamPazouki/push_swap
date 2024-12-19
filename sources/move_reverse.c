/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:23:09 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 22:24:24 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse(t_list **stack)
{
	t_list	*prev;
	t_list	*current;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	prev = NULL;
	current = *stack;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = *stack;
	*stack = current;
}

void	ft_reverse_and_log(t_list **stack, int j, const char *log_message)
{
	if (stack && *stack && (*stack)->next)
	{
		ft_reverse(stack);
		if (j == 0 && log_message)
			write(1, log_message, ft_strlen(log_message));
	}
}

void	ft_rra(t_list **a, int j)
{
	ft_reverse_and_log(a, j, "rra\n");
}

void	ft_rrb(t_list **b, int j)
{
	ft_reverse_and_log(b, j, "rrb\n");
}

void	ft_rrr(t_list **a, t_list **b, int j)
{
	int	rotated;

	rotated = 0;
	if (a && *a && (*a)->next)
	{
		ft_reverse(a);
		rotated = 1;
	}
	if (b && *b && (*b)->next)
	{
		ft_reverse(b);
		rotated = 1;
	}
	if (j == 0 && rotated)
		write(1, "rrr\n", 4);
}
