/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:23:21 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 22:23:26 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_a(t_list **a, t_list **b, int j)
{
	t_list	*temp;

	if (b == NULL || *b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ft_push_to_b(t_list **a, t_list **b, int j)
{
	t_list	*temp;

	if (a == NULL || *a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (j == 0)
		write(1, "pb\n", 3);
}
