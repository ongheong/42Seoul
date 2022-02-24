/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:09:08 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/21 15:39:23 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(unsigned int unnbr, unsigned int len, char *base);
int		checkbase(char *base);
int		check_same_number(char *base, int i);

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	unnbr;

	len = 0;
	while (base[len])
	{
		len++;
	}
	if (checkbase(base) == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			unnbr = -nbr;
		}
		else
			unnbr = nbr;
		print_nbr(unnbr, len, base);
	}
}

void	print_nbr(unsigned int unnbr, unsigned int len, char *base)
{
	int				i;
	char			arr[11];

	i = 0;
	while (unnbr >= len)
	{
		arr[i] = base[unnbr % len];
		unnbr = unnbr / len;
		i++;
	}
	arr[i] = base[unnbr];
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
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
