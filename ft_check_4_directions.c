/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_4_directions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:53:01 by qdo               #+#    #+#             */
/*   Updated: 2024/04/12 17:57:38 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_belongs_go_thr(const char *new_str, char char1, int new)
{
	int					i;
	static const char	*go_thr;

	if (new == 1)
		return (go_thr = new_str, 1);
	i = -1;
	while (go_thr[++i])
		if (go_thr[i] == char1)
			return (1);
	return (0);
}

int	ft_check_up(t_map_data *map, t_position *re, t_position present)
{
	int	i;

	if (present.l_cnt - 1 <= 0)
		return (0);
	if (ft_belongs_go_thr(0, map[present.l_cnt - 1].ct[present.l_len], 0) == 0)
		return (0);
	i = 0;
	while (++i <= re[0].l_len)
		if (re[i].l_cnt == present.l_cnt - 1 && re[i].l_len == present.l_len)
			return (0);
	re[re[0].l_len + 1].l_cnt = present.l_cnt - 1;
	re[re[0].l_len + 1].l_len = present.l_len;
	re[0].l_len += 1;
	return (1);
}

int	ft_check_left(t_map_data *map, t_position *re, t_position present)
{
	int	i;

	if (present.l_cnt - 1 < 0)
		return (0);
	if (ft_belongs_go_thr(0, map[present.l_cnt].ct[present.l_len - 1], 0) == 0)
		return (0);
	i = 0;
	while (++i <= re[0].l_len)
		if (re[i].l_cnt == present.l_cnt && re[i].l_len == present.l_len - 1)
			return (0);
	re[re[0].l_len + 1].l_cnt = present.l_cnt;
	re[re[0].l_len + 1].l_len = present.l_len -1;
	re[0].l_len += 1;
	return (1);
}

int	ft_check_right(t_map_data *map, t_position *re, t_position present)
{
	int	i;

	if (present.l_len + 1 >= map[map[0].l_cnt].l_len)
		return (0);
	if (ft_belongs_go_thr(0, map[present.l_cnt].ct[present.l_len + 1], 0) == 0)
		return (0);
	i = 0;
	while (++i <= re[0].l_len)
		if (re[i].l_cnt == present.l_cnt && re[i].l_len == present.l_len + 1)
			return (0);
	re[re[0].l_len + 1].l_cnt = present.l_cnt;
	re[re[0].l_len + 1].l_len = present.l_len + 1;
	re[0].l_len += 1;
	return (1);
}

int	ft_check_down(t_map_data *map, t_position *re, t_position present)
{
	int	i;

	if (present.l_cnt + 1 > map[0].l_cnt)
		return (0);
	if (ft_belongs_go_thr(0, map[present.l_cnt + 1].ct[present.l_len], 0) == 0)
		return (0);
	i = 0;
	while (++i <= re[0].l_len)
		if (re[i].l_cnt == present.l_cnt + 1 && re[i].l_len == present.l_len)
			return (0);
	re[re[0].l_len + 1].l_cnt = present.l_cnt + 1;
	re[re[0].l_len + 1].l_len = present.l_len;
	re[0].l_len += 1;
	return (1);
}
