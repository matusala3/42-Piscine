/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:31:01 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/27 19:16:29 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (i < power)
	{
		return (nb * ft_recursive_power(nb, power));
		i++;
	}
	return (1);
}
