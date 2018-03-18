/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 05:31:51 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 11:15:52 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_ra_2(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;
	t_pile *tmp_begin;

	ft_putstr("ra\n");
	if (!*begin_a || !(*begin_a)->next)
		return (0);
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

int			put_rb_2(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;
	t_pile *tmp_begin;

	ft_putstr("rb\n");
	if (!*begin_b || !(*begin_b)->next)
		return (0);
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

int			put_rr_2(t_pile **begin_a, t_pile **begin_b)
{
	ft_putstr("rr\n");
	if (!put_ra_2(begin_a, begin_b))
		return (0);
	if (!put_rb_2(begin_a, begin_b))
		return (0);
	return (1);
}

int			put_rra_2(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp_beg;
	t_pile *tmp;

	ft_putstr("rra\n");
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

int			put_rrb_2(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp_beg;
	t_pile *tmp;

	ft_putstr("rrb\n");
	if (*begin_a || *begin_b)
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
