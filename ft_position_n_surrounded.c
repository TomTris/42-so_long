/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_position_n_surrounded.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:39:39 by qdo               #+#    #+#             */
/*   Updated: 2024/04/15 13:50:42 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	ft_position_expo(t_map_data *map, char epc)
{
	t_position	ret;
	int			i;
	int			j;

	ret.l_cnt = -1;
	i = 0;
	while (++i <= map[0].l_cnt)
	{
		j = -1;
		while (++j < map[map[0].l_cnt].l_len)
		{
			if (map[i].ct[j] == epc)
			{
				if (ret.l_cnt != -1)
					return (ret.l_cnt = -1, write(1, ">1", 3), ret);
				ret.l_cnt = i;
				ret.l_len = j;
			}
		}
	}
	return (ret);
}

t_position	*ft_position_c_join(t_position *ori, int l_cnt_new, int l_len_new)
{
	t_position	*ret;
	int			i;

	ret = (t_position *)malloc((ori[0].l_len + 2) * sizeof(t_position));
	if (ret == 0)
		return (free(ori), NULL);
	i = -1;
	while (++i <= ori[0].l_len)
		ret[i] = ori[i];
	ret[i].l_cnt = l_cnt_new;
	ret[i].l_len = l_len_new;
	ret[0].l_len += 1;
	free(ori);
	return (ret);
}

t_position	*ft_position_co(t_map_data *map)
{
	t_position	*ret;
	int			i;
	int			j;

	ret = (t_position *)malloc(1 * sizeof(t_position));
	if (ret == 0)
		return (0);
	ret[0].l_len = 0;
	i = 0;
	while (++i <= map[0].l_cnt)
	{
		j = -1;
		while (++j <= map[map[0].l_cnt].l_len)
		{
			if (map[i].ct[j] == 'C')
			{
				ret = ft_position_c_join(ret, i, j);
				if (ret == 0)
					return (ret);
			}
		}
	}
	return (ret);
}

int	ft_check_surrounded(t_map_data *map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (map[1].ct[i] == '1')
		i++;
	if (map[1].ct[i] != '\n')
		return (0);
	j = 0;
	while (++j < map[0].l_cnt)
		if (map[j].ct[0] != '1' || map[j].ct[i - 1] != '1')
			return (0);
	k = -1;
	while (++k < i)
		if (map[j].ct[k] != '1')
			return (0);
	return (1);
}
