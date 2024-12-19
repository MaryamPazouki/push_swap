/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:08:03 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 17:21:40 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **stack)
{
	t_list	*current;
	t_list	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		next = current ->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
