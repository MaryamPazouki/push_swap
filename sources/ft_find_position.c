/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:07:42 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 17:17:12 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index(t_list *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == value)
			return (i);
		stack = stack->next;
		i++;
	}
	stack->index = 0;
	return (-1);
}

/*
int ft_find_index(t_list *stack, int value) 
{
	int i = 0;

	while (stack) {
		if (stack->content == value)
			return i; // Return the position if found
		stack = stack->next;
		i++;
	}
	stack->index = 0;
	// Value not found
	return -1;
}
*/
