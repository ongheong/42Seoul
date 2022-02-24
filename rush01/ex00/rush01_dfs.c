/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01_dfs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:07:47 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/13 17:31:36 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_answer(int block[], int block_view[]);
int		print_block(int block[]);
void	initialize_visited(int visited[16][4], int block[], int i);

int	dfs(int i, int visited[16][4], int block_view[16], int block[16])
{
	int	j;
	int	error;

	error = 0;
	j = -1;
	if (i == 16)
	{
		if (check_answer(block, block_view))
			error = print_block(block);
		return (error);
	}
	initialize_visited(visited, block, i);
	while (++j < 4)
	{
		if (visited[i][j] == 0)
		{
			visited[i][j] = 1;
			block[i] = j + 1;
			error = dfs(i + 1, visited, block_view, block);
		}
		if (error == 1)
			break ;
	}
	return (error);
}

void	initialize_visited(int visited[16][4], int block[], int i)
{
	int	j;

	j = -1;
	while (++j < 4)
		visited[i][j] = 0;
	j = i - i % 4 - 1;
	while (++j < i)
		visited[i][block[j] - 1] = 1;
	j = i - (i / 4) * 4;
	while (j < i)
	{
		visited[i][block[j] - 1] = 1;
		j += 4;
	}
}
