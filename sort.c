/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:20:26 by brickard          #+#    #+#             */
/*   Updated: 2022/03/17 15:06:56 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_var *var)
{
	if (var->a_stack.stack[0].index > var->a_stack.stack[1].index)
		sa(var);
}

void	sort_3(t_var *var)
{
	t_stack	stack;

	stack = var->a_stack;
	if (stack.stack[0].index == max_index(stack))
	{
		ra(var);
	}
	if (stack.stack[0].index == min_index(stack)
		&& stack.stack[1].index == max_index(stack))
	{
		rra(var);
		sa(var);
	}
	if (stack.stack[0].index != min_index(stack)
		&& stack.stack[0].index > stack.stack[1].index)
		sa(var);
	if (stack.stack[0].index != min_index(stack)
		&& stack.stack[0].index < stack.stack[1].index)
		rra(var);
}

void	sort_4_5(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->size - 2)
	{
		if (var->a_stack.stack[0].index > min_index(var->a_stack)
			&& is_closer(var->a_stack, min_index(var->a_stack)))
			ra(var);
		else if (var->a_stack.stack[0].index > min_index(var->a_stack)
			&& !is_closer(var->a_stack, min_index(var->a_stack)))
			rra(var);
		else
		{
			pb(var);
			i++;
		}
	}
	if (var->a_stack.stack[0].index != min_index(var->a_stack))
		sa(var);
	while (var->b_stack.len)
		pa(var);
}

void	sort_big(t_var *var)
{
	int	i;
	int	limit;

	i = 0;
	if (var->size <= 100)
		limit = 15;
	else
		limit = 30;
	while (var->a_stack.len != 0)
	{
		if (var->a_stack.stack[0].index <= i)
		{
			pb(var);
			rb(var);
			i++;
		}
		else if (var->a_stack.stack[0].index <= i + limit)
		{
			pb(var);
			i++;
		}
		else if (var->a_stack.stack[0].index >= i)
			ra(var);
	}
	sort_b_stack(var);
}
