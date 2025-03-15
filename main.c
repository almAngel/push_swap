/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:15:38 by angellop          #+#    #+#             */
/*   Updated: 2025/03/14 14:22:26 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_join_args(int argc, char **argv, t_stacks *stacks)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	if (argc == 1)
    {
        stacks->args_connected = tmp2;
        return;
    }
	while (++i < argc && argv[i])
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			free(tmp);
			tmp = tmp2;
		}
	}
	stacks->args_connected = tmp;
	if (!stacks->args_connected)
		ft_flush_exit(stacks, "Error\n");
}

static void ft_args_validation(t_stacks *stacks)
{
	int i;
	char *args;

	i = 0;
	args = stacks->args_connected;
	while (args[i])
	{
		if ((!ft_isdigit(args[i]) && args[i] != ' ' && args[i] != '-' && args[i] != '+') ||
			(args[i] == '-' && args[i] == ' ') ||
			(args[i] == '+' && args[i] == ' ') ||
			(args[i] == '-' && args[i] == '\0') ||
			(args[i] == '+' && args[i] == '\0'))
				ft_flush_exit(NULL, "Error\n");
		i++;
	}
}

void ft_initialize_stacks(t_stacks *stacks)
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

int main(int argc, char **argv)
{

	t_stacks *stacks;

	stacks = malloc(sizeof(t_stacks));
	ft_join_args(argc, argv, stacks);
	ft_args_validation(stacks);
	ft_initialize_stacks(stacks);
	ft_parse_numbers(stacks);
	ft_check_dup(stacks->a, stacks->a_size);
	ft_relative_pos_normalization(stacks);
	if (stacks->a_size > 20)
		ft_radix_sort(stacks);
	else
		ft_infra_sort(stacks);
	return (0);
}