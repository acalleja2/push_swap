/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 21:13:06 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/13 00:49:46 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "push_swap.h"

int		print_visu(t_visu *visu)
{
	int		trash;

	if (visu->bol)
	{
		if (!get_next_line(0, &visu->line))
			return (0);
		put_line(&visu->line, &visu->begin_a, &visu->begin_b);
	}
	else
		visu->bol = 1;
	visu->pix = (int *)mlx_get_data_addr(visu->img, &trash, &trash, &trash);
	ft_put_background(visu->pix);
	put_a_nb(visu);
	sleep(visu->speed);
	if (visu->line)
		free(visu->line);
	mlx_put_image_to_window(visu->mlx, visu->win, visu->img, 0, 0);
	return (0);
}

void	free_visu(t_visu *visu)
{
	free(visu);
	exit(0);
}

void	error(t_visu *visu, t_pile **begin_a, t_pile **begin_b)
{
	free(visu);
	if (begin_a)
		del_lst(begin_a);
	if (begin_b)
		del_lst(begin_b);
	exit(0);
}

void	img_visu(t_visu *visu, t_pile **begin_a, t_pile **begin_b)
{
	t_pile *tmp;

	visu->begin_a = *begin_a;
	visu->begin_b = *begin_b;
	visu->mlx = mlx_init();
	visu->win = mlx_new_window(visu->mlx, WIDTH, HEIGHT, "Visualitor Sort");
	visu->img = mlx_new_image(visu->mlx, WIDTH, HEIGHT);
	visu->len = count_lst(*begin_a);
	tmp = copie_lst(visu->begin_a, LONG_MAX, LONG_MAX);
	index_pile(&visu->begin_a, sort_lst(tmp));
	del_lst(&tmp);
	mlx_loop_hook(visu->mlx, &print_visu, visu);
	mlx_key_hook(visu->win, &stop_visu, 0);
	mlx_loop(visu->mlx);
}

int		main(int argc, char **argv)
{
	t_pile	*begin_a;
	t_pile	*begin_b;
	t_visu	*visu;

	if (argc == 1)
		return (0);
	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		exit(0);
	visu->speed = 0;
	visu->bol = 0;
	if (argc < 2 || argc > 3)
		free_visu(visu);
	begin_a = NULL;
	begin_b = NULL;
	if (!error_list(argc, argv, &begin_a, 0) || !check_double(begin_a))
		error(visu, &begin_a, &begin_b);
	if (!begin_a)
		free_visu(visu);
	img_visu(visu, &begin_a, &begin_b);
	return (0);
}
