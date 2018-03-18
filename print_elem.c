/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 07:09:21 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:52:53 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "push_swap.h"

t_pile	*find_elem(t_pile *begin, int index)
{
	int i;

	i = 1;
	while (i < index)
	{
		begin = begin->next;
		i++;
	}
	return (begin);
}

int		stop_visu(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

void	put_a_nb(t_visu *visu)
{
	int		len;
	float	y;
	float	y_2;

	y = 0;
	y_2 = 0;
	len = count_lst(visu->begin_a);
	while (len)
	{
		ft_put_nb(visu->pix, find_elem(visu->begin_a, len), y, visu->len);
		y += height_elem(visu->begin_a, visu->len);
		len--;
	}
	len = count_lst(visu->begin_b);
	while (len)
	{
		ft_put_nb_b(visu->pix, find_elem(visu->begin_b, len), y_2, visu->len);
		y_2 += height_elem(visu->begin_b, visu->len);
		len--;
	}
}
