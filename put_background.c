/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 07:05:26 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/12 10:43:34 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "push_swap.h"

void		ft_put_background(int *pix)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (j > WIDTH / 2)
				pix[i * WIDTH + j] = 0x70BAE5;
			else
				pix[i * WIDTH + j] = 0x4663B2;
			j++;
		}
		i++;
	}
}

double		height_elem(t_pile *begin, int len)
{
	if (begin)
		;
	return ((float)HEIGHT / (float)len);
}

double		width_elem(t_pile *begin, int len)
{
	return ((WIDTH / 2) * (((float)begin->rang + 1) / (float)(len)));
}

void		ft_put_nb(int *pix, t_pile *begin, float y, int len)
{
	int i;
	int j;

	i = HEIGHT - y - height_elem(begin, len);
	while (i < HEIGHT - y)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (j >= ((1.0 - (double)width_elem(begin, len) / (WIDTH / 2)) / 2)
	* (WIDTH / 2) && j <= WIDTH / 2 - ((1.0 - (double)width_elem(begin, len) /
	(WIDTH / 2)) / 2) * (WIDTH / 2) && i <= HEIGHT - y && i >= HEIGHT -
	y - height_elem(begin, len))
				pix[i * WIDTH + j] = 0xEFFBF2;
			j++;
		}
		i++;
	}
}

void		ft_put_nb_b(int *pix, t_pile *begin, float y, int len)
{
	int i;
	int j;

	i = HEIGHT - y - height_elem(begin, len);
	while (i < HEIGHT - y)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (j >= (WIDTH / 2) + ((1.0 - (double)width_elem(begin, len) /
	(WIDTH / 2)) / 2) * (WIDTH / 2) && j <= WIDTH - ((1.0 -
	(double)width_elem(begin, len) / (WIDTH / 2)) / 2) * (WIDTH / 2) &&
	i <= HEIGHT - y && i >= HEIGHT - y - height_elem(begin, len))
				pix[i * WIDTH + j] = 0xEFFBF2;
			j++;
		}
		i++;
	}
}
