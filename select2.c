/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 06:24:54 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:38:09 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort_c(t_pile **begin_a, t_pile **begin_b,
		t_pivot *pivot, int size)
{
	if (!*begin_b)
	{
		while (size)
		{
			if ((*begin_a)->value == search_min_tot(*begin_a, *begin_b, size))
			{
				put_ra_2(begin_a, begin_b);
				(*pivot->tri)++;
			}
			else
				put_pb_2(begin_a, begin_b);
			(*pivot->len)--;
			size--;
		}
	}
	select_c(begin_a, begin_b, pivot, size);
}

void	select_sort_b(t_pile **begin_a, t_pile **begin_b, int *tri)
{
	int len;

	len = 0;
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
			len++;
		}
	}
	while (len)
	{
		put_ra_2(begin_a, begin_b);
		len--;
		(*tri)++;
	}
}

t_pile	*sort_lst(t_pile *begin)
{
	int		tmp;
	t_pile	*tmp_lst;
	t_pile	*tmp_beg;

	if (!begin)
		return (NULL);
	tmp = begin->value;
	tmp_lst = begin;
	tmp_beg = begin;
	while (tmp_lst)
	{
		tmp = tmp_lst->value;
		tmp_lst->value = search_min(tmp_lst, count_lst(tmp_lst));
		begin = begin->next;
		while (begin)
		{
			if (begin->value == search_min(tmp_lst, count_lst(tmp_lst)))
				begin->value = tmp;
			begin = begin->next;
		}
		tmp_lst = tmp_lst->next;
		begin = tmp_lst;
	}
	return (tmp_beg);
}

void	index_pile(t_pile **begin_a, t_pile *model)
{
	int		k;
	t_pile	*beg;
	t_pile	*tmp;

	beg = model;
	tmp = *begin_a;
	while (tmp)
	{
		k = 0;
		while (model->value != tmp->value)
		{
			k++;
			model = model->next;
		}
		tmp->rang = k;
		tmp = tmp->next;
		model = beg;
	}
}

void	give_rang(t_pile *begin, t_pivot *pivot)
{
	while (begin)
	{
		if (begin->value == pivot->current)
			pivot->rang = begin->rang;
		begin = begin->next;
	}
}
