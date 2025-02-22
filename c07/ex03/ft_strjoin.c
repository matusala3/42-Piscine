/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:26:38 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/30 17:15:39 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	join_strings(char *dest, char *src, int start_index)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[start_index + i] = src[i];
		i++;
	}
	return (start_index + i);
}

int	calculate_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	total_len++;
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_len;
	int		i;
	int		index;
	char	*result;

	if (size == 0)
		return (NULL);
	total_len = calculate_total_length(size, strs, sep);
	result = (char *)malloc(sizeof(char) * total_len);
	if (!result)
		return (NULL);
	index = 0;
	i = 0;
	while (i < size)
	{
		index = join_strings(result, strs[i], index);
		if (i < size - 1)
			index = join_strings(result, sep, index);
		i++;
	}
	result[index] = '\0';
	return (result);
}
