/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:10:23 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 21:49:01 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;

	a = ft_preprocess(argc, argv);
	if (!a)
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_check_sorted(a))
		ft_sort(&a);
	ft_free(&a);
	return (0);
}

// ARG=$(shuf -i 1-1000 -n 700) && ./push_swap $ARG | wc -l