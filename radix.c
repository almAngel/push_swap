/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:09:29 by angellop          #+#    #+#             */
/*   Updated: 2025/04/21 18:35:59 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_radix_sort_stack_b(t_stacks *stacks, int b_size
	, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !ft_is_sorted(stacks))
	{
		if (((stacks->b[0] >> j) & 1) == 0)
			ft_rotate_backwards(stacks, 'b');
		else
			ft_push_a(stacks);
	}
	if (ft_is_sorted(stacks))
		while (stacks->b_size != 0)
			ft_push_a(stacks);
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
				ft_push_b(stacks);
			else
				ft_rotate_backwards(stacks, 'a');
		}
		ft_radix_sort_stack_b(stacks, stacks->b_size, bit_size, j + 1);
	}
	while (stacks->b_size != 0)
		ft_push_a(stacks);
}
