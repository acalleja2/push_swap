/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 06:18:54 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:36:43 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_min_tot(t_pile *begin_a, t_pile *begin_b, int len)
{
	if (search_min(begin_a, len) < search_min(begin_b, count_lst(begin_b)))
		return (search_min(begin_a, len));
	else
		return (search_min(begin_b, count_lst(begin_b)));
}

int		check_position(t_pile *begin_b)
{
	int len;

	len = count_lst(begin_b);
	if (begin_b->value == search_min(begin_b, len) ||
		begin_b->value == search_max(begin_b, len))
		return (5);
	if (value_range(begin_b, search_min(begin_b, len)) <
	value_range(begin_b, search_max(begin_b, len)))
	{
		if (value_range(begin_b, search_min(begin_b, len)) <
		len - value_range(begin_b, search_max(begin_b, len)))
			return (1);
		else
			return (2);
	}
	else
	{
		if (value_range(begin_b, search_max(begin_b, len)) <
		len - value_range(begin_b, search_min(begin_b, len)))
			return (3);
		else
			return (4);
	}
}

void	select_b(t_pile **begin_a, t_pile **begin_b, int *len, int *tri)
{
	while (*begin_b)
	{
		action_move(begin_a, begin_b, check_position(*begin_b));
		if ((*begin_b)->value == search_min(*begin_b, count_lst(*begin_b)))
		{
			put_pa_2(begin_a, begin_b);
			put_ra_2(begin_a, begin_b);
			(*tri)++;
		}
		else
		{
			put_pa_2(begin_a, begin_b);
			(*len)++;
		}
	}
	while (*len)
	{
		put_ra_2(begin_a, begin_b);
		(*len)--;
		(*tri)++;
	}
}

void	select_sort(t_pile **begin_a, t_pile **begin_b, int *len, int *tri)
{
	if (!*begin_b)
	{
		while (*len)
		{
			if ((*begin_a)->value == search_min_tot(*begin_a, *begin_b, *len))
			{
				put_ra_2(begin_a, begin_b);
				(*tri)++;
			}
			else
				put_pb_2(begin_a, begin_b);
			(*len)--;
		}
	}
	select_b(begin_a, begin_b, len, tri);
}

void	select_c(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot, int size)
{
	while (*begin_b)
	{
		action_move(begin_a, begin_b, check_position(*begin_b));
		if ((*begin_b)->value == search_min(*begin_b, count_lst(*begin_b)))
		{
			put_pa_2(begin_a, begin_b);
			put_ra_2(begin_a, begin_b);
			(*pivot->tri)++;
		}
		else
		{
			put_pa_2(begin_a, begin_b);
			(*pivot->len)++;
			size++;
		}
	}
	while (size)
	{
		put_ra_2(begin_a, begin_b);
		(*pivot->len)--;
		size--;
		(*pivot->tri)++;
	}
}
