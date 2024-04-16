/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_funcs_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:51:55 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 19:21:27 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_position	ft_create_en(t_save *save)
{
	t_position	en;
	int			k;

	k = save->p_to_x[0].l_len + 1;
	while (--k >= 1)
	{
		if (ft_find_co(save, save->p_to_x[k].l_cnt, save->p_to_x[k].l_len) != 1
			&& (save->p_to_x[k].l_cnt != save->ex.l_cnt
				|| save->p_to_x[k].l_len != save->ex.l_len))
			break ;
	}
	en.l_cnt = save->p_to_x[k].l_cnt;
	en.l_len = save->p_to_x[k].l_len;
	mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
		save->ws.img_en, save->ws.wi * en.l_len, save->ws.he * (en.l_cnt - 1));
	return (en);
}

int	ft_check_en(t_save *save, int check)
{
	static t_position	en;
	int					move;

	if (check == 1)
		return (en = ft_create_en(save), save->en = &en, 0);
	if (en.l_cnt == save->po.l_cnt && en.l_len == save->po.l_len)
	{
		ft_printf("You Lose\n");
		ft_detect(53, save);
		return (1);
	}
	move = 1 + (en.l_cnt + en.l_len + save->po.l_len + save->po.l_cnt) % 5;
	if (move == 1)
		ft_up_en(save, &en);
	else if (move == 2)
		ft_right_en(save, &en);
	else if (move == 3)
		ft_down_en(save, &en);
	else if (move == 4)
		ft_left_en(save, &en);
	return (1);
}

void	ft_strcpy(char *des, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		des[i] = src[i];
	des[i] = 0;
}

char	*ft_dis(int step_cnt)
{
	int		check;
	int		di_cnt;
	char	*ret;

	step_cnt++;
	check = step_cnt / 10;
	di_cnt = 1;
	while (check != 0)
	{
		di_cnt++;
		check = check / 10;
	}
	ret = (char *)malloc(di_cnt + 1 + 16);
	if (ret == 0)
		return (write(1, "malloc failed\n", 14), NULL);
	ft_strcpy(ret, "movement count: ");
	ret[16 + di_cnt] = 0;
	check = di_cnt + 16 - 1;
	while (di_cnt != 0)
	{
		ret[check--] = step_cnt % 10 + '0';
		step_cnt /= 10;
		di_cnt--;
	}
	return (ret);
}

void	ft_display_for_movement(t_save *save, int *step_cnt)
{
	char	*to_dis;

	mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
		save->ws.img_ep, 0, 0);
	mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
		save->ws.img_ep, save->ws.wi, 0);
	mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
		save->ws.img_wall, 0, 0);
	mlx_put_image_to_window(save->ws.cnect, save->ws.wnd,
		save->ws.img_wall, save->ws.wi, 0);
	to_dis = ft_dis(*step_cnt);
	if (to_dis == 0)
	{
		printf("malloc failed\n");
		ft_close((void *)save);
	}
	mlx_string_put(save->ws.cnect, save->ws.wnd, 50, 50, 200, to_dis);
	free(to_dis);
}
