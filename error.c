/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 03:08:17 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 23:25:25 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			error_list(int ac, char **av, t_pile **begin_a, int a)
{
	int		i;
	int		k;
	char	**tab;

	k = 1 + a;
	while (k < ac)
	{
		if (!(tab = ft_strsplit(av[k], ' ')))
			exit(0);
		i = 0;
		while (i < len_tab(tab))
		{
			if (pars_error(tab, i, begin_a) == 0)
				return (0);
			i++;
		}
		free_tab(tab);
		k++;
	}
	return (1);
}

int			put_sa(t_pile **begin_a, t_pile **begin_b)
{
	int tmp;
	int tmp2;

	if (*begin_a || *begin_b)
		;
	if (!*begin_a || !(*begin_a)->next)
		return (1);
	tmp = (*begin_a)->value;
	tmp2 = (*begin_a)->rang;
	(*begin_a)->value = (*begin_a)->next->value;
	(*begin_a)->rang = (*begin_a)->next->rang;
	(*begin_a)->next->value = tmp;
	(*begin_a)->next->rang = tmp2;
	return (1);
}

int			put_sb(t_pile **begin_a, t_pile **begin_b)
{
	int tmp;
	int tmp2;

	if (*begin_a || *begin_b)
		;
	if (!*begin_b || !(*begin_b)->next)
		return (1);
	tmp = (*begin_b)->value;
	tmp2 = (*begin_b)->rang;
	(*begin_b)->value = (*begin_b)->next->value;
	(*begin_b)->rang = (*begin_b)->next->rang;
	(*begin_b)->next->value = tmp;
	(*begin_b)->next->rang = tmp2;
	return (1);
}

int			put_ss(t_pile **begin_a, t_pile **begin_b)
{
	if (put_sa(begin_a, begin_b) || put_sb(begin_a, begin_b))
		return (1);
	return (1);
}

int			put_pa(t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;

	if (*begin_a || *begin_b)
		;
	if (!*begin_b)
		return (1);
	if (!(tmp = (t_pile *)malloc(sizeof(t_pile))))
		exit(0);
	tmp->value = (*begin_b)->value;
	tmp->rang = (*begin_b)->rang;
	tmp->next = *begin_a;
	*begin_a = tmp;
	remove_elem(begin_b);
	return (1);
}
