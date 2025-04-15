/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:51:11 by angellop          #+#    #+#             */
/*   Updated: 2025/04/15 17:07:40 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a_size - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_three(t_stacks *s)
{
	if (s->a[2] != 2)
	{
		if (s->a[0] == 2)
			ft_rotate_backwards(s, 'a');
		else
			ft_rotate_forward(s, 'a');
	}
	if (s->a[0] > s->a[1])
		ft_swap(s, 'a');
}

void	ft_sort_four_to_five(t_stacks *s)
{
	while (s->b_size <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			ft_push_b(s);
		else
			ft_rotate_backwards(s, 'a');
	}
	if (s->b[0] == 0)
		ft_swap(s, 'b');
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			ft_rotate_backwards(s, 'a');
		else
			ft_rotate_forward(s, 'a');
	}
	if (s->a[0] > s->a[1])
		ft_swap(s, 'a');
	ft_push_a(s);
	ft_push_a(s);
}

void	ft_relative_pos_normalization(t_stacks *s)
{
	int	*hash;
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
