/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:31:39 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/13 19:31:40 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_sort_min(t_sort_data data)
{
	data.size = data.size / 3;
	ft_revr_x(data.top_b, "rrb", data.size);
	ft_sort_b(data);
}

void	ft_sort_mid(t_sort_data data)
{
	int	p;

	p = 0;
	if (data.size % 3)
		p = 1;
	data.size = data.size / 3 + p;
	ft_sort_b(data);
}

void	ft_sort_max(t_sort_data data)
{
	data.size = data.size / 3 + data.size % 3 / 2;
	ft_sort(data);
}

int	get_min(int size, t_stack *start)
{
	int	i;
	int	min;

	i = 0;
	min = start->index;
	while (i < size)
	{
		if (start->index < min)
			min = start->index;
		i++;
		start = start->next;
	}
	return (min);
}

t_stack	*ft_get_bottom_offset(t_stack *start, int offset)
{
	int	i;

	i = 0;
	if (offset < 0)
	{
		while (i > offset)
		{
			start = start->next;
			i--;
		}
	}
	while (i < offset)
	{
		start = start->prev;
		i++;
	}
	return (start);
}
