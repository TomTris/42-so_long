/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdo <qdo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:51:38 by qdo               #+#    #+#             */
/*   Updated: 2024/03/14 15:35:34 by qdo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr1_null(void)
{
	if (write(1, "(null)", 6) < 0)
		return (-1);
	else
		return (6);
}

int	ft_puts(char *s)
{
	int		len;
	int		len2;
	int		i;
	char	*s1;

	if (s == NULL)
	{
		return (ft_putstr1_null());
	}
	s1 = s;
	i = 0;
	len = (int) ft_strlen(s);
	len2 = len;
	while (len > 0)
	{
		if (write(1, s + i, 1) < 0)
			return (-1);
		else
		{
			len--;
			i++;
		}
	}
	return (len2);
}
