/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:51:34 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/23 12:41:12 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen((char *)dest);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && (dest_len + i < size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
