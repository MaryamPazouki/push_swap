/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 22:47:26 by mpazouki          #+#    #+#             */
/*   Updated: 2024/12/19 22:48:36 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	long			index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_check_sorted(t_list *stack);
void	ft_error(void);
int		ft_find_index(t_list *a, int nbr);
int		ft_find_target_a(t_list *stack_a, int push_value);
void	ft_free(t_list **stack);
int		ft_max(t_list *stack);
int		ft_min(t_list *stack);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(long content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_freestr(char **str_array);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_optimal_cost(t_list *a, t_list *b);
int		ft_atoi_long(const char *str);
t_list	*ft_fill_stack(t_list *stack, char **sequence, int start_index);
int		ft_check_duplicates(t_list *stack);
t_list	*ft_preprocess(int argc, char **argv);
void	sort_three_numbers(t_list **a);
void	ft_push_alltill3_ab(t_list **a, t_list **b);
t_list	**ft_sort_a(t_list **a, t_list **b);
void	ft_last_sort_a(t_list **a);
void	ft_sort(t_list **stack_a);
int		main(int argc, char **argv);
int		ft_move_rarb(t_list **a, t_list **b, int value);
int		ft_move_rrarb(t_list **a, t_list **b, int value);
int		ft_move_rarrb(t_list **a, t_list **b, int value);
int		ft_move_rrarrb(t_list **a, t_list **b, int value);
int		ft_cost_rarb(t_list *a, t_list *b, int value);
int		ft_cost_rrarrb(t_list *a, t_list *b, int value);
int		ft_cost_rarrb(t_list *a, t_list *b, int value);
int		ft_cost_rrarb(t_list *a, t_list *b, int value);
void	ft_swap(t_list **stack);
void	ft_sa(t_list **a, int j);
void	ft_sb(t_list **b, int j);
void	ft_ss(t_list **a, t_list **b, int j);
void	ft_rotate(t_list **stack);
void	ft_ra(t_list **a, int j);
void	ft_rb(t_list **b, int j);
void	ft_rr(t_list **a, t_list **b, int j);
void	ft_reverse(t_list **stack);
void	ft_reverse_and_log(t_list **stack, int j, const char *log_message);
void	ft_rra(t_list **a, int j);
void	ft_rrb(t_list **b, int j);
void	ft_rrr(t_list **a, t_list **b, int j);
void	ft_push_to_a(t_list **a, t_list **b, int j);
void	ft_push_to_b(t_list **a, t_list **b, int j);
#endif