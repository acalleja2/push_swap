/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 06:30:59 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 11:13:25 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_rb_test(t_pile **begin_b)
{
	t_pile *tmp;
	t_pile *tmp_begin;

	if (!*begin_b || !(*begin_b)->next)
		return (0);
	tmp = *begin_b;
	tmp_begin = tmp->next;
	if (*begin_b)
		;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *begin_b;
	(*begin_b)->next = NULL;
	*begin_b = tmp_begin;
	return (1);
}

int			put_rrb_test(t_pile **begin_b)
{
	t_pile *tmp_beg;
	t_pile *tmp;

	if (*begin_b)
		;
	tmp = *begin_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp_beg = tmp->next;
	tmp->next = NULL;
	tmp_beg->next = *begin_b;
	*begin_b = tmp_beg;
	return (1);
}

int			put_ra_test(t_pile **begin_b)
{
	t_pile *tmp;
	t_pile *tmp_begin;

	if (!*begin_b || !(*begin_b)->next)
		return (0);
	tmp = *begin_b;
	tmp_begin = tmp->next;
	if (*begin_b)
		;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *begin_b;
	(*begin_b)->next = NULL;
	*begin_b = tmp_begin;
	return (1);
}

int			put_rra_test(t_pile **begin_b)
{
	t_pile *tmp_beg;
	t_pile *tmp;

	if (*begin_b)
		;
	tmp = *begin_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp_beg = tmp->next;
	tmp->next = NULL;
	tmp_beg->next = *begin_b;
	*begin_b = tmp_beg;
	return (1);
}

void		chose_direction_b(t_pile **begin_a, t_pile **begin_b, int mediane)
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
		put_rb_test(&tmp);
	}
	del_lst(&tmp);
	tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
	while (tmp->value < mediane)
	{
		j++;
		put_rrb_test(&tmp);
	}
	j = i + 1;
	if (i < j)
		put_rb_2(begin_a, begin_b);
	else
		put_rrb_2(begin_a, begin_b);
	del_lst(&tmp);
}
