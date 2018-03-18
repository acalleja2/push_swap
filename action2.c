/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 03:15:09 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 22:51:10 by acalleja         ###   ########.fr       */
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

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			print_error(t_pile **begin_a, t_pile **begin_b)
{
	write(1, "Error\n", 6);
	if (*begin_a)
		del_lst(begin_a);
	if (*begin_b)
		del_lst(begin_b);
	return (0);
}

int			print_ok(t_pile **begin_a, t_pile **begin_b)
{
	write(1, "OK\n", 3);
	if (*begin_a)
		del_lst(begin_a);
	if (*begin_b)
		del_lst(begin_b);
	return (0);
}
