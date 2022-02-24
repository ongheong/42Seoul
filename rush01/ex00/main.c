/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:11:33 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/13 17:39:26 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	dfs(int i, int visited[16][4], int block_view[16], int block[16]);

int	check_input(int argc, char **argv, int block_view[16])
{
	int	j;

	j = 0;
	if (argc != 2)
		return (0);
	while (argv[1][j] != '\0')
	{
		if (j % 2 == 0)
		{
			if (argv[1][j] >= '1' && argv[1][j] <= '4')
				block_view[j / 2] = argv[1][j] - '0';
			else
				return (0);
		}
		else
		{
			if (argv[1][j] != ' ')
				return (0);
		}
		j++;
	}
	if (j != 31)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	visited[16][4];
	int	block_view[16];
	int	block[16];

	if (check_input(argc, argv, block_view) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (dfs(0, visited, block_view, block) == 0)
		write(1, "Error\n", 6);
	return (0);
}

int	print_block(int block[])
{
	int		i;
	char	value;

	i = 0;
	while (i < 16)
	{
		value = block[i] + '0';
		write(1, &value, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
	return (1);
}
