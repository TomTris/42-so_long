/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_4_direction_en_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:42 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 19:15:32 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_up_en(t_save *save, t_position *en)
{
	int	i;
	int	j;

	i = en->l_cnt;
	j = en->l_len;
	if (ft_find_p_to_x(save, en->l_cnt - 1, en->l_len) == 1
		&& ft_find_co(save, en->l_cnt - 1, en->l_len) != 1
		&& (en->l_cnt - 1 != save->ex.l_cnt || en->l_len != save->ex.l_len))
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_en_up, save->ws.wi * j, save->ws.he * (i - 2));
		save->ws.i = 0;
		if (en->l_cnt - 1 == save->po.l_cnt && en->l_len == save->po.l_len)
		{
			ft_printf("You Lose\n");
			ft_detect(53, save);
		}
		en->l_cnt--;
	}
}

void	ft_down_en(t_save *save, t_position *en)
{
	int	i;
	int	j;

	i = en->l_cnt;
	j = en->l_len;
	if (ft_find_p_to_x(save, en->l_cnt + 1, en->l_len) == 1
		&& ft_find_co(save, en->l_cnt + 1, en->l_len) != 1
		&& (en->l_cnt + 1 != save->ex.l_cnt || en->l_len != save->ex.l_len))
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_en_down, save->ws.wi * j, save->ws.he * (i));
		save->ws.i = 0;
		if (en->l_cnt + 1 == save->po.l_cnt && en-> l_len == save->po.l_len)
		{
			ft_printf("You Lose\n");
			ft_detect(53, save);
		}
		en->l_cnt++;
	}
}

void	ft_right_en(t_save *save, t_position *en)
{
	int	i;
	int	j;

	i = en->l_cnt;
	j = en->l_len;
	if (ft_find_p_to_x(save, en->l_cnt, en->l_len + 1) == 1
		&& ft_find_co(save, en->l_cnt, en->l_len + 1) != 1
		&& (en->l_cnt != save->ex.l_cnt || en->l_len + 1 != save->ex.l_len))
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_en_right, save->ws.wi * (j + 1), save->ws.he * (i - 1));
		save->ws.i = 0;
		if (en->l_cnt == save->po.l_cnt && en->l_len + 1 == save->po.l_len)
		{
			ft_printf("You Lose\n");
			ft_detect(53, save);
		}
		en->l_len++;
	}
}

void	ft_left_en(t_save *save, t_position *en)
{
	int	i;
	int	j;

	i = en->l_cnt;
	j = en->l_len;
	if (ft_find_p_to_x(save, en->l_cnt, en->l_len - 1) == 1
		&& ft_find_co(save, en->l_cnt, en->l_len - 1) != 1
		&& (en->l_cnt != save->ex.l_cnt || en->l_len - 1 != save->ex.l_len))
	{
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->ws.img_ep, save->ws.wi * j, save->ws.he * (i - 1));
		mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
			save->img_en_left, save->ws.wi * (j - 1), save->ws.he * (i - 1));
		save->ws.i = 0;
		if (en->l_cnt == save->po.l_cnt && en->l_len - 1 == save->po.l_len)
		{
			ft_printf("You Lose\n");
			ft_detect(53, save);
		}
		en->l_len--;
	}
}
