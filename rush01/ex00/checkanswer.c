/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkanswer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:14:11 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/13 16:18:16 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int i, int block[])
{
	int	j;
	int	max_height;
	int	count;

	count = 1;
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
	return (count);
}

int	check_coldown(int i, int block[])
{
	int	j;
	int	max_height;
	int	count;

	count = 1;
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
	return (count);
}

int	check_rowleft(int i, int block[])
{
	int	j;
	int	max_height;
	int	count;

	count = 1;
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
	return (count);
}

int	check_rowright(int i, int block[])
{
	int	j;
	int	max_height;
	int	count;

	count = 1;
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
	return (count);
}

int	check_answer(int block[], int block_view[])
{
	int	i;
	int	count;

	i = 0;
	while (i < 16)
	{
		if (0 <= i && i <= 3)
			count = check_colup(i, block);
		else if (4 <= i && i <= 7)
			count = check_coldown(i, block);
		else if (8 <= i && i <= 11)
			count = check_rowleft(i, block);
		else
			count = check_rowright(i, block);
		if (count != block_view[i])
			return (0);
		i++;
	}
	return (1);
}
