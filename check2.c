/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 05:57:59 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 11:13:44 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_supp(t_pile *begin, int limit, int len)
{
	if (!begin)
		return (1);
	while (begin && len)
	{
		if (begin->value >= limit)
			return (1);
		begin = begin->next;
		len--;
	}
	return (0);
}

int			check_inf(t_pile *begin, int limit, int len)
{
	if (!begin)
		return (1);
	while (begin && len)
	{
		if (begin->value < limit)
			return (1);
		begin = begin->next;
		len--;
	}
	return (0);
}

t_pile		*search_last(t_pile *begin)
{
	while (begin->next)
		begin = begin->next;
	return (begin);
}

int			check_zone(t_pile *begin, long min, long max)
{
	while (begin)
	{
		if (begin->value > min && begin->value < max)
			return (1);
		begin = begin->next;
	}
	return (0);
}

int			value_range(t_pile *begin, int value)
{
	int k;

	k = 0;
	while (begin)
	{
		k++;
		if (begin->value == value)
			return (k);
		begin = begin->next;
	}
	return (0);
}
