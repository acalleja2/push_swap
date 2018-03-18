/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:04:29 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/13 01:31:19 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			pars_error(char **tab, int i, t_pile **begin_a)
{
	int j;

	j = 0;
	while (tab[i][j])
	{
		if (j == 0 && !ft_isdigit(tab[i][j]))
		{
			if (tab[i][j] != '+' && tab[i][j] != '-')
				return (0);
		}
		else if (ft_isdigit(tab[i][j]) == 0)
			return (0);
		j++;
	}
	if (ft_latoi(tab[i]) < INT_MIN || ft_latoi(tab[i]) > INT_MAX)
		return (0);
	create_lst(begin_a, tab[i]);
	return (1);
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

int			len_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			main(int argc, char **argv)
{
	t_pile	*begin_a;
	t_pile	*begin_b;
	char	*line;
	int		len;

	if (argc == 1)
		return (0);
	begin_a = NULL;
	begin_b = NULL;
	if (!error_list(argc, argv, &begin_a, 0) || !check_double(begin_a))
		return (print_error(&begin_a, &begin_b));
	if (!begin_a)
		return (0);
	len = count_lst(begin_a);
	while (get_next_line(0, &line) && put_line(&line, &begin_a, &begin_b))
		free(line);
	if (check_list(begin_a, len) == 1)
		return (print_ok(&begin_a, &begin_b));
	else
		return (print_ko(&begin_a, &begin_b));
}
