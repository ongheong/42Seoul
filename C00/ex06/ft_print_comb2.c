/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:41:28 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/13 18:33:51 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_ab(int a, int b);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_ab(a, b);
			b++;
		}
		a++;
	}			
}

void	print_ab(int a, int b)
{
	char	itoc [5];
	int		i;

	itoc[0] = a / 10 + '0';
	itoc[1] = a % 10 + '0';
	itoc[2] = ' ';
	itoc[3] = b / 10 + '0';
	itoc[4] = b % 10 + '0';
	i = 0;
	while (i <= 4)
	{
		write(1, &itoc[i], 1);
		i++;
	}
	if (a < 98 && b <= 99)
		write(1, ", ", 2);
}
