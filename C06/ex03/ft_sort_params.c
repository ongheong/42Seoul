/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:18:27 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/23 20:21:19 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	swap(char **a, char **b);
int		ft_strlen(char *arr);

int	main(int argc, char **argv)
{
	int	i;
	int	temp;

	i = 1;
	temp = argc - 1;
	while (temp > 1)
	{
		while (i < temp)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				swap(&argv[i], &argv[i + 1]);
			i++;
		}
		temp--;
		i = 1;
	}
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] != s2[i])
			break ;
		if (!(s1[i] && s2[i]))
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
