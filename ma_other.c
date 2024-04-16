/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma_other.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:02:25 by qdo               #+#    #+#             */
/*   Updated: 2024/04/15 18:17:48 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_delete_co(t_save *save, int i, int j)
{
	int			k;
	t_position	*co;

	k = 0;
	co = save->co;
	while (++k <= co[0].l_len)
		if (co[k].l_cnt == i && co[k].l_len == j)
			break ;
	if (k == co[0].l_len)
		co[0].l_len--;
	else
	{
		co[k].l_len = co[co[0].l_len].l_len;
		co[k].l_cnt = co[co[0].l_len].l_cnt;
		co[0].l_len--;
	}
}

int	ft_find_co(t_save *save, int i, int j)
{
	int	k;

	k = 0;
	while (++k <= save->co[0].l_len)
		if (save->co[k].l_cnt == i && save->co[k].l_len == j)
			return (1);
	return (0);
}

int	ft_find_p_to_x(t_save *save, int i, int j)
{
	int	k;

	k = 0;
	while (++k <= save->p_to_x[0].l_len)
		if (save->p_to_x[k].l_cnt == i && save->p_to_x[k].l_len == j)
			return (1);
	return (0);
}
