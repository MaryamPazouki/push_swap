/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cost_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:10:10 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 21:41:52 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_cost_rarb(t_list *a, t_list *b, int value)
{
	int	target_position_a;
	int	value_position_b;
	int	cost;

	cost = 1;
	target_position_a = ft_find_target_a(a, value);
	value_position_b = ft_find_index(b, value);
	if (target_position_a > value_position_b)
		cost += target_position_a;
	else
		cost += value_position_b;
	return (cost);
}

int	ft_cost_rrarrb(t_list *a, t_list *b, int value)
{
	int	dist_a;
	int	dist_b;
	int	cost;

	cost = 1;
	dist_a = ft_lstsize(a) - ft_find_target_a(a, value);
	dist_b = ft_lstsize(b) - ft_find_index(b, value);
	if (dist_a > 0)
		cost += dist_a;
	if (dist_b > 0)
		cost += dist_b;
	return (cost);
}

int	ft_cost_rarrb(t_list *a, t_list *b, int value)
{
	int	target_position_a;
	int	value_position_b;
	int	cost;

	target_position_a = ft_find_target_a(a, value);
	value_position_b = ft_find_index(b, value);
	cost = 1;
	if (value_position_b > 0)
	{
		cost += (ft_lstsize(b) - value_position_b);
	}
	cost += target_position_a;
	return (cost);
}

int	ft_cost_rrarb(t_list *a, t_list *b, int value)
{
	int	target_position_a;
	int	value_position_b;
	int	cost;

	target_position_a = ft_find_target_a(a, value);
	value_position_b = ft_find_index(b, value);
	cost = 1;
	if (target_position_a > 0)
	{
		cost += (ft_lstsize(a) - target_position_a);
	}
	cost += value_position_b;
	return (cost);
}

/*// Calculations are done for ra+rb cas
int ft_cost_rarb(t_list *a, t_list *b, int value)
{
	int target_position_a;
	int value_position_b;
	int cost;

	cost = 1; // Account for the `pa` operation
	target_position_a = ft_find_target_a(a, value);
	value_position_b = ft_find_index(b, value);
	
	// If positions are different, choose the larger one for rotation
	cost += (target_position_a > value_position_b) 
	? target_position_a : value_position_b;
	return cost;
}*/