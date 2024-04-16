/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_4_direction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:51:18 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 19:14:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_exit_win(t_save *save)
{
	t_map_data	*map;

	map = save->map;
	if (save->co[0].l_len == 0 && save->po.l_cnt == save->ex.l_cnt
		&& save->po.l_len == save->ex.l_len)
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd, save->ws.img_win,
			(save->ws.wi * (map[1].l_len - 1) - save->ws.wi2) / 2,
			(save->ws.he * (save->map[0].l_cnt) - save->ws.he2) / 2);
		ft_printf("You Win\n");
		ft_detect(-2, save);
	}
	if (save->co[0].l_len == 0)
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd, save->ws.img_ex2,
			save->ws.wi * save->ex.l_len, save->ws.he * (save->ex.l_cnt - 1));
}

void	ft_up(t_save *save, int *cnt)
{
	int	i;
	int	j;

	i = save->po.l_cnt;
	j = save->po.l_len;
	if (ft_find_p_to_x(save, save->po.l_cnt - 1, save->po.l_len) == 1)
	{
		if (ft_find_co(save, save->po.l_cnt - 1, save->po.l_len) == 1)
			ft_delete_co(save, i - 1, j);
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		if (save->co[0].l_len != 0 && save->po.l_cnt == save->ex.l_cnt
			&& save->po.l_len == save->ex.l_len)
			mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
				save->ws.img_ex1, save->ws.wi * save->ex.l_len,
				save->ws.he * (save->ex.l_cnt - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_po_up, save->ws.wi * j, save->ws.he * (i - 2));
		*cnt = *cnt + 1;
		save->po.l_cnt--;
		save->ws.i = 0;
	}
	ft_check_exit_win(save);
}

void	ft_down(t_save *save, int *cnt)
{
	int	i;
	int	j;

	i = save->po.l_cnt;
	j = save->po.l_len;
	if (ft_find_p_to_x(save, save->po.l_cnt + 1, save->po.l_len) == 1)
	{
		if (ft_find_co(save, save->po.l_cnt + 1, save->po.l_len) == 1)
			ft_delete_co(save, i + 1, j);
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		if (save->co[0].l_len != 0 && save->po.l_cnt == save->ex.l_cnt
			&& save->po.l_len == save->ex.l_len)
			mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
				save->ws.img_ex1, save->ws.wi * save->ex.l_len,
				save->ws.he * (save->ex.l_cnt - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_po_down, save->ws.wi * j, save->ws.he * (i));
		*cnt = *cnt + 1;
		save->po.l_cnt++;
		save->ws.i = 0;
	}
	ft_check_exit_win(save);
}

void	ft_right(t_save *save, int *cnt)
{
	int	i;
	int	j;

	i = save->po.l_cnt;
	j = save->po.l_len;
	if (ft_find_p_to_x(save, save->po.l_cnt, save->po.l_len + 1) == 1)
	{
		if (ft_find_co(save, save->po.l_cnt, save->po.l_len + 1) == 1)
			ft_delete_co(save, i, j + 1);
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		if (save->co[0].l_len != 0 && save->po.l_cnt == save->ex.l_cnt
			&& save->po.l_len == save->ex.l_len)
			mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
				save->ws.img_ex1, save->ws.wi * save->ex.l_len,
				save->ws.he * (save->ex.l_cnt - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_po_right, save->ws.wi * (j + 1), save->ws.he * (i - 1));
		*cnt = *cnt + 1;
		save->po.l_len++;
		save->ws.i = 0;
	}
	ft_check_exit_win(save);
}

void	ft_left(t_save *save, int *cnt)
{
	int	i;
	int	j;

	i = save->po.l_cnt;
	j = save->po.l_len;
	if (ft_find_p_to_x(save, save->po.l_cnt, save->po.l_len - 1) == 1)
	{
		if (ft_find_co(save, save->po.l_cnt, save->po.l_len - 1) == 1)
			ft_delete_co(save, i, j - 1);
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		if (save->co[0].l_len != 0 && save->po.l_cnt == save->ex.l_cnt
			&& save->po.l_len == save->ex.l_len)
			mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
				save->ws.img_ex1, save->ws.wi * save->ex.l_len,
				save->ws.he * (save->ex.l_cnt - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_po_left, save->ws.wi * (j - 1), save->ws.he * (i - 1));
		*cnt = *cnt + 1;
		save->po.l_len--;
		save->ws.i = 0;
	}
	ft_check_exit_win(save);
}
