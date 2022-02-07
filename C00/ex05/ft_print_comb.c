/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:09:13 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/07 15:16:58 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_all(char a, char b, char c);

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{		
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				write_all(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}

void	write_all(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}
