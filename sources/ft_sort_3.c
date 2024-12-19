/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:09:35 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 18:27:20 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)-> content;
	second = (*a)-> next -> content;
	third = (*a)-> next -> next -> content;
	if (first > second && second < third && first < third)
		ft_sa(a, 0);
	else if (first < second && second > third && first > third)
		ft_rra(a, 0);
	else if (first > second && second > third)
	{
		ft_ra(a, 0);
		ft_sa(a, 0);
	}
	else if (first > second && second < third && first > third)
		ft_ra(a, 0);
	else if (first < second && second > third && first < third)
	{
		ft_ra(a, 0);
		ft_ra(a, 0);
		ft_sa(a, 0);
	}
}

/*
void	sort_three_numbers(t_list **a)
{
int first;
int second;
int third; 

first = (*a)->content;
second = (*a)->next->content;
third = (*a)->next->next->content;
if (first > second && second < third && first < third)
{
	ft_sa(a, 0);
	return ;
}
if (first < second && second > third && first > third)
{
	ft_rra(a, 0);
	return ;
}
if (first > second && second > third)
{
	ft_ra(a,0);
	ft_sa(a,0);
	return ;
}
if (first > second && second < third && first > third)
{
	ft_ra(a,0);
	return ;
}
if (first < second && second > third && first < third)
{
	ft_ra(a,0);
	ft_ra(a,0);
	ft_sa(a,0);
	return ;
}
}

*/