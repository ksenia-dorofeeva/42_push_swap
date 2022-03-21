/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:30:29 by brickard          #+#    #+#             */
/*   Updated: 2022/03/15 18:24:08 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_var *var)
{
	swap(&var->a_stack);
	write(1, "sa\n", 3);
}

void	pa(t_var *var)
{
	push(&var->a_stack, &var->b_stack);
	write(1, "pa\n", 3);
}

void	pb(t_var *var)
{
	push(&var->b_stack, &var->a_stack);
	write(1, "pb\n", 3);
}

void	ra(t_var *var)
{
	rotate(&var->a_stack);
	write(1, "ra\n", 3);
}
