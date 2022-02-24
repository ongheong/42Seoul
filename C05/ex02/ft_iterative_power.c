/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:41:19 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/23 11:07:04 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	value;

	value = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (nb == 0 && power > 0)
		return (0);
	while (power >= 1)
	{
		value = value * nb;
		power--;
	}
	return (value);
}
