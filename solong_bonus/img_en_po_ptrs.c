/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_en_po_ptrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 23:04:26 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 19:14:32 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_img_en_ptrs2(t_save *save)
{
	save->img_en_up = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/en_up.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_en_up == 0)
		ft_close((void *)save);
	save->img_en_down = mlx_xpm_file_to_image(save->ws.cnect,
		"texture/en_down.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_en_down == 0)
		ft_close((void *)save);
	save->img_en_left = mlx_xpm_file_to_image(save->ws.cnect,
		"texture/en_left.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_en_left == 0)
		ft_close((void *)save);
	save->img_en_right = mlx_xpm_file_to_image(save->ws.cnect,
		"texture/en_right.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_en_right == 0)
		ft_close((void *)save);
	save->ws.img_en2 = mlx_xpm_file_to_image(save->ws.cnect,
		"texture/en2.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->ws.img_en2 == 0)
		ft_close((void *)save);
}

void	ft_img_en_ptrs(t_save *save)
{
	save->ws.img_po2 = 0;
	save->ws.img_en2 = 0;
	save->img_en_up = 0;
	save->img_en_down = 0;
	save->img_en_left = 0;
	save->img_en_right = 0;
	save->img_po_up = 0;
	save->img_po_down = 0;
	save->img_po_left = 0;
	save->img_po_right = 0;
	ft_img_en_ptrs2(save);
}

void	ft_img_po_ptrs(t_save *save)
{
	save->img_po_up = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/po_up.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_po_up == 0)
		ft_close((void *)save);
	save->img_po_down = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/po_down.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_po_down == 0)
		ft_close((void *)save);
	save->img_po_left = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/po_left.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_po_left == 0)
		ft_close((void *)save);
	save->img_po_right = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/po_right.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->img_po_right == 0)
		ft_close((void *)save);
	save->ws.img_po2 = mlx_xpm_file_to_image(save->ws.cnect,
			"texture/po2.xpm", &(save->ws.wi), &(save->ws.he));
	if (save->ws.img_po2 == 0)
		ft_close((void *)save);
}
