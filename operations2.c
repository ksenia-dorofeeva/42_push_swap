/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:13:41 by brickard          #+#    #+#             */
/*   Updated: 2022/03/15 18:23:26 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_var *var)
{
	rotate(&var->b_stack);
	write(1, "rb\n", 3);
}

void	rra(t_var *var)
{
	reverse_rotate(&var->a_stack);
	write(1, "rra\n", 4);
}

void	rrb(t_var *var)
{
	reverse_rotate(&var->b_stack);
	write(1, "rrb\n", 4);
}
