/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 05:49:30 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 11:07:37 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			len_list(t_pile *begin)
{
	int k;

	k = 0;
	while (begin)
	{
		k++;
		begin = begin->next;
	}
	return (k);
}

t_pile		*cpy_lst_supp(t_pile *begin, int start, long len)
{
	t_pile *new_beg;
	t_pile *new;

	if (!(new = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	new->value = start;
	new->next = NULL;
	new_beg = new;
	while (begin && len)
	{
		if (begin->value > start)
		{
			if (!(new = (t_pile *)malloc(sizeof(t_pile))))
				exit(0);
			new->value = begin->value;
			new->next = new_beg;
			new_beg = new;
		}
		len--;
		begin = begin->next;
	}
	return (new_beg);
}

t_pile		*cpy_lst_min(t_pile *begin, int start, long len)
{
	t_pile *new_beg;
	t_pile *new;

	if (!(new = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	new->value = start;
	new->next = NULL;
	new_beg = new;
	while (begin && len)
	{
		if (begin->value < start)
		{
			if (!(new = (t_pile *)malloc(sizeof(t_pile))))
				exit(0);
			new->value = begin->value;
			new->next = new_beg;
			new_beg = new;
		}
		begin = begin->next;
		len--;
	}
	return (new_beg);
}

t_pile		*cpy_min(t_pile *begin, int start, long len)
{
	t_pile *new_beg;
	t_pile *new;

	new_beg = NULL;
	while (begin && len)
	{
		if (begin->value < start)
		{
			if (!(new = (t_pile *)malloc(sizeof(t_pile))))
				exit(0);
			new->value = begin->value;
			new->next = new_beg;
			new_beg = new;
		}
		begin = begin->next;
		len--;
	}
	return (new_beg);
}

int			search_end(t_pile *begin_a)
{
	while (begin_a->next)
		begin_a = begin_a->next;
	return (begin_a->value);
}
