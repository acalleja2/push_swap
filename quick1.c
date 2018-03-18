/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 06:35:22 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:39:50 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		chose_direction_a(t_pile **begin_a, t_pile **begin_b, int mediane)
{
	int		i;
	int		j;
	t_pile	*tmp;

	i = 0;
	j = 0;
	tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
	while (tmp->value < mediane)
	{
		i++;
		put_ra_test(&tmp);
	}
	del_lst(&tmp);
	tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
	while (tmp->value < mediane)
	{
		j++;
		put_rra_test(&tmp);
	}
	j = i + 1;
	if (i < j)
		put_ra_2(begin_a, begin_b);
	else
		put_rra_2(begin_a, begin_b);
	del_lst(&tmp);
}

int			check_domaine(int min, int max, t_pile *begin, int len)
{
	while (len && begin)
	{
		if (begin->value >= min && begin->value <= max)
			return (1);
		begin = begin->next;
	}
	return (0);
}

int			rang_val(t_pile *begin, int val)
{
	while (begin)
	{
		if (begin->value == val)
			return (begin->rang);
		begin = begin->next;
	}
	return (0);
}

void		quick1_b(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot, int *k)
{
	while (!*pivot->tri && (*k)--)
		(*pivot->len)++;
	while ((*k)-- && *pivot->tri)
	{
		put_rra_2(begin_a, begin_b);
		(*pivot->len)++;
	}
}

void		quick1(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot, int *k)
{
	t_pile	*tmp;

	tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
	while (check_inf(tmp, pivot->current, *pivot->len))
	{
		if ((*begin_a)->value < pivot->current)
		{
			put_pb_2(begin_a, begin_b);
			(*pivot->len)--;
		}
		else
		{
			put_ra_2(begin_a, begin_b);
			(*pivot->len)--;
			(*k)++;
		}
		del_lst(&tmp);
		tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
	}
	del_lst(&tmp);
	quick1_b(begin_a, begin_b, pivot, k);
}
