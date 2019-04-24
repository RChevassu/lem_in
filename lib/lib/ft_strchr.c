/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:58:12 by jlemahie          #+#    #+#             */
/*   Updated: 2018/10/28 03:39:24 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char*)s;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)s + i);
	return (NULL);
}

char	*ft_strbchr(const char *s, int c, int stop)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char*)s;
	while (s[i] != 0 && s[i] != stop)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)s + i);
	return (NULL);
}
