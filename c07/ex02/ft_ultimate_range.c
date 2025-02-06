/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:21:43 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/30 16:21:29 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	counter;
	int	len;
	int	*buffer;

	counter = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	buffer = (int *) malloc(sizeof(int) * len);
	if (!buffer)
	{
		*range = 0;
		return (-1);
	}
	*range = buffer;
	while (counter < len)
	{
		buffer[counter] = min + counter;
		counter++;
	}
	return (len);
}
