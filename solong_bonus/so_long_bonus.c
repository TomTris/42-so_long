/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:04:15 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 15:10:14 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_img_load2(void *param)
{
	t_save			*save;
	t_wnd_create	*ws;

	save = (t_save *)param;
	ws = &save->ws;
	if (save->co[0].l_len != 0)
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_ex1,
			ws->wi * save->ex.l_len, ws->he * (save->ex.l_cnt - 1));
	else
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_ex2,
			ws->wi * save->ex.l_len, ws->he * (save->ex.l_cnt - 1));
	if (ws->i == 2000)
	{
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_po,
			ws->wi * save->po.l_len, ws->he * (save->po.l_cnt - 1));
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_en,
			ws->wi * save->en->l_len, ws->he * (save->en->l_cnt - 1));
	}
	else
	{
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_po2,
			ws->wi * save->po.l_len, ws->he * (save->po.l_cnt - 1));
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_en2,
			ws->wi * save->en->l_len, ws->he * (save->en->l_cnt - 1));
	}
}

int	ft_img_load(void *param)
{
	t_save			*save;
	t_wnd_create	*ws;

	save = (t_save *)param;
	ws = &save->ws;
	if (save->ws.i < 0)
		return (1);
	save->ws.i++;
	if (ws->i == 4001)
		ws->i = 0;
	if (ws->i == 2000 || ws->i == 4000)
	{
		save = (t_save *)param;
		ws = &save->ws;
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_ep,
			ws->wi * save->po.l_len, ws->he * (save->po.l_cnt - 1));
		mlx_put_image_to_window(ws->cnect, ws->wnd, ws->img_ep,
			ws->wi * save->en->l_len, ws->he * (save->en->l_cnt - 1));
		ft_img_load2((void *)save);
	}
	return (1);
}

int	ft_ws_create1(t_save *save, t_wnd_create *ws, t_map_data *map)
{
	ws->cnect = mlx_init();
	if (ws->cnect == 0)
		return (ft_close((void *)save));
	ws->wi = 100;
	ws->he = 100;
	ws->wnd = mlx_new_window(ws->cnect, ws->wi * (map[1].l_len - 1),
			ws->he * (map[0].l_cnt), "Sword_of_hero");
	if (ws->wnd == 0)
		return (ft_close((void *)save));
	if (ft_ws_create2(save) == 1)
		return (ft_close((void *)save), 1);
	ft_generate_pic(save, save->map, 0, 0);
	ft_check_en(save, 1);
	mlx_loop_hook(save->ws.cnect, &ft_img_load, save);
	mlx_hook(ws->wnd, 17, 0, &ft_close, save);
	mlx_key_hook(ws->wnd, &ft_detect, save);
	mlx_loop(ws->cnect);
	return (0);
}

int	ft_check0(t_save *save)
{
	int	i;
	int	check;
	int	j;

	i = 0;
	check = 0;
	while (++i <= save->map[0].l_cnt)
	{
		j = -1;
		while (++j < save->map[1].l_len - 1)
		{
			if (save->map[i].ct[j] == '0')
			{
				check = 1;
				break ;
			}
		}
	}
	if (check == 0)
		return (free(save->p_to_x), free(save->co), ft_free_map(save->map), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_save		*save;

	if (argc != 2 || argv == 0)
		return (write(1, "check input\n", 12), 1);
	save = ft_check_map(argc, argv);
	if (save == NULL)
		return (1);
	if (ft_check0(save) == 1)
	{
		ft_printf("But no empty space, ");
		ft_printf("need at least 1 space '0' for bonus part\n", 20);
		return (1);
	}
	save->ws.i = 0;
	save->ws.img_wall = 0;
	save->ws.img_co = 0;
	save->ws.img_ex1 = 0;
	save->ws.img_ex2 = 0;
	save->ws.img_po = 0;
	save->ws.img_ep = 0;
	save->ws.img_en = 0;
	ft_img_en_ptrs(save);
	ft_img_po_ptrs(save);
	ft_ws_create1(save, &save->ws, save->map);
	return (0);
}
