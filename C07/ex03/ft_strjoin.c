/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:23:32 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/24 12:43:35 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *arr);
char	*make_arr(char *arr, char *sep, char **strs, int size);
char	*ft_strcat(char *dest, char *src);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		seplen;
	int		strslen;
	int		i;
	char	*arr;

	i = 0;
	strslen = 0;
	seplen = ft_strlen(sep);
	if (size == 0)
	{
		arr = (char *)malloc(sizeof(char) * 1);
		*arr = '\0';
		return (arr);
	}
	while (i < size)
	{
		strslen += ft_strlen(strs[i]);
		i++;
	}
	arr = (char *)malloc(sizeof(char) * (strslen + seplen * (size - 1) + 1));
	return (make_arr(arr, sep, strs, size));
}

int	ft_strlen(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (0);
}

char	*make_arr(char *arr, char *sep, char **strs, int size)
{
	int	i;

	i = 1;
	arr[0] = '\0';
	arr = ft_strcat(arr, strs[0]);
	while (i < size)
	{
		arr = ft_strcat(arr, sep);
		arr = ft_strcat(arr, strs[i]);
		i++;
	}
	return (arr);
}

char	*ft_strcat(char *dest, char *src)
{
	int	lendest;
	int	i;

	i = 0;
	lendest = 0;
	while (dest[lendest])
		lendest++;
	while (src[i])
	{
		dest[lendest] = src[i];
		lendest++;
		i++;
	}
	dest[lendest] = '\0';
	return (dest);
}
