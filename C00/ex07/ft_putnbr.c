/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:16:29 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/09 18:17:00 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int				index;
	char			arr[11];
	unsigned int	un_nb;

	index = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		un_nb = -nb;
	}
	else
		un_nb = nb;
	while (un_nb >= 10)
	{
		arr[index] = un_nb % 10 + '0';
		un_nb = un_nb / 10;
		index++;
	}
	arr[index] = un_nb + '0';
	while (index >= 0)
	{
		write(1, &arr[index], 1);
		index--;
	}
}
