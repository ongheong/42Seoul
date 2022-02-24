/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeosim <yeosim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:47:48 by yeosim            #+#    #+#             */
/*   Updated: 2022/02/24 12:30:25 by yeosim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);

char	*ft_strdup(char *src)
{
	int		i;
	char	*arr;

	i = 0;
	if (src[i] == '\0')
	{
		arr = (char *)malloc(sizeof(char) * 1);
		*arr = '\0';
		return (arr);
	}
	while (src[i])
		i++;
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (!arr)
		return (0);
	return (ft_strcpy(arr, src));
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
