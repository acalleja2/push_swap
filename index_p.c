/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 05:36:33 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:54:27 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			put_rrr_2(t_pile **begin_a, t_pile **begin_b)
{
	ft_putstr("rrr\n");
	if (!put_rra_2(begin_a, begin_b))
		return (0);
	if (!put_rrb_2(begin_a, begin_b))
		return (0);
	return (1);
}

int			print_error2(t_pile **begin_a, t_pile **begin_b)
{
	write(1, "Error\n", 6);
	if (*begin_a)
		del_lst(begin_a);
	if (*begin_b)
		del_lst(begin_b);
	return (0);
}

int			index_fuction_2(char *line)
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
	t_func *tab_f;

	if (index_fuction_2(*line) < 0)
		return (0);
	tab_f = tab_function();
	return (tab_f[index_fuction_2(*line)](begin_a, begin_b));
}

t_func		*tab_function(void)
{
	t_func	*tab_f;

	if (!(tab_f = (t_func *)malloc(sizeof(t_func) * 11)))
		exit(0);
	tab_f[0] = put_sa_2;
	tab_f[1] = put_sb_2;
	tab_f[2] = put_ss_2;
	tab_f[3] = put_pa_2;
	tab_f[4] = put_pb_2;
	tab_f[5] = put_ra_2;
	tab_f[6] = put_rb_2;
	tab_f[7] = put_rr_2;
	tab_f[8] = put_rra_2;
	tab_f[9] = put_rrb_2;
	tab_f[10] = put_rrr_2;
	return (tab_f);
}
