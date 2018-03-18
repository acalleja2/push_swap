/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 06:40:45 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:34:52 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick2(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot)
{
	t_pile *tmp;

	pivot->current = find_mediane(copie_lst(*begin_b, LONG_MAX, LONG_MAX),
	pivot, count_lst(*begin_b), 0);
	tmp = copie_lst(*begin_b, LONG_MAX, LONG_MAX);
	while (check_supp(tmp, pivot->current, len_list(*begin_b)))
	{
		if ((*begin_b)->value >= pivot->current)
		{
			put_pa_2(begin_a, begin_b);
			(*pivot->len)++;
		}
		else
			chose_direction_b(begin_a, begin_b, pivot->current);
		del_lst(&tmp);
		tmp = copie_lst(*begin_b, LONG_MAX, LONG_MAX);
	}
	del_lst(&tmp);
}

int			quick3(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = copie_lst(*begin_a, LONG_MAX, pivot->current);
	tmp2 = cpy_min(tmp, pivot->current, *pivot->len);
	if (len_list(tmp2) < 35)
	{
		select_sort_c(begin_a, begin_b, pivot, len_list(tmp2));
		del_lst(&tmp);
		del_lst(&tmp2);
		return (1);
	}
	pivot->current = find_mediane(cpy_min(tmp, pivot->current, *pivot->len),
	pivot, *pivot->len, 0);
	del_lst(&tmp);
	del_lst(&tmp2);
	return (0);
}

int			quick4(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot)
{
	t_pile		*tmp;
	int			k;

	k = 0;
	if (*pivot->len < 35)
	{
		select_sort(begin_a, begin_b, pivot->len, pivot->tri);
		return (1);
	}
	if (pivot->bol == 0)
	{
		tmp = cpy_lst_min(*begin_a, search_max(*begin_a, *pivot->len),
		*pivot->len);
		pivot->current = find_mediane(tmp, pivot, *pivot->len, 0);
		pivot->bol = 1;
	}
	else
	{
		if (quick3(begin_a, begin_b, pivot) == 1)
			return (1);
	}
	quick1(begin_a, begin_b, pivot, &k);
	return (0);
}

void		quick_sort(t_pile **begin_a, t_pile **begin_b, t_pivot pivot)
{
	t_pile *tmp;

	if (!*begin_b)
	{
		if (quick4(begin_a, begin_b, &pivot) == 1)
			return ;
	}
	else
	{
		if (count_lst(*begin_b) < 35)
			return (select_sort_b(begin_a, begin_b, pivot.tri));
		quick2(begin_a, begin_b, &pivot);
	}
	while (rang_val(*begin_a, pivot.current) != *pivot.tri)
	{
		tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
		if (!check_inf(tmp, pivot.current, *pivot.len) && !*begin_b)
		{
			del_lst(&tmp);
			return ;
		}
		del_lst(&tmp);
		quick_sort(begin_a, begin_b, pivot);
	}
}

void		little_sort(t_pile **begin_a, t_pile **begin_b, t_pivot pivot)
{
	while (check_list(*begin_a, len_list(*begin_a)) != 1)
	{
		if ((*begin_a)->value == search_max(*begin_a, len_list(*begin_a)))
			put_ra_2(begin_a, begin_b);
		else if ((*begin_a)->value != search_min(*begin_a, len_list(*begin_a))
	&& search_last(*begin_a)->value == search_max(*begin_a, len_list(*begin_a)))
			put_sa_2(begin_a, begin_b);
		else if ((*begin_a)->value == search_min(*begin_a, len_list(*begin_a))
	&& search_last(*begin_a)->value != search_max(*begin_a, len_list(*begin_a)))
			put_rra_2(begin_a, begin_b);
		else if ((*begin_a)->value == search_min(*begin_a, len_list(*begin_a)))
			put_ra_2(begin_a, begin_b);
		else if (search_last(*begin_a)->value ==
				search_min(*begin_a, len_list(*begin_a)))
			put_rra_2(begin_a, begin_b);
		if (pivot.v)
			print_list(*begin_a, *begin_b);
	}
}
