/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magebreh <magebreh@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:40:00 by magebreh          #+#    #+#             */
/*   Updated: 2025/01/27 13:52:20 by magebreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	while (nb > 1)
	{
		result = result * nb;
		nb--;
	}
	return (result);
}
