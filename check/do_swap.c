/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   do_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: obult <obult@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 17:59:14 by obult         #+#    #+#                 */
/*   Updated: 2021/12/17 16:22:41 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_do_sa(t_sort_data data)
{
	if (*data.top_a)
		ft_swap(*data.top_a);
	return (0);
}

int	ft_do_sb(t_sort_data data)
{
	if (*data.top_b)
		ft_swap(*data.top_b);
	return (0);
}

int	ft_do_ss(t_sort_data data)
{
	if (*data.top_a)
		ft_swap(*data.top_a);
	if (*data.top_b)
		ft_swap(*data.top_b);
	return (0);
}
