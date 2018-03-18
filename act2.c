/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:21:50 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:22:04 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_rrb(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp_beg;
	t_pile *tmp;

	if (count_lst(*begin_b) < 2)
		return (1);
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

int			put_rrr(t_pile **begin_a, t_pile **begin_b)
{
	if (!put_rra(begin_a, begin_b))
		return (1);
	if (!put_rrb(begin_a, begin_b))
		return (1);
	return (1);
}
