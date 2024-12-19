/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:22:25 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 22:24:45 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*stack_last;

	if (*stack == NULL || (*stack)-> next == NULL)
		return ;
	first = *stack;
	stack_last = *stack;
	while (stack_last -> next != NULL)
		stack_last = stack_last -> next;
	stack_last -> next = first;
	*stack = first -> next;
	first -> next = NULL;
}

void	ft_ra(t_list **a, int j)
{
	ft_rotate(a);
	if (j == 0)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int j)
{
	ft_rotate(b);
	if (j == 0)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **a, t_list **b, int j)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ft_rotate(a);
	ft_rotate(b);
	if (j == 0)
		write(1, "rr\n", 3);
}
