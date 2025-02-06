/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:16:30 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/23 12:35:50 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}
