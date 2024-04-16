/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:04:15 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 18:44:46 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ws_create1(t_save *save, t_wnd_create *ws, t_map_data *map)
{
	ws->cnect = mlx_init();
	if (ws->cnect == 0)
		return (ft_close((void *)save), 1);
	ws->wi = 100;
	ws->he = 100;
	ws->wnd = mlx_new_window(ws->cnect, ws->wi * (map[1].l_len - 1),
			ws->he * (map[0].l_cnt), "Sword_of_hero");
	if (ws->wnd == 0)
		return (ft_close(save), 1);
	if (ft_ws_create2(save) == 1)
		return (ft_close(save), 1);
	ft_generate_pic(save, save->map, 0, 0);
	mlx_hook(ws->wnd, 17, 0, &ft_close, save);
	mlx_key_hook(ws->wnd, &ft_detect, save);
	mlx_loop(ws->cnect);
	return (0);
}

//khi free, nho free toan bo ben trong save
int	main(int argc, char **argv)
{
	t_save		*save;

	if (argc != 2 || argv == 0)
		return (printf("check input\n"), 1);
	save = ft_check_map(argc, argv);
	if (save == NULL)
		return (1);
	save->ws.i = 0;
	save->ws.img_wall = 0;
	save->ws.img_co = 0;
	save->ws.img_ex1 = 0;
	save->ws.img_ex2 = 0;
	save->ws.img_po = 0;
	save->ws.img_ep = 0;
	save->ws.img_lose = 0;
	save->ws.img_lose2 = 0;
	save->ws.img_win = 0;
	save->ws.wnd = 0;
	ft_ws_create1(save, &save->ws, save->map);
	return (0);
}
