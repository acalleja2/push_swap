/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rang.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:15:48 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:44:10 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*sort_lst(t_pile *begin)
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

void		index_pile(t_pile **begin_a, t_pile *model)
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

void		give_rang(t_pile *begin, t_pivot *pivot)
{
	while (begin)
	{
		if (begin->value == pivot->current)
			pivot->rang = begin->rang;
		begin = begin->next;
	}
}
