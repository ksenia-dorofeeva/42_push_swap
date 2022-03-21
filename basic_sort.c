/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:21:21 by brickard          #+#    #+#             */
/*   Updated: 2022/03/15 20:55:03 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_index(t_stack stack)
{
	int	i;
	int	index;

	i = 0;
	index = stack.stack[i].index;
	while (i < stack.len)
	{
		if (stack.stack[i].index < index)
			index = stack.stack[i].index;
		i++;
	}	
	return (index);
}

int	max_index(t_stack stack)
{
	int	i;
	int	index;

	i = 0;
	index = stack.stack[i].index;
	while (i < stack.len)
	{
		if (stack.stack[i].index > index)
			index = stack.stack[i].index;
		i++;
	}
	return (index);
}

int	find_index(int *sorted_arr, int num)
{
	int	i;

	i = 0;
	while (sorted_arr[i] != num)
		i++;
	return (i);
}

void	set_index(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->size)
	{
		var->a_stack.stack[i].index = find_index(var->sorted_arr,
				var->a_stack.stack[i].num);
		i++;
	}
}

void	basic_sort(t_var *var)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < var->size - 1)
	{
		j = var->size - 1;
		while (j > i)
		{
			if (var->sorted_arr[j - 1] > var->sorted_arr[j])
			{
				tmp = var->sorted_arr[j - 1];
				var->sorted_arr[j - 1] = var->sorted_arr[j];
				var->sorted_arr[j] = tmp;
			}
			j--;
		}
		i++;
	}
}
