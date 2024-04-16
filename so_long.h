/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:46:48 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 18:33:47 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include <stdio.h>
# include "mlx/mlx.h"
# include <stdlib.h>

typedef struct s_position
{
	int				l_cnt;
	int				l_len;
}	t_position;

typedef struct s_map_data
{
	int		l_cnt;
	int		l_len;
	char	*ct;
}	t_map_data;

typedef struct s_wnd_create
{
	void	*cnect;
	void	*wnd;
	void	*img_wall;
	void	*img_po;
	void	*img_ex1;
	void	*img_ex2;
	void	*img_co;
	void	*img_ep;
	void	*img_en;
	void	*img_win;
	void	*img_lose;
	void	*img_lose2;
	void	*img_po2;
	void	*img_en2;
	int		he;
	int		wi;
	int		he2;
	int		wi2;
	int		he3;
	int		wi3;
	int		i;
	int		j;
}	t_wnd_create;

typedef struct s_save
{
	t_position		ex;
	t_position		po;
	t_position		*co;
	t_map_data		*map;
	t_position		*p_to_x;
	t_wnd_create	ws;
	t_position		*en;
	void			*img_po_up;
	void			*img_po_left;
	void			*img_po_down;
	void			*img_po_right;
	void			*img_en_up;
	void			*img_en_left;
	void			*img_en_down;
	void			*img_en_right;
}	t_save;

int			ft_belongs_go_thr(const char *new_str, char char1, int new);
t_position	ft_position_expo(t_map_data *map, char epc);
t_position	*ft_position_co(t_map_data *map);
void		ft_free_map(t_map_data *map);
t_save		ft_map_check(t_map_data *map);
int			ft_check_surrounded(t_map_data *map);
int			ft_check_up(t_map_data *map, t_position *re, t_position present);
int			ft_check_left(t_map_data *map, t_position *re, t_position present);
int			ft_check_down(t_map_data *map, t_position *re, t_position present);
int			ft_check_right(t_map_data *map, t_position *re, t_position present);
t_position	ft_position_expo(t_map_data *map, char epc);
t_position	*ft_position_co(t_map_data *map);
int			ft_check_path2(t_map_data *map, t_position *re_old,
				t_position po_2, t_position present);
t_save		*ft_check_map(int argc, char *argv[]);

int			ft_close(void *param);
int			ft_detect(int keysym, void *param);

int			ft_ws_create2(t_save *save);
void		ft_generate_pic(t_save *save, t_map_data *map, int i, int j);

void		ft_delete_co(t_save *save, int i, int j);
int			ft_find_co(t_save *save, int i, int j);
int			ft_find_p_to_x(t_save *save, int i, int j);

void		ft_check_exit_win(t_save *save);
void		ft_up(t_save *save, int *cnt);
void		ft_down(t_save *save, int *cnt);
void		ft_left(t_save *save, int *cnt);
void		ft_right(t_save *save, int *cnt);

void		ft_up_en(t_save *save, t_position *en);
void		ft_down_en(t_save *save, t_position *en);
void		ft_left_en(t_save *save, t_position *en);
void		ft_right_en(t_save *save, t_position *en);
int			ft_check_en(t_save *save, int check);
t_position	ft_create_en(t_save *save);
int			ft_check_en(t_save *save, int check);
void		ft_strcpy(char *des, char *src);
char		*ft_dis(int step_cnt);
void		ft_display_for_movement(t_save *save, int *step_cnt);
void		ft_img_en_ptrs(t_save *save);
void		ft_img_po_ptrs(t_save *save);

#endif