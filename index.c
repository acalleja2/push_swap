/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 03:18:24 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/13 01:27:26 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			print_ko(t_pile **begin_a, t_pile **begin_b)
{
	write(1, "KO\n", 3);
	if (*begin_a)
		del_lst(begin_a);
	if (*begin_b)
		del_lst(begin_b);
	return (0);
}

int			index_fuction(char *line)
{
	char	*tab[11];
	int		i;

	i = 0;
	tab[0] = "sa";
	tab[1] = "sb";
	tab[2] = "ss";
	tab[3] = "pa";
	tab[4] = "pb";
	tab[5] = "ra";
	tab[6] = "rb";
	tab[7] = "rr";
	tab[8] = "rra";
	tab[9] = "rrb";
	tab[10] = "rrr";
	while (i < 11)
	{
		if (!ft_strcmp(line, tab[i]))
			return (i);
		i++;
	}
	return (-1);
}

int			put_line(char **line, t_pile **begin_a, t_pile **begin_b)
{
	t_func	*tab_f;
	int		i;

	if (index_fuction(*line) < 0)
	{
		free(*line);
		write(1, "Error\n", 6);
		if (*begin_a)
			del_lst(begin_a);
		if (*begin_b)
			del_lst(begin_b);
		exit(0);
	}
	tab_f = tab_function();
	i = tab_f[index_fuction(*line)](begin_a, begin_b);
	free(tab_f);
	return (i);
}

t_func		*tab_function(void)
{
	t_func	*tab_f;

	if (!(tab_f = (t_func *)malloc(sizeof(t_func) * 11)))
		exit(0);
	tab_f[0] = put_sa;
	tab_f[1] = put_sb;
	tab_f[2] = put_ss;
	tab_f[3] = put_pa;
	tab_f[4] = put_pb;
	tab_f[5] = put_ra;
	tab_f[6] = put_rb;
	tab_f[7] = put_rr;
	tab_f[8] = put_rra;
	tab_f[9] = put_rrb;
	tab_f[10] = put_rrr;
	return (tab_f);
}

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
