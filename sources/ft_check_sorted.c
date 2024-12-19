/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:43:16 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 17:13:44 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack -> next;
		while (temp)
		{
			if (stack -> content > temp-> content)
			{
				return (0);
			}
			temp = temp -> next;
		}
		stack = stack -> next;
	}
	ft_error();
	return (0);
}
