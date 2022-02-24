/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:11:08 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/23 11:22:18 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	add;

	add = 0;
	if (index == 1 || index == 0)
		return (index);
	if (index == 2)
		return (1);
	if (index < 0)
		return (-1);
	while (index > 2)
	{
		add = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (add);
	}
	return (add);
}
