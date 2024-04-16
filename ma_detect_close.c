/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_detect_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:52:18 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 14:55:07 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_detect2(int keysym, t_save *save, int *step_cnt)
{
	if (keysym == 13)
		ft_up(save, step_cnt);
	else if (keysym == 2)
		ft_right(save, step_cnt);
	else if (keysym == 1)
		ft_down(save, step_cnt);
	else if (keysym == 0)
		ft_left(save, step_cnt);
	return (1);
}

int	ft_detect(int keysym, void *param)
{
	static int		step_cnt = 0;
	static int		check = 0;
	t_save			*save;

	save = (t_save *)param;
	if (check == -1)
		return (ft_close((void *)save));
	else if (keysym == -2)
		return (check = -1, 1);
	else if (check == -2)
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd, save->ws.img_lose,
			(save->ws.wi * (save->map[1].l_len - 1) - save->ws.wi2) / 2,
			(save->ws.he * (save->map[0].l_cnt) - save->ws.he2) / 2);
		return (check = -1, 1);
	}
	else if (keysym == 53)
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_lose2,
			(save->ws.wi * (save->map[1].l_len - 1) - save->ws.wi3) / 2,
			(save->ws.he * (save->map[0].l_cnt) - save->ws.he3) / 2);
		return (ft_printf("You Lose\n"), check = -2, 1);
	}
	return (ft_detect2(keysym, save, &step_cnt));
}

int	ft_close2(void *param)
{
	t_save	*save;

	save = (t_save *)param;
	if (save->ws.img_ep)
		mlx_destroy_image(save->ws.cnect, save->ws.img_ep);
	if (save->ws.wnd)
		mlx_destroy_window(save->ws.cnect, save->ws.wnd);
	exit(0);
	return (1);
}

int	ft_close(void *param)
{
	t_save	*save;

	save = (t_save *)param;
	free(save->co);
	free(save->p_to_x);
	ft_free_map(save->map);
	if (save->ws.img_wall)
		(mlx_destroy_image(save->ws.cnect, save->ws.img_wall));
	if (save->ws.img_co)
		mlx_destroy_image(save->ws.cnect, save->ws.img_co);
	if (save->ws.img_ex1)
		mlx_destroy_image(save->ws.cnect, save->ws.img_ex1);
	if (save->ws.img_ex2)
		mlx_destroy_image(save->ws.cnect, save->ws.img_ex2);
	if (save->ws.img_po)
		mlx_destroy_image(save->ws.cnect, save->ws.img_po);
	if (save->ws.img_lose)
		mlx_destroy_image(save->ws.cnect, save->ws.img_lose);
	if (save->ws.img_lose2)
		mlx_destroy_image(save->ws.cnect, save->ws.img_lose2);
	if (save->ws.img_win)
		mlx_destroy_image(save->ws.cnect, save->ws.img_win);
	return (ft_close2((void *)save));
}
