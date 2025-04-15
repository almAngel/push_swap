/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:16:03 by angellop          #+#    #+#             */
/*   Updated: 2025/04/15 20:20:32 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_numbers(t_stacks *stacks)
{
	char	**tmp;
	int		i;
	int		z;
	int		num;

	z = 0;
	tmp = ft_split(stacks->args_connected, ' ');
	i = 0;
	num = 0;
	while (tmp[i] && tmp[i][0])
	{
		num = ft_atol(tmp, tmp[i], stacks);
		stacks->a[z++] = num;
		i++;
	}
	free(tmp);
}

void	ft_check_dup(int *stack, int size)
{
	int	*i;
	int	*j;

	i = stack;
	while (i < stack + size)
	{
		j = i + 1;
		while (j < stack + size)
		{
			if (*i == *j)
				ft_flush_exit(NULL, "Error\n");
			j++;
		}
		i++;
	}
}

size_t	ft_word_count(const char *s, char c, size_t w_count)
{
	short	is_word;

	is_word = 0;
	while (*s)
	{
		if (*s != c && !is_word)
		{
			is_word = 1;
			w_count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (w_count);
}

void	ft_flush_exit(t_stacks *stacks, char *msg)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	if (stacks)
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks->args_connected);
		free(stacks);
	}
	stacks = NULL;
	exit(1);
}

long long	ft_atol(char **tmp, char *str, t_stacks *stacks)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] <= 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			ft_flush_exit(stacks, "Error\n");
		result = result * 10 + (str[i++] - '0');
	}
	result *= sign;
	free(str);
	if (result > 2147483647 || result < -2147483648)
	{
		free(tmp);
		ft_flush_exit(stacks, "Error\n");
	}
	return (result);
}
