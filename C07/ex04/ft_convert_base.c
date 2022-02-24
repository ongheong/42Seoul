/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:14:32 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/24 12:23:38 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);
int		check_str_in_base(char c, char *base);
int		checkbase(char *base);
int		check_same_number(char *base, int i);
char	*ft_putnbr_base(int nbr, char *base_to);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*arr;

	if (checkbase(base_from) == 0 || checkbase(base_to) == 0)
		return (0);
	num = ft_atoi_base(nbr, base_from);
	arr = ft_putnbr_base(num, base_to);
	return (arr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	value;
	int	len;

	value = 0;
	sign = 1;
	len = 0;
	while (base[len])
		len++;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (check_str_in_base(*str, base) >= 0)
	{
		value = value * len + check_str_in_base(*str, base);
		if (check_str_in_base(*(str + 1), base) == -1)
			break ;
		str++;
	}
	return (value * sign);
}

int	check_str_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	checkbase(char *base)
{
	int	i;

	i = 0;
	if (base[i] == '\0' || base[i + 1] == '\0' )
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (check_same_number(base, i) == 1)
			return (0);
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

int	check_same_number(char *base, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (base[j] == base[i])
			return (1);
		j++;
	}
	return (0);
}
