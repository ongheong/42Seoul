/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:08:06 by yeselee           #+#    #+#             */
/*   Updated: 2022/02/12 21:16:38 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		check_answer(int block[], int block_view[]);
void	print_block(int block[]);

void	dfs(int i, int visited[16][4], int	block_view[16], int block[16])
{
	int	j;
	int	result;

	j = 0;
	if (i == 16)
	{
		result = check_answer(block, block_view);
		if (result == 1)
			print_block(block);
		return ;
	}
	while (j < 4)	//visited 배열 0으로 초기화
	{
		visited[i][j] = 0;
		j++;
	}
	j = i - i % 4;
	while (j < i)
	{
		visited[i][block[j] - 1] = 1;
		j++;
	}
	j = i - (i / 4) * 4;
	while (j < i)
	{
		visited[i][block[j] - 1] = 1;
		j += 4;
	}
	j = 0;
	while (j < 4)
	{
		if (visited[i][j] == 0)
		{
			visited[i][j] = 1;
			block[i] = j + 1;
			dfs(i + 1, visited, block_view, block);
		}
		j++;
	}
	return ;
}

int	check_answer(int block[], int block_view[])
{
	int	i;
	int	j;
	int	count;
	int	max_height;

	i = 0;
	while (i < 16)
	{
		count = 1;
		if (0 <= i && i <= 3)
		{
			j = i;
			max_height = block[j];
			while (j < 12)
			{
				if (max_height < block[j + 4])
				{
					max_height = block[j + 4];
					count++;
				}
				j += 4;
			}
		}
		else if (4 <= i && i <= 7)
		{
			j = i + 8;
			max_height = block[j];
			while (j > 3)
			{
				if (max_height < block[j - 4])
				{
					max_height = block[j - 4];
					count++;
				}
				j -= 4;
			}
		}
		else if (8 <= i && i <= 11)
		{
			j = (i % 4) * 4;
			max_height = block[j];
			while (j % 4 != 3)
			{
				if (max_height < block[j + 1])
				{
					max_height = block[j + 1];
					count++;
				}
				j++;
			}
		}
		else
		{
			j = (i % 4) * 4 + 3;
			max_height = block[j];
			while (j % 4 != 0)
			{
				if (max_height < block[j - 1])
				{
					max_height = block[j - 1];
					count++;
				}
				j--;
			}
		}
		if (count != block_view[i])
			return (0);
		i++;
	}
	return (1);
}

void	print_block(int block[16])	//char형 배열로 바꾸기
{
	int	i;

	i = 0;
	while (i < 16)
	{
		write(1, &(block[i]+'0'), 1);
		i++;
	}
}

int	main(int argc, char **argv)	//입력받는 값 int형 배열로 바꾸기
{
	int	visited[16][4];
	int	block_view[16] = {2, 1, 2, 4, 2, 4, 2, 1, 2,3 ,1, 3, 3, 2, 2, 1};
	int	i;
	int	j;
	int	block[16];

	i = 0;
	while (i < 16)	//visited 배열 0으로 초기화
	{
		j = 0;
		while (j < 4)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	dfs(0, visited, block_view, block);
	return (0);
}
