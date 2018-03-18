/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:00:48 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 23:01:28 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pars_error(char **tab, int i, t_pile **begin_a)
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
