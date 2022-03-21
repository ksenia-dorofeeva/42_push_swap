/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:23:51 by brickard          #+#    #+#             */
/*   Updated: 2022/03/17 10:51:07 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnumeric(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

int	is_num(char **av, t_var *var)
{
	int	i;

	i = 0;
	while (++i < var->size + 1)
		if (!ft_isnumeric(av[i]))
			return (0);
	return (1);
}

int	is_int(char **av, t_var *var)
{
	int		i;
	long	num;

	i = 0;
	while (++i < var->size + 1)
	{
		num = ft_atoi(av[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
	}
	return (1);
}

int	check_dup(char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	stack_is_sorted(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->size - 1)
	{
		if (var->a_stack.stack[i].num > var->a_stack.stack[i + 1].num)
			return (0);
		i++;
	}
	return (1);
}
