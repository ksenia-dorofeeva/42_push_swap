/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:37:03 by brickard          #+#    #+#             */
/*   Updated: 2022/03/17 14:37:00 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_item
{
	int	num;
	int	index;	
}				t_item;

typedef struct s_stack
{
	int		len;
	t_item	*stack;
}				t_stack;

typedef struct s_var
{
	int		size;
	t_stack	a_stack;
	t_stack	b_stack;
	int		*sorted_arr;
}				t_var;

size_t	ft_atoi(const char *str);
int		stack_is_sorted(t_var *var);
void	basic_sort(t_var *var);
int		check_dup(char **av);
void	set_index(t_var *var);
int		find_index(int *sorted_arr, int num);
void	swap(t_stack *stack);
void	push(t_stack *dst, t_stack *src);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	sort_2(t_var *var);
void	sa(t_var *var);
void	pa(t_var *var);
void	pb(t_var *var);
void	ra(t_var *var);
void	rb(t_var *var);
void	rra(t_var *var);
void	rrb(t_var *var);
void	sort_3(t_var *var);
int		min_index(t_stack stack);
int		max_index(t_stack stack);
void	sort_4_5(t_var *var);
int		is_closer(t_stack stack, int med);
int		arr_of_indexes(t_stack stack, int *num);
void	sort_big(t_var *var);
void	sort_b_stack(t_var *var);
int		is_num(char **av, t_var *var);
int		is_int(char **av, t_var *var);
int		ft_strcmp(char *s1, char *s2);

#endif