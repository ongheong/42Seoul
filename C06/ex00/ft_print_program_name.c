/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:06:05 by marvin            #+#    #+#             */
/*   Updated: 2022/02/22 01:06:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	size;

	(void)argc;
	size = 0;
	while (argv[0][size])
		size++;
	write(1, argv[0], size);
	write(1, "\n", 1);
	return (0);
}
