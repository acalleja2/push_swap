/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 05:24:42 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:13:38 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_sa_2(t_pile **begin_a, t_pile **begin_b)
{
	int tmp;

	ft_putstr("sa\n");
	if (*begin_a || *begin_b)
		;
	if (!*begin_a || !(*begin_a)->next)
		return (0);
	tmp = (*begin_a)->value;
	(*begin_a)->value = (*begin_a)->next->value;
	(*begin_a)->next->value = tmp;
	return (1);
}

int			put_sb_2(t_pile **begin_a, t_pile **begin_b)
{
	int tmp;

	ft_putstr("sb\n");
	if (*begin_a || *begin_b)
		;
	if (!*begin_b || !(*begin_b)->next)
		return (0);
	tmp = (*begin_b)->value;
	(*begin_b)->value = (*begin_b)->next->value;
	(*begin_b)->next->value = tmp;
	return (1);
}

int			put_ss_2(t_pile **begin_a, t_pile **begin_b)
{
	ft_putstr("ss\n");
	if (put_sa_2(begin_a, begin_b) || put_sb_2(begin_a, begin_b))
		return (0);
	return (1);
}

int			put_pa_2(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;

	ft_putstr("pa\n");
	if (*begin_a || *begin_b)
		;
	if (!*begin_b)
		return (0);
	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	tmp->value = (*begin_b)->value;
	tmp->next = *begin_a;
	*begin_a = tmp;
	remove_elem(begin_b);
	return (1);
}

int			put_pb_2(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;

	ft_putstr("pb\n");
	if (*begin_a || *begin_b)
		;
	if (!*begin_a)
		return (0);
	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	tmp->value = (*begin_a)->value;
	tmp->next = *begin_b;
	*begin_b = tmp;
	remove_elem(begin_a);
	return (1);
}
