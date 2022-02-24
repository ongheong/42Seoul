/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:00:04 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/24 12:08:30 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*put_array(long lnbr, int len, int arr_size, char *base_to);
int		ft_strlen(char *arr);

char	*ft_putnbr_base(int nbr, char *base_to)
{
	int		len;
	long	lnbr;
	char	*arr;
	int		arr_size;
	long	value;

	len = ft_strlen(base_to);
	arr_size = 1;
	if (nbr < 0)
	{
		lnbr = -nbr;
		arr_size++;
	}
	else
		lnbr = nbr;
	value = lnbr;
	while (value > len)
	{
		value = value / len;
		arr_size++;
	}
	if (nbr < 0)
		lnbr *= -1;
	arr = put_array(lnbr, len, arr_size, base_to);
	return (arr);
}

char	*put_array(long lnbr, int len, int arr_size, char *base_to)
{
	int		i;
	char	*arr;

	i = 0;
	arr = (char *)malloc(sizeof(char) * (arr_size + 1));
	if (lnbr < 0)
	{
		arr[i] = '-';
		i++;
		lnbr *= -1;
	}
	while (lnbr >= len)
	{
		arr[i] = base_to[lnbr % len];
		lnbr = lnbr / len;
		i++;
	}
	arr[i] = base_to[lnbr];
	arr[i + 1] = '\0';
	return (arr);
}

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (0);
}
