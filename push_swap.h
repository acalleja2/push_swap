/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalleja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:15:16 by acalleja          #+#    #+#             */
/*   Updated: 2018/01/13 00:51:35 by acalleja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define WIDTH 2000
# define HEIGHT 1000

typedef struct	s_pile
{
	int				value;
	int				rang;
	struct s_pile	*next;
}				t_pile;
typedef struct	s_pivot
{
	long	current;
	long	prec;
	int		rang;
	int		bol;
	int		v;
	int		c;
	int		*len;
	int		*tri;
}				t_pivot;
typedef struct	s_visu
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*pix;
	int		trash;
	t_pile	*begin_a;
	t_pile	*begin_b;
	int		len;
	int		bol;
	int		speed;
	char	*line;
}				t_visu;
int				pars_error(char **tab, int i, t_pile **begin_a);
typedef int		(*t_func)(t_pile **, t_pile **);
t_func			*tab_function();
int				count_lst(t_pile *begin);
t_pile			*remove_if(t_pile **begin, int n);
int				error_list(int ac, char **av, t_pile **begin_a, int a);
int				put_sa(t_pile **begin_a, t_pile **begin_b);
int				put_sb(t_pile **begin_a, t_pile **begin_b);
int				put_ss(t_pile **begin_a, t_pile **begin_b);
int				put_pa(t_pile **begin_a, t_pile **begin_b);
int				put_pb(t_pile **begin_a, t_pile **begin_b);
int				put_ra(t_pile **begin_a, t_pile **begin_b);
int				put_rb(t_pile **begin_a, t_pile **begin_b);
int				put_rr(t_pile **begin_a, t_pile **begin_b);
int				put_rra(t_pile **begin_a, t_pile **begin_b);
int				put_rrb(t_pile **begin_a, t_pile **begin_b);
int				put_rrr(t_pile **begin_a, t_pile **begin_b);
int				put_sa_2(t_pile **begin_a, t_pile **begin_b);
int				put_sb_2(t_pile **begin_a, t_pile **begin_b);
int				put_ss_2(t_pile **begin_a, t_pile **begin_b);
int				put_pa_2(t_pile **begin_a, t_pile **begin_b);
int				put_pb_2(t_pile **begin_a, t_pile **begin_b);
int				put_ra_2(t_pile **begin_a, t_pile **begin_b);
int				put_rb_2(t_pile **begin_a, t_pile **begin_b);
int				put_rr_2(t_pile **begin_a, t_pile **begin_b);
int				put_rra_2(t_pile **begin_a, t_pile **begin_b);
int				put_rrb_2(t_pile **begin_a, t_pile **begin_b);
int				put_rrr_2(t_pile **begin_a, t_pile **begin_b);
void			free_tab(char **tab);
int				print_error(t_pile **begin_a, t_pile **begin_b);
int				print_ok(t_pile **begin_a, t_pile **begin_b);
int				print_ko(t_pile **begin_a, t_pile **begin_b);
int				index_function(char *line);
int				put_line(char **line, t_pile **begin_a, t_pile **begin_b);
int				check_list(t_pile *begin, int len);
int				count_lst(t_pile *begin);
int				len_tab(char **tab);
void			print_lst(t_pile *begin, int fd);
void			create_lst(t_pile **begin, char *nbr);
void			del_lst(t_pile **begin);
void			remove_elem(t_pile **begin);
int				check_double(t_pile *begin);
int				print_error2(t_pile **begin_a, t_pile **begin_b);
int				find_mediane(t_pile *begin, t_pivot *pivot, int size, int i);
t_pile			*copie_lst(t_pile *begin, long start, long end);
int				search_end(t_pile *begin_a);
int				len_list(t_pile *begin);
t_pile			*cpy_lst_min(t_pile *begin, int start, long len);
t_pile			*cpy_lst_supp(t_pile *begin, int start, long len);
t_pile			*cpy_min(t_pile *begin, int start, long len);
int				value_range(t_pile *begin, int value);
int				check_zone(t_pile *begin, long min, long max);
int				check_supp(t_pile *begin, int limit, int len);
int				check_inf(t_pile *begin, int limit, int len);
t_pile			*search_last(t_pile *begin);
void			action_move(t_pile **begin_a, t_pile **begin_b, int a);
int				search_min(t_pile *begin_a, int len);
int				search_max(t_pile *begin_a, int len);
void			print_list(t_pile *begin_a, t_pile *begin_b);
void			select_c(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot,
		int size);
void			select_sort(t_pile **begin_a, t_pile **begin_b, int *len,
		int *tri);
void			select_b(t_pile **begin_a, t_pile **begin_b, int *len,
		int *tri);
int				check_position(t_pile *begin);
int				search_min_tot(t_pile *begin_a, t_pile *begin_b, int len);
void			give_rang(t_pile *begin, t_pivot *pivot);
void			index_pile(t_pile **begin_a, t_pile *model);
t_pile			*sort_lst(t_pile *begin);
void			select_sort_b(t_pile **begin_a, t_pile **begin_b, int *tri);
void			select_sort_c(t_pile **begin_a, t_pile **begin_b,
		t_pivot *pivot, int size);
void			chose_direction_b(t_pile **begin_a, t_pile **begin_b,
		int mediane);
int				put_rra_test(t_pile **begin_b);
int				put_ra_test(t_pile **begin_b);
int				put_rrb_test(t_pile **begin_b);
int				put_rb_test(t_pile **begin_b);
void			quick1(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot,
		int *k);
void			quick1_b(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot,
		int *k);
int				check_domaine(int min, int max, t_pile *begin, int len);
void			chose_direction_a(t_pile **begin_a, t_pile **begin_b,
		int mediane);
int				rang_val(t_pile *begin, int val);
void			little_sort(t_pile **begin_a, t_pile **begin_b, t_pivot pivot);
void			quick_sort(t_pile **begin_a, t_pile **begin_b, t_pivot pivot);
void			quick2(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot);
int				quick3(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot);
int				quick4(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot);
void			init_var(t_pivot *pivot, t_pile **begin_a, t_pile **begin_b);
void			choice_sort(t_pile **begin_a, t_pile **begin_b, t_pivot *pivot);
void			ft_check(t_pile **begin_a, t_pile **begin_b, int len,
		t_pivot pivot);
void			free_tab(char **tab);
void			check_color(t_pile *begin_a, t_pivot pivot);
int				check_arg(int ac, char **av, t_pivot *pivot, int *a);
int				len_tab(char **tab);
void			medium_sort(t_pile **begin_a, t_pile **begin_b, t_pivot pivot);
void			put_a_nb(t_visu *visu);
int				stop_visu(int keycode);
t_pile			*find_elem(t_pile *begin, int index);
void			ft_put_background(int *pix);
double			height_elem(t_pile *begin, int len);
double			width_elem(t_pile *begin, int len);
void			ft_put_nb(int *pix, t_pile *begin, float y, int len);
void			ft_put_nb_b(int *pix, t_pile *begin, float y, int len);

#endif
