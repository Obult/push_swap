/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 19:30:22 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/16 18:08:51 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_push(t_stack **origin, t_stack **dest, char *msg)
{
	t_stack	*og_cpy;

	og_cpy = *origin;
	(og_cpy->prev)->next = og_cpy->next;
	(og_cpy->next)->prev = og_cpy->prev;
	*origin = og_cpy->next;
	if (*dest)
	{
		((*dest)->prev)->next = og_cpy;
		og_cpy->prev = (*dest)->prev;
		og_cpy->next = *dest;
		(*dest)->prev = og_cpy;
		*dest = og_cpy;
	}
	else
	{
		*dest = og_cpy;
		og_cpy->next = og_cpy;
		og_cpy->prev = og_cpy;
	}
	if (msg != NULL)
		ft_putendl_fd(msg, 1);
	if (*origin == *dest)
		*origin = NULL;
}

static void	ft_bottom_push_b(t_stack **org, t_stack **dst)
{
	ft_rev_rotate(org, "rra");
	ft_push(org, dst, "pb");
}

void	ft_bottom_push_bx(t_stack **org, t_stack **dst, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_bottom_push_b(org, dst);
		i++;
	}
}

void	ft_push_x(t_stack **org, t_stack **dst, char *msg, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		ft_push(org, dst, msg);
		i++;
	}
}
