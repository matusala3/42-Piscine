/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:56:33 by magebreh          #+#    #+#             */
/*   Updated: 2025/02/06 14:41:24 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (is_sep(str[i + 1], charset) == 1
			&& is_sep(str[i], charset) == 0)
			words++;
		i++;
	}
	return (words);
}

void	ft_strcpy(char *dest, char *from, char *charset)
{
	int	j;

	j = 0;
	while (is_sep(from[j], charset) == 0)
	{
		dest[j] = from[j];
		j++;
	}
	dest[j] = '\0';
}

void	split_words(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (is_sep(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) *(j + 1));
			ft_strcpy(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		words;

	words = count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	res[words] = 0;
	split_words(res, str, charset);
	return (res);
}
