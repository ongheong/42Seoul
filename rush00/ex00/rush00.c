/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiypark <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:17:41 by kiypark           #+#    #+#             */
/*   Updated: 2022/02/06 18:02:50 by kiypark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	front_line(int x);
void	last_line(int x);
void	middle_line(int x);

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x > 0 && y > 0)
	{
		while (i < y)
		{
			i++;
			if (i == 1)
			{
				front_line(x);
			}
			else if (i == y)
			{
				last_line(x);
			}
			else
			{
				middle_line(x);
			}
		}
	}
}

void	front_line(int x)
{
	int	a;

	a = 1;
	if (x == 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('o');
		while (a < x - 1)
		{
			ft_putchar('-');
			a++;
		}
		ft_putchar('o');
		ft_putchar('\n');
	}
}

void	last_line(int x)
{
	int	a;

	a = 1;
	if (x == 1)
	{
		ft_putchar('o');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('o');
		while (a < x - 1)
		{
			ft_putchar('-');
			a++;
		}
		ft_putchar('o');
		ft_putchar('\n');
	}
}

void	middle_line(int x)
{
	int	a;

	a = 1;
	if (x == 1)
	{
		ft_putchar('|');
		ft_putchar('\n');
	}
	else
	{
		ft_putchar('|');
		while (a < x - 1)
		{
			ft_putchar(' ');
			a++;
		}
		ft_putchar('|');
		ft_putchar('\n');
	}
}
