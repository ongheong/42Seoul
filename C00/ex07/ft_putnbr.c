/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:16:29 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/07 21:55:42 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void ft_putnbr(int nb)
{
	int index = 0;
	char arr[11];//안에는 최대수
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	while(nb >= 10)
	{
		arr[index] = nb%10 + '0';
		nb = nb/10;
		index++;
	} //nb가 한자리 수일 때까지 반복
	arr[index] = nb;
	while (index >= 0)
	{
		write(1, &arr[index], 1);
		index--;
	}
}

// / -> 몫 연산자
// % -> 나머지 연산자

int main(void)
{
	ft_putnbr(42);
}