/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:40:00 by brickard          #+#    #+#             */
/*   Updated: 2022/03/17 14:32:00 by brickard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_var *var)
{
	basic_sort(var);
	set_index(var);
	if (var->size == 2)
		sort_2(var);
	else if (var->size == 3)
		sort_3(var);
	else if (var->size == 4 || var->size == 5)
		sort_4_5(var);
	else
		sort_big(var);
}

void	fill_a_stack(t_var *var, char **argv)
{
	int	i;

	i = 0;
	while (i < var->size)
	{
		var->a_stack.stack[i].num = ft_atoi(argv[i + 1]);
		var->sorted_arr[i] = var->a_stack.stack[i].num;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	var->size = argc - 1;
	if (is_num(argv, var) && is_int(argv, var))
	{
		var->a_stack.stack = malloc(var->size * sizeof(t_item));
		var->a_stack.len = var->size;
		var->b_stack.stack = malloc(var->size * sizeof(t_item));
		var->b_stack.len = 0;
		var->sorted_arr = malloc(var->size * sizeof(int));
		fill_a_stack(var, argv);
		if (!check_dup(argv))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		if (!stack_is_sorted(var))
			sort(var);
	}
	else
		write(2, "Error\n", 6);
	exit(0);
}
