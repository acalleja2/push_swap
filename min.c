/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 10:18:11 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:52:16 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile		*lst_min(t_pile *begin, int max)
{
	t_pile *tmp;
	t_pile *tmp_beg;

	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	tmp->value = begin->value;
	tmp_beg = tmp;
	begin = begin->next;
	while (begin && begin->value != max)
	{
		if (!(tmp->next = (t_pile *)malloc(sizeof(t_pile))))
			exit(0);
		tmp->next->value = begin->value;
		tmp = tmp->next;
		begin = begin->next;
	}
	tmp->next = NULL;
	return (tmp_beg);
}

void		print_list(t_pile *begin_a, t_pile *begin_b)
{
	ft_putstr("\nPile A = ");
	print_lst(begin_a, 1);
	ft_putchar('\n');
	ft_putstr("Pile B = ");
	print_lst(begin_b, 1);
	ft_putchar('\n');
	ft_putchar('\n');
}

int			search_max(t_pile *begin_a, int len)
{
	int tmp;

	tmp = begin_a->value;
	while (begin_a && len)
	{
		if (tmp < begin_a->value)
			tmp = begin_a->value;
		begin_a = begin_a->next;
		len--;
	}
	return (tmp);
}

int			search_min(t_pile *begin_a, int len)
{
	int tmp;

	if (!begin_a)
		return (0);
	tmp = begin_a->value;
	while (begin_a && len)
	{
		if (tmp > begin_a->value)
			tmp = begin_a->value;
		begin_a = begin_a->next;
		len--;
	}
	return (tmp);
}
