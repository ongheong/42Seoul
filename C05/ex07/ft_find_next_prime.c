/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:37:02 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/23 11:40:14 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	check_prime(long lnb);

int	ft_find_next_prime(int nb)
{
	long	lnb;

	lnb = nb;
	if (lnb <= 0)
		return (2);
	while (1)
	{
		if (check_prime(lnb) != 0)
			return ((int)lnb);
		lnb++;
	}
}

long	check_prime(long lnb)
{
	long	i;

	i = 3;
	if (lnb % 2 == 0 && lnb != 2)
		return (0);
	while (i <= lnb / i)
	{
		if (lnb % i == 0)
			return (0);
		i += 2;
	}
	return (lnb);
}
