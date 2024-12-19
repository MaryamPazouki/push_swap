/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:21:39 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 22:24:16 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_sa(t_list **a, int j)
{
	ft_swap(a);
	if (j == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **b, int j)
{
	ft_swap(b);
	if (j == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list **b, int j)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	ft_swap(a);
	ft_swap(b);
	if (j == 0)
		write(1, "ss\n", 3);
}
