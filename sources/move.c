/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:10:04 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 21:20:21 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move_rarb(t_list **a, t_list **b, int value)
{
	while ((*b)->content != value && ft_find_target_a(*a, value) > 0)
		ft_rr(a, b, 0);
	while ((*b)->content != value)
		ft_rb(b, 0);
	while (ft_find_target_a(*a, value) > 0)
		ft_ra(a, 0);
	ft_push_to_a(a, b, 0);
	return (-1);
}

int	ft_move_rrarb(t_list **a, t_list **b, int value)
{
	while ((*b)-> content != value)
		ft_rb(b, 0);
	while (ft_find_target_a(*a, value) > 0)
		ft_rra(a, 0);
	ft_push_to_a(a, b, 0);
	return (-1);
}

int	ft_move_rarrb(t_list **a, t_list **b, int value)
{
	while ((*b)-> content != value)
		ft_rrb(b, 0);
	while (ft_find_target_a(*a, value) > 0)
		ft_ra(a, 0);
	ft_push_to_a(a, b, 0);
	return (-1);
}

int	ft_move_rrarrb(t_list **a, t_list **b, int value)
{
	while ((*b)-> content != value && ft_find_target_a(*a, value) > 0)
		ft_rrr(a, b, 0);
	while ((*b)-> content != value)
		ft_rrb(b, 0);
	while (ft_find_target_a(*a, value) > 0)
		ft_rra(a, 0);
	ft_push_to_a(a, b, 0);
	return (-1);
}

/*
int	ft_move_rarb(t_list **a, t_list **b, int value)
{
	// Rotate both a and b while the top of b doesn't 
	contain the target value and there are still elements to process
	while ((*b)->content != value && ft_find_target_a(*a, value) > 0)
		ft_rr(a, b, 0);

	// Rotate b until we find the target value
	while ((*b)->content != value)
		ft_rb(b, 0);

	// Rotate a until the target is correctly placed in a
	while (ft_find_target_a(*a, value) > 0)
		ft_ra(a, 0);

	// Push the element from b to a
	ft_push_to_a(a, b, 0);

	return -1;  // The function seems to return -1 as a marker of completion
}
*/