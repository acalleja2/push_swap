/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 02:02:02 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 22:46:32 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_pile *begin, int fd)
{
	t_pile *tmp;

	tmp = begin;
	while (tmp)
	{
		ft_putnbr_fd(tmp->value, fd);
		ft_putchar_fd(' ', fd);
		tmp = tmp->next;
	}
}

void	create_lst(t_pile **begin, char *nbr)
{
	t_pile	*new;
	t_pile	*tmp;

	tmp = *begin;
	if (!(new = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	new->value = ft_atoi(nbr);
	if (!*begin)
	{
		new->next = NULL;
		*begin = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	del_lst(t_pile **begin)
{
	t_pile *tmp;

	while (*begin)
	{
		tmp = (*begin)->next;
		free(*begin);
		*begin = tmp;
	}
}

void	remove_elem(t_pile **begin)
{
	t_pile *tmp;

	tmp = *begin;
	if (!tmp->next)
		*begin = NULL;
	else
		*begin = tmp->next;
	free(tmp);
}

int		check_double(t_pile *begin)
{
	t_pile *tmp;

	while (begin)
	{
		tmp = begin->next;
		while (tmp)
		{
			if (begin->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		begin = begin->next;
	}
	return (1);
}
