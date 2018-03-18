/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 03:46:09 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 23:32:39 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		init_var(t_pivot *pivot, t_pile **begin_a, t_pile **begin_b)
{
	pivot->current = 0;
	pivot->rang = 0;
	begin_a = NULL;
	begin_b = NULL;
}

void		sort_small(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot,
		int *len)
{
	little_sort(begin_a, begin_b, *pivot);
	*len = 0;
}

void		choice_sort(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot)
{
	int		len;
	int		tri;
	t_pile	*tmp;

	tri = 0;
	len = len_list(*begin_a);
	tmp = copie_lst(*begin_a, LONG_MAX, LONG_MAX);
	index_pile(begin_a, sort_lst(tmp));
	del_lst(&tmp);
	pivot->len = &len;
	pivot->tri = &tri;
	if (len < 4)
		sort_small(begin_a, begin_b, pivot, &len);
	else if (len != 0 && len < 6)
	{
		medium_sort(begin_a, begin_b, *pivot);
		len = 0;
	}
	while (len != 0)
	{
		pivot->bol = 0;
		quick_sort(begin_a, begin_b, *pivot);
	}
}

void		ft_check(t_pile **begin_a, t_pile **begin_b, int len, t_pivot pivot)
{
	if (check_list(*begin_a, len) == 1)
	{
		check_color(*begin_a, pivot);
		if (begin_a)
			del_lst(begin_a);
		if (begin_b)
			del_lst(begin_b);
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_pile		*begin_a;
	t_pile		*begin_b;
	t_pivot		pivot;
	int			a;
	int			i;

	a = 0;
	init_var(&pivot, &begin_a, &begin_b);
	if (!check_arg(argc, argv, &pivot, &a))
		return (0);
	if (!error_list(argc, argv, &begin_a, a) || !check_double(begin_a))
		return (print_error2(&begin_a, &begin_b));
	if (!begin_a)
		return (0);
	i = count_lst(begin_a);
	ft_check(&begin_a, &begin_b, i, pivot);
	choice_sort(&begin_a, &begin_b, &pivot);
	check_color(begin_a, pivot);
	del_lst(&begin_a);
	return (0);
}
