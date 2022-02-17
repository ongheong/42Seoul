/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:19:58 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/10 11:03:37 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	go_recursive(char arr[], int n, int index, char now_num);

void	ft_print_combn(int n)
{
	char	arr[9];
	int		index;
	char	now_num;

	index = 0;
	now_num = '0';
	go_recursive(arr, n, index, now_num);
}

void	go_recursive(char arr[], int n, int index, char now_num)
{
	int	i;

	i = 0;
	if (index == n)
	{
		while (i < index)
		{
			write(1, &arr[i], 1);
			i++;
		}
		if (arr[0] + n < '0' + 10)
			write(1, ", ", 2);
		return ;
	}
	while (now_num <= '9')
	{
		arr[index] = now_num;
		go_recursive(arr, n, index + 1, now_num + 1);
		now_num++;
	}
}
