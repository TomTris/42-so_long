/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:14:51 by qdo               #+#    #+#             */
/*   Updated: 2024/04/16 19:17:40 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (++i <= map[0].l_cnt)
		free(map[i].ct);
	free (map);
}

int	ft_check_get_line(char *str)
{
	static int	sta_str_len = -1;
	int			i;

	if (sta_str_len == -2)
		return (0);
	if (str == 0 || ft_strlen(str) < 3
		|| (ft_strlen(str) == 3 && str[2] == '\n'))
		return (0);
	if (sta_str_len == -1)
	{
		sta_str_len = ft_strlen(str);
		if (sta_str_len == 3)
			return (0);
	}
	else if ((int) ft_strlen(str) == sta_str_len - 1)
		sta_str_len = -2;
	else if ((int) ft_strlen(str) != sta_str_len)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] != '1' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != '0' && str[i] != 'E' && str[i] != '\n')
			return (0);
	return (1);
}

t_map_data	*ft_map_cpy(t_map_data *map_old, char *get_line)
{
	t_map_data	*map_new;
	int			i;

	if (ft_check_get_line(get_line) == 0)
		return (ft_free_map(map_old), NULL);
	map_new = (t_map_data *)malloc((map_old[0].l_cnt + 2) * sizeof(t_map_data));
	if (map_new == 0)
		return (ft_free_map(map_old), NULL);
	map_new[0].l_cnt = map_old[0].l_cnt + 1;
	map_new[0].l_len = map_old[0].l_len;
	map_new[map_new[0].l_cnt].ct = get_line;
	map_new[map_new[0].l_cnt].l_cnt = map_new[0].l_cnt;
	map_new[map_new[0].l_cnt].l_len = ft_strlen(get_line);
	i = 0;
	while (++i <= map_old[0].l_cnt)
		map_new[i] = map_old[i];
	return (free(map_old), map_new);
}

//only 5 type of charaters and '\n', and at least 3 columns,
//last get_line has less 1 character than other, AT LEAST 3 lines.
t_map_data	*ft_map_create(char **argv)
{
	int			fd;
	t_map_data	*map;

	fd = open(argv[1], O_RDWR);
	map = (t_map_data *)malloc(1 * sizeof(t_map_data));
	if (map == 0)
		return (0);
	map[0].l_cnt = 0;
	map = ft_map_cpy(map, get_next_line(fd));
	if (map == 0)
		return (0);
	map[0].l_len = map[1].l_len;
	while (map[0].l_len == map[map[0].l_cnt].l_len)
	{
		map = ft_map_cpy(map, get_next_line(fd));
		if (map == 0)
			return (0);
	}
	if (map[0].l_cnt < 3)
		return (write(1, "< 3 lines", 7), ft_free_map(map), NULL);
	return (map);
}

t_save	*ft_check_map(int argc, char *argv[])
{
	t_map_data		*map;
	size_t			len;
	static t_save	save;

	if (argc != 2)
		return (ft_printf("#1 map"), NULL);
	len = ft_strlen(argv[1]);
	if (len <= 3 || argv[1][len - 1] != 'r' || argv[1][len -2] != 'e'
		|| argv[1][len - 3] != 'b' || argv[1][len - 4] != '.')
		return (ft_printf("wrong name\n"), NULL);
	map = ft_map_create(argv);
	if (map == NULL)
		return (write(1, "create invalid", 14), NULL);
	save = ft_map_check(map);
	if (save.ex.l_cnt == -1)
		return (ft_printf("map_check invalid\n"), ft_free_map(map), NULL);
	else
		return (save.map = map, ft_printf("map valid\n"), &save);
}
