/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:09:42 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 21:10:35 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_alltill3_ab(t_list **a, t_list **b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	while (size_a > 3)
	{
		ft_push_to_b(a, b, 0);
		size_a--;
	}
}

t_list	**ft_sort_a(t_list **a, t_list **b)
{
	t_list	*temp;
	int		opt_cost;

	while (*b)
	{
		temp = *b;
		opt_cost = ft_optimal_cost(*a, *b);
		while (opt_cost > 0)
		{
			if (opt_cost == ft_cost_rarb(*a, *b, temp->content))
				opt_cost = ft_move_rarb(a, b, temp->content);
			else if (opt_cost == ft_cost_rrarrb(*a, *b, temp->content))
				opt_cost = ft_move_rrarrb(a, b, temp->content);
			else if (opt_cost == ft_cost_rrarb(*a, *b, temp->content))
				opt_cost = ft_move_rrarb(a, b, temp->content);
			else if (opt_cost == ft_cost_rarrb(*a, *b, temp->content))
				opt_cost = ft_move_rarrb(a, b, temp->content);
			else
				temp = temp -> next;
		}
	}
	return (a);
}

void	ft_last_sort_a(t_list **a)
{
	int	i;

	i = ft_find_index(*a, ft_min(*a));
	if (i < ft_lstsize(*a) / 2)
	{
		while ((*a)->content != ft_min(*a))
			ft_ra(a, 0);
	}
	else
	{
		while ((*a)->content != ft_min(*a))
			ft_rra(a, 0);
	}
}

void	ft_sort(t_list **stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
	{
		printf("Sorting 2 elements...\n");
		ft_sa(stack_a, 0);
		return ;
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		sort_three_numbers(stack_a);
		return ;
	}
	else
	{
		ft_push_alltill3_ab(stack_a, &stack_b);
		sort_three_numbers(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		ft_last_sort_a(stack_a);
	}
}
