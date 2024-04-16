/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 08:45:43 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 18:46:03 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_path3(t_map_data *map, t_position *re,
		t_position po_2, t_position present)
{
	t_position	new;

	if (ft_check_left(map, re, present) == 1)
	{
		new = re[re[0].l_len];
		if (ft_check_path2(map, re, po_2, new) == 1)
			return (1);
	}
	if (ft_check_right(map, re, present) == 1)
	{
		new = re[re[0].l_len];
		return (ft_check_path2(map, re, po_2, new));
	}
	return (0);
}

int	ft_check_path2(t_map_data *map, t_position *re,
		t_position po_2, t_position present)
{
	t_position	new;

	if (present.l_cnt == po_2.l_cnt && present.l_len == po_2.l_len)
		return (free(re), 1);
	if (ft_check_down(map, re, present) == 1)
	{
		new = re[re[0].l_len];
		if (ft_check_path2(map, re, po_2, new) == 1)
			return (1);
	}
	if (ft_check_up(map, re, present) == 1)
	{
		new = re[re[0].l_len];
		if (ft_check_path2(map, re, po_2, new) == 1)
			return (1);
	}
	return (ft_check_path3(map, re, po_2, present));
}

//if po_2 == none, return all possible path that position 1 can go to
t_position	*ft_check_path_of_p(t_map_data *map,
	t_position po_1, const char *go_thr)
{
	t_position	*re;
	t_position	none;

	none.l_cnt = -1;
	re = (t_position *)malloc
		((map[1].l_len * map[0].l_cnt) * sizeof(t_position));
	if (re == 0)
		return (0);
	re[0].l_len = 1;
	re[1].l_cnt = po_1.l_cnt;
	re[1].l_len = po_1.l_len;
	ft_belongs_go_thr(go_thr, 0, 1);
	ft_check_path2(map, re, none, po_1);
	return (re);
}

int	ft_p_to_x(t_position *p_to_x, t_position ex, t_position *co)
{
	int	i;
	int	j;
	int	stop1;

	i = 0;
	stop1 = 0;
	while (++i <= p_to_x[0].l_len && stop1 == 0)
		if (ex.l_cnt == p_to_x[i].l_cnt && ex.l_len == p_to_x[i].l_len)
			stop1 = 1;
	if (stop1 != 1)
		return (ft_printf("P-E invalid\n"), 0);
	i = 0;
	while (++i <= co[0].l_len)
	{
		j = 0;
		stop1 = 0;
		while (++j <= p_to_x[0].l_len && stop1 == 0)
			if (co[i].l_len == p_to_x[j].l_len
				&& co[i].l_cnt == p_to_x[j].l_cnt)
				stop1 = 1;
		if (stop1 == 0)
			return (ft_printf("one/more P-C invalid\n"), 0);
	}
	return (1);
}

t_save	ft_map_check(t_map_data *map)
{
	t_position	ex;
	t_position	po;
	t_position	*co;
	t_position	*p_to_x;
	t_save		save;

	if (ft_check_surrounded(map) == 0)
		return (ft_printf("surrounded invalid\n"), save.ex.l_cnt = -1, save);
	ex = ft_position_expo(map, 'E');
	if (ex.l_cnt == -1)
		return (ft_printf("E invalid\n"), save.ex.l_cnt = -1, save);
	po = ft_position_expo(map, 'P');
	if (po.l_cnt == -1)
		return (ft_printf("P invalid\n"), save.ex.l_cnt = -1, save);
	co = ft_position_co(map);
	if (co == 0 || co[0].l_len == 0)
		return (ft_printf("C invalid\n"), free(co), save.ex.l_cnt = -1, save);
	p_to_x = ft_check_path_of_p(map, po, "0CPE");
	if (ft_p_to_x(p_to_x, ex, co) == 0)
		return (free(p_to_x), free(co), save.ex.l_cnt = -1, save);
	save.ex = ex;
	save.co = co;
	save.po = po;
	save.p_to_x = p_to_x;
	return (save);
}
