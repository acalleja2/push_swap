/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 03:11:26 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 22:47:15 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_pb(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;

	if (!*begin_a)
		return (1);
	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	tmp->rang = (*begin_a)->rang;
	tmp->value = (*begin_a)->value;
	tmp->next = *begin_b;
	*begin_b = tmp;
	remove_elem(begin_a);
	return (1);
}

int			put_ra(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;
	t_pile *tmp_begin;

	if (!*begin_a || !(*begin_a)->next)
		return (1);
	tmp = *begin_a;
	tmp_begin = tmp->next;
	if (*begin_a || *begin_b)
		;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *begin_a;
	(*begin_a)->next = NULL;
	*begin_a = tmp_begin;
	return (1);
}

int			put_rb(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;
	t_pile *tmp_begin;

	if (!*begin_b || !(*begin_b)->next)
		return (1);
	tmp = *begin_b;
	tmp_begin = tmp->next;
	if (*begin_a || *begin_b)
		;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *begin_b;
	(*begin_b)->next = NULL;
	*begin_b = tmp_begin;
	return (1);
}

int			put_rr(t_pile **begin_a, t_pile **begin_b)
{
	if (!put_ra(begin_a, begin_b))
		return (1);
	if (!put_rb(begin_a, begin_b))
		return (1);
	return (1);
}

int			put_rra(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp_beg;
	t_pile *tmp;

	if (count_lst(*begin_a) < 2)
		return (1);
	if (*begin_a || *begin_b)
		;
	tmp = *begin_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp_beg = tmp->next;
	tmp->next = NULL;
	tmp_beg->next = *begin_a;
	*begin_a = tmp_beg;
	return (1);
}
