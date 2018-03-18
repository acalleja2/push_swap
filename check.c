/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 05:43:34 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 23:08:41 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_list(t_pile *begin, int len)
{
	t_pile *tmp;

	tmp = begin;
	while (tmp->next && tmp->value <= tmp->next->value)
		tmp = tmp->next;
	if (!tmp->next && count_lst(begin) == len)
		return (1);
	return (0);
}

int			count_lst(t_pile *begin)
{
	int i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i);
}

t_pile		*copie_lst(t_pile *begin, long start, long end)
{
	t_pile *tmp;
	t_pile *begin_cpy;

	if (start <= INT_MAX)
	{
		while (begin->value != start)
			begin = begin->next;
	}
	if (!(begin_cpy = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	begin_cpy->next = NULL;
	tmp = begin_cpy;
	tmp->value = begin->value;
	begin = begin->next;
	while (begin && begin->value != end)
	{
		if (!(tmp->next = (t_pile *)malloc(sizeof(t_pile))))
			exit(0);
		tmp->next->next = NULL;
		tmp->next->value = begin->value;
		begin = begin->next;
		tmp = tmp->next;
	}
	return (begin_cpy);
}

int			find_mediane(t_pile *begin, t_pivot *pivot, int size, int i)
{
	t_pile	*tmp;
	int		len;

	len = 0;
	pivot->prec = pivot->current;
	tmp = begin;
	while (len++ < size - 1 && begin->next)
		begin = begin->next;
	begin->next = NULL;
	begin = tmp;
	while (i++ < size / 2 + 1 && begin)
	{
		tmp = begin;
		pivot->current = tmp->value;
		while (tmp)
		{
			if (tmp->value < pivot->current)
				pivot->current = tmp->value;
			tmp = tmp->next;
		}
		begin = remove_if(&begin, pivot->current);
	}
	del_lst(&begin);
	return (pivot->current);
}

t_pile		*remove_if(t_pile **begin, int n)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp = *begin;
	if ((*begin)->value == n)
	{
		*begin = (*begin)->next;
		free(tmp);
		return (*begin);
	}
	while (tmp->next)
	{
		if (n == tmp->next->value)
		{
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
			return (*begin);
		}
		tmp = tmp->next;
	}
	return (*begin);
}
