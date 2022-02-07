/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:48:52 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/06 16:36:45 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphbet(void)
{
	char	a;

	a = 'a';
	while (a <= 'z')
	{
		write(1, &a, 1); // ssize_t write (int fd, const void *buf, size_t nbytes);
		a++;
	}
}

int	main(void)
{
	ft_print_alphbet();
	return (0);
}
