/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 06:53:09 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 23:38:54 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_pile **begin_a, t_pile **begin_b, t_pivot pivot)
{
	while (len_list(*begin_a) >= 4)
	{
		while ((*begin_a)->value != search_min(*begin_a, len_list(*begin_a)))
		{
			chose_direction_a(begin_a, begin_b, search_min(*begin_a,
			len_list(*begin_b)));
			if (pivot.v)
				print_list(*begin_a, *begin_b);
		}
		put_pb_2(begin_a, begin_b);
		if (pivot.v)
			print_list(*begin_a, *begin_b);
	}
	little_sort(begin_a, begin_b, pivot);
	if (len_list(*begin_b) > 1 && (*begin_b)->value < (*begin_b)->next->value)
		put_sb_2(begin_a, begin_b);
	while (*begin_b)
	{
		put_pa_2(begin_a, begin_b);
		if (pivot.v)
			print_list(*begin_a, *begin_b);
	}
}

int		len_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		check_arg(int ac, char **av, t_pivot *pivot, int *a)
{
	if (ac == 2)
		return (1);
	if (ac >= 3)
	{
		if (!ft_strcmp(av[1], "-v"))
		{
			pivot->v = 1;
			(*a)++;
			return (1);
		}
		if (!ft_strcmp(av[1], "-c"))
		{
			(*a)++;
			pivot->c = 1;
			return (1);
		}
	}
	return (1);
}

void	check_color(t_pile *begin_a, t_pivot pivot)
{
	if (pivot.c)
	{
		write(1, "\x1B[32m", 6);
		ft_putstr("Sorted A = ");
		print_lst(begin_a, 1);
		ft_putchar('\n');
	}
}

void	free_tab(char **tab)
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
