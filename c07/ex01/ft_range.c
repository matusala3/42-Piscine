/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:07:10 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/30 16:16:16 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	len;
	int	*size;
	int	counter;

	len = max - min;
	counter = 0;
	if (min >= max)
		return (NULL);
	size = (int *)malloc(sizeof(int) * len);
	if (size == NULL)
		return (NULL);
	while (counter < len)
	{
		size[counter] = min + counter;
		counter++;
	}
	return (size);
}
