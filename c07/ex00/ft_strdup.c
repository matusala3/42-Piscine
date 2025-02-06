/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 09:35:21 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/30 17:28:26 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	char	*p;
	int		len;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	p = str;
	while (*src)
		*p++ = *src++;
	*p = '\0';
	return (str);
}
