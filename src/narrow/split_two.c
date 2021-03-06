/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_two.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:31:51 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:31:52 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_split_in_two(t_sort_data data)
{
	int	i;
	int	min;
	int	size;

	i = 0;
	size = data.size;
	min = get_min(data.size, *data.top_b);
	while (i < data.size)
	{
		if ((*data.top_b)->index < (min + data.size / 2 - 1))
		{
			ft_rotate(data.top_b, "rb");
		}
		else
		{
			ft_push(data.top_b, data.top_a, "pa");
		}
		i++;
	}
	ft_revr_x(data.top_b, "rrb", data.size / 2 - 1);
	data.size = size / 2 + size % 2 + 1;
	ft_sort(data);
	data.size = size / 2 - 1;
	ft_sort_b(data);
}

void	ft_medium_size_a(t_sort_data data)
{
	int	i;
	int	min;
	int	size;

	i = 0;
	size = data.size;
	min = get_min(data.size, *data.top_a);
	while (i < data.size)
	{
		if ((*data.top_a)->index < (min + data.size / 2 + 1 + data.size % 2))
		{
			ft_push(data.top_a, data.top_b, "pb");
		}
		else
		{
			ft_rotate(data.top_a, "ra");
		}
		i++;
	}
	ft_revr_x(data.top_a, "rra", size / 2 - 1);
	data.size = size / 2 - 1;
	ft_sort(data);
	data.size = size / 2 + 1 + size % 2;
	ft_sort_b(data);
}
