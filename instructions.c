/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 01:43:14 by angellop          #+#    #+#             */
/*   Updated: 2025/04/10 14:31:17 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stacks *stacks, char c)
{
	int	tmp;

	if (c == 'a' && stacks->a_size >= 2)
	{
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
		ft_putendl_fd("sa", 1);
	}
	if (c == 'b' && stacks->b_size >= 2)
	{
		tmp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
		ft_putendl_fd("sb", 1);
	}
}

void	ft_rotate_backwards(t_stacks *stacks, char c)
{
	int	tmp;
	int	i;

	i = -1;
	if (c == 'a' && stacks->a_size >= 2)
	{
		tmp = stacks->a[0];
		while (++i < stacks->a_size - 1)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[i] = tmp;
		ft_putendl_fd("ra", 1);
	}
	if (c == 'b' && stacks->b_size >= 2)
	{
		tmp = stacks->b[0];
		while (++i < stacks->b_size - 1)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[i] = tmp;
		ft_putendl_fd("rb", 1);
	}
}

void	ft_rotate_forward(t_stacks *stacks, char c)
{
	int	tmp;
	int	i;

	i = -1;
	if (c == 'a' && stacks->a_size >= 2)
	{
		tmp = stacks->a[stacks->a_size - 1];
		while (++i < stacks->a_size - 1)
			stacks->a[i + 1] = stacks->a[i];
		stacks->a[0] = tmp;
		ft_putendl_fd("rra", 1);
	}
	if (c == 'b' && stacks->b_size >= 2)
	{
		tmp = stacks->b[stacks->a_size - 1];
		while (++i < stacks->b_size - 1)
			stacks->b[i + 1] = stacks->b[i];
		stacks->b[0] = tmp;
		ft_putendl_fd("rrb", 1);
	}
}

void	ft_push_a(t_stacks *stacks)
{
	int	tmp;

	if (stacks->b_size == 0)
		return ;
	tmp = stacks->b[0];
	ft_memmove(stacks->a + 1, stacks->a, sizeof(int) * stacks->a_size);
	stacks->a[0] = tmp;
	stacks->b_size--;
	ft_memmove(stacks->b, stacks->b + 1, sizeof(int) * stacks->b_size);
	stacks->a_size++;
	ft_putendl_fd("pa", 1);
}

void	ft_push_b(t_stacks *stacks)
{
	int	tmp;

	if (stacks->a_size == 0)
		return ;
	tmp = stacks->a[0];
	ft_memmove(stacks->b + 1, stacks->b, sizeof(int) * stacks->b_size);
	stacks->b[0] = tmp;
	stacks->a_size--;
	ft_memmove(stacks->a, stacks->a + 1, sizeof(int) * stacks->a_size);
	stacks->b_size++;
	ft_putendl_fd("pb", 1);
}
