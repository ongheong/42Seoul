/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:34:41 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/23 11:39:14 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;
	long	lnb;

	i = 3;
	lnb = nb;
	if (lnb <= 1)
		return (0);
	if (lnb % 2 == 0 && lnb != 2)
		return (0);
	if (lnb == 2)
		return (1);
	while (i <= lnb / i)
	{
		if (lnb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
