/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:05:05 by brickard          #+#    #+#             */
/*   Updated: 2022/03/17 14:52:33 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_item	tmp;

	if (stack->len > 1)
	{
		tmp = stack->stack[0];
		stack->stack[0] = stack->stack[1];
		stack->stack[1] = tmp;
	}
}

void	push(t_stack *dst, t_stack *src)
{
	int	i;

	if (src->len > 0)
	{
		i = dst->len + 1;
		while (--i > 0)
			dst->stack[i] = dst->stack[i - 1];
		dst->stack[0] = src->stack[0];
		i = -1;
		while (++i < src->len - 1)
			src->stack[i] = src->stack[i + 1];
		dst->len += 1;
		src->len -= 1;
	}
}

void	rotate(t_stack *stack)
{
	int		i;
	t_item	tmp;

	i = -1;
	if (stack->len > 1)
	{
		tmp = stack->stack[0];
		while (++i < stack->len - 1)
			stack->stack[i] = stack->stack[i + 1];
		stack->stack[i] = tmp;
	}
}

void	reverse_rotate(t_stack *stack)
{
	int		i;
	t_item	tmp;

	i = stack->len;
	if (stack->len > 1)
	{
		tmp = stack->stack[stack->len - 1];
		while (--i > 0)
			stack->stack[i] = stack->stack[i - 1];
		stack->stack[0] = tmp;
	}
}
