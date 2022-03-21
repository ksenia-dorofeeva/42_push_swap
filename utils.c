/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:54:27 by brickard          #+#    #+#             */
/*   Updated: 2022/03/17 11:33:03 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

size_t	ft_atoi(const char *str)
{
	unsigned int	i;
	long			sign;
	long			num;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	arr_of_indexes(t_stack stack, int *num)
{
	int	i;

	i = 0;
	while (i < stack.len)
	{
		num[i] = stack.stack[i].index;
		i++;
	}
	return (*num);
}

int	is_closer(t_stack stack, int med)
{
	int	i;
	int	j;
	int	*num;

	i = stack.len - 1;
	num = malloc(sizeof(int) * (i + 1));
	if (!num)
		return (0);
	*num = arr_of_indexes(stack, num);
	j = i;
	while (num[i] != med)
		i--;
	j = j - i;
	i = 0;
	while (num[i] != med)
		i++;
	free(num);
	if (j < i)
		return (0);
	return (1);
}

void	sort_b_stack(t_var *var)
{
	while (var->b_stack.len != 0)
	{
		if (var->b_stack.stack[0].index != max_index(var->b_stack)
			&& is_closer(var->b_stack, max_index(var->b_stack)))
			rb(var);
		else if (var->b_stack.stack[0].index != max_index(var->b_stack)
			&& !is_closer(var->b_stack, max_index(var->b_stack)))
			rrb(var);
		else if (var->b_stack.stack[0].index == max_index(var->b_stack))
			pa(var);
	}
}
