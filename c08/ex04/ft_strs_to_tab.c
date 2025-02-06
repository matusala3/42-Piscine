/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:37:37 by magebreh          #+#    #+#             */
/*   Updated: 2025/02/03 15:01:00 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strrlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy( char *str, int size)
{
	char	*ret;
	int		i;

	ret = NULL;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
	{
		return (ret);
	}
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i += 1;
	}
	ret[i] = 0;
	return (ret);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;

	i = 0;
	ret = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == NULL)
		return (NULL);
	while (i < ac)
	{
		ret[i].str = av[i];
		ret[i].size = ft_strrlen(av[i]);
		ret[i].copy = ft_strcpy(av[i], ret[i].size);
		i++;
	}
	ret[i].str = 0;
	ret[i].size = 0;
	ret[i].copy = 0;
	return (ret);
}
