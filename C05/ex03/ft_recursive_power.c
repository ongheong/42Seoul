/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:50:23 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/23 11:33:36 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0 && nb == 0)
		return (1);
	else if (power == 0)
		return (1);
	else if (nb == 0)
		return (0);
	else if (power < 0)
		return (0);
	return (ft_recursive_power(nb, power - 1) * nb);
}
