/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_n_generate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:49:02 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 19:20:44 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_ws_create4(t_save *save)
{
	save->ws.img_en = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/icesword.xpm", &save->ws.wi, &save->ws.he);
	if (save->ws.img_en == NULL)
		return (1);
	return (0);
}

int	ft_ws_create3(t_save *save)
{
	t_wnd_create	*ws;

	ws = &save->ws;
	save->ws.img_ep = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/coin.xpm", &save->ws.wi, &save->ws.he);
	if (save->ws.img_ep == NULL)
		return (ft_close((void *)save));
	save->ws.he2 = 300;
	save->ws.wi2 = 300;
	save->ws.img_win = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/youwin.xpm", &save->ws.wi2, &save->ws.he2);
	if (save->ws.img_win == NULL)
		return (ft_close((void *)save));
	save->ws.img_lose = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/loser.xpm", &save->ws.wi2, &save->ws.he2);
	if (save->ws.img_lose == NULL)
		return (ft_close((void *)save));
	save->ws.he3 = 350;
	save->ws.wi3 = 350;
	save->ws.img_lose2 = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/loser2.xpm", &save->ws.wi3, &save->ws.he3);
	if (save->ws.img_lose == NULL)
		return (ft_close((void *)save));
	return (ft_ws_create4(save));
}

int	ft_ws_create2(t_save *save)
{
	t_wnd_create	*ws;

	ws = &save->ws;
	ws->img_wall = mlx_xpm_file_to_image(ws->cnect,
			"texture/tree.xpm", &ws->wi, &ws->he);
	if (!ws->img_wall)
		return (ft_close((void *)save));
	save->ws.img_po = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/sword.xpm", &save->ws.wi, &save->ws.he);
	if (save->ws.img_po == NULL)
		return (ft_close((void *)save));
	save->ws.img_ex1 = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/shield1.xpm", &save->ws.wi, &save->ws.he);
	if (save->ws.img_ex1 == NULL)
		return (ft_close((void *)save));
	save->ws.img_ex2 = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/shield2.xpm", &save->ws.wi, &save->ws.he);
	if (save->ws.img_ex2 == NULL)
		return (ft_close((void *)save));
	save->ws.img_co = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/meat.xpm", &save->ws.wi, &save->ws.he);
	if (save->ws.img_co == NULL)
		return (ft_close((void *)save));
	return (ft_ws_create3(save));
}

void	ft_generate_pic(t_save *save, t_map_data *map, int i, int j)
{
	while (++i <= map[0].l_cnt)
	{
		j = -1;
		while (++j < map[1].l_len - 1)
		{
			mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
				save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
			if (map[i].ct[j] == 'C' && ft_find_co(save, i, j) == 1)
				mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
					save->ws.img_co, save->ws.wi * j, save->ws.he * (i - 1));
			else if (map[i].ct[j] == 'P')
				mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
					save->ws.img_po, save->ws.wi * j, save->ws.he * (i - 1));
			else if (map[i].ct[j] == 'E')
				mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
					save->ws.img_ex1, save->ws.wi * j, save->ws.he * (i - 1));
			else if (map[i].ct[j] == '1')
				mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
					save->ws.img_wall, save->ws.wi * j, save->ws.he * (i - 1));
		}
	}
}
