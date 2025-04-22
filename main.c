/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:15:38 by angellop          #+#    #+#             */
/*   Updated: 2025/04/22 15:55:08 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_join_args(int argc, char **argv, t_stacks *stacks)
{
	char	*tmp;
	int		i;

	i = 0;
	stacks->args_connected = ft_strdup("");
	tmp = NULL;
	if (argc == 1)
		return ;
	if (argc == 2 && argv[1][0] == 0)
		return (ft_putendl_fd("Error", 2));
	while (++i < argc)
	{
		tmp = ft_strjoin(stacks->args_connected, argv[i]);
		free(stacks->args_connected);
		if (i < argc - 1)
		{
			stacks->args_connected = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = stacks->args_connected;
		}
		else
			stacks->args_connected = tmp;
	}
}

static void	ft_args_validation(t_stacks *stacks)
{
	int		i;
	char	*args;

	i = 0;
	args = stacks->args_connected;
	while (args[i])
	{
		if ((!ft_isdigit(args[i]) && args[i] != ' '
				&& args[i] != '-' && args[i] != '+')
			|| (args[i] == '-' && args[i + 1] == ' ')
			|| (args[i] == '+' && args[i + 1] == ' ')
			|| (args[i] == '-' && args[i + 1] == '\0')
			|| (args[i] == '+' && args[i + 1] == '\0'))
		{
			ft_putstr_fd("Error\n", 2);
			free(stacks->args_connected);
			free(stacks);
			exit(1);
		}
		i++;
	}
}

void	ft_initialize_stacks(t_stacks *stacks)
{
	char	*args;

	stacks->a_size = 0;
	stacks->b_size = 0;
	args = stacks->args_connected;
	if (ft_word_count(args, ' ', 0))
		stacks->a_size += ft_word_count(args, ' ', 0);
	stacks->a = malloc(stacks->a_size * sizeof(int));
	if (!stacks->a)
		ft_flush_exit(stacks, "Error\n");
	stacks->b = malloc(stacks->a_size * sizeof(int));
	if (!stacks->b)
		ft_flush_exit(stacks, "Error\n");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	ft_join_args(argc, argv, stacks);
	ft_args_validation(stacks);
	ft_initialize_stacks(stacks);
	ft_parse_numbers(stacks);
	ft_check_dup(stacks);
	ft_relative_pos_normalization(stacks);
	if (stacks->a_size == 2 && stacks->a[0] > stacks->a[1])
		ft_swap(stacks, 'a');
	else if (stacks->a_size == 3 && !ft_is_sorted(stacks))
		ft_sort_three(stacks);
	else if (stacks->a_size >= 4
		&& stacks->a_size <= 5 && !ft_is_sorted(stacks))
		ft_sort_four_to_five(stacks);
	else
		ft_radix_sort(stacks);
	ft_is_sorted(stacks);
	ft_flush_exit(stacks, "");
	return (0);
}
