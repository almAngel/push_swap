/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:07:21 by angellop          #+#    #+#             */
/*   Updated: 2025/03/14 14:23:53 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*args_connected;
}			t_stacks;

void	ft_flush_exit(t_stacks *stacks, char *msg);
long	ft_atol(const char *str, t_stacks *stacks);
size_t	ft_word_count(const char *s, char c, size_t w_count);
void	ft_parse_numbers(t_stacks *stacks);
void	ft_check_dup(int *stack, int size);
void	ft_swap(t_stacks *stacks, char c);
void	ft_rotate(t_stacks *stacks, char c);
void	ft_reverse_rotate(t_stacks *stacks, char c);
void	ft_push(t_stacks *stacks, char c);
int		ft_is_sorted(t_stacks *stacks);
void	ft_infra_sort(t_stacks *stacks);
void	ft_radix_sort(t_stacks *stacks);
void	ft_relative_pos_normalization(t_stacks *s);

#endif