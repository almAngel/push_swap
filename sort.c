/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:51:11 by angellop          #+#    #+#             */
/*   Updated: 2025/03/14 14:25:11 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_sorted(t_stacks *stacks)
{
	int i;

	i = 0;
	while (i < stacks->a_size - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void ft_infra_sort(t_stacks *stacks)
{
	while (!ft_is_sorted(stacks) && stacks->b_size == 0)
	{
		while (stacks->a_size > 1 && !ft_is_sorted(stacks))
		{
			if (stacks->a[0] < stacks->a[1])
				ft_push(stacks, 'b');
			else
				ft_swap(stacks, 'a');
		}
		while (stacks->b_size > 0)
		{
			if (stacks->b[0] < stacks->b[1])
				ft_swap(stacks, 'b');
			ft_push(stacks, 'a');
		}
	}
	ft_flush_exit(stacks, NULL);
}

static void	ft_radix_sort_stack_b(t_stacks *stacks, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !ft_is_sorted(stacks))
	{
		if (((stacks->b[0] >> j) & 1) == 0)
			ft_rotate(stacks, 'b');
		else
			ft_push(stacks, 'a');
	}
	if (ft_is_sorted(stacks))
		while (stacks->b_size != 0)
			ft_push(stacks, 'a');
}

void	ft_radix_sort(t_stacks *stacks)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stacks->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stacks->a_size;
		while (size-- && !ft_is_sorted(stacks))
		{
			if (((stacks->a[0] >> j) & 1) == 0)
				ft_push(stacks, 'b');
			else
				ft_rotate(stacks, 'a');
		}
		ft_radix_sort_stack_b(stacks, stacks->b_size, bit_size, j + 1);
	}
	while (stacks->b_size != 0)
		ft_push(stacks, 'a');
}

void ft_relative_pos_normalization(t_stacks *s)
{
    int *hash;
    int	i;
	int	j;
	int	k;

	i = -1;
    hash = malloc(s->a_size * sizeof(int));
    while (++i < s->a_size)
		hash[i] = s->a[i];
	i = -1;
    while (++i < s->a_size)
    {
		j = -1;
        k = 0;
        while (++j < s->a_size)
            if (s->a[i] > s->a[j])
                k++;
        hash[i] = k;
    }
    free(s->a);
	s->a = hash;
}
