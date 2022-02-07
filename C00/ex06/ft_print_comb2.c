/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:41:28 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/07 21:56:29 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_ab(int a, int b);

void	ft_print_comb2(void)
{
	int a;
	int b;
	
	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			while (a < b)
			{
				print_ab(a, b);
				b++;
				write(1, ",", 1);
				write(1, " ", 1);
			}
			b++;
		}
		a++;
	}			
}

int main(void)
{
	ft_print_comb2();
	return (0);
}

void	print_ab(int a, int b)
{
	if( a < 10 || b < 10)
	{
		write(1, "0", 1);
		write(1, *&a + '0', 1);
		write(1, "0", 1);
		write(1, &b, 1);
	}
	else
	{
		write(1, &a, 1);
		write(1, &b, 1);
	}
}

//-> 집 가서 디버거 찍어보기