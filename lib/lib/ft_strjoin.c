/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:46:41 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/27 10:53:53 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		p;
	char	*r;
	int		i;
	int		y;

	i = 0;
	y = 0;
	p = ft_strlen(s1) + ft_strlen(s2) + 1;
	r = malloc(p * sizeof(char));
	if (r == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[y] != 0)
	{
		r[i] = s2[y];
		i++;
		y++;
	}
	r[i] = 0;
	return (r);
}
