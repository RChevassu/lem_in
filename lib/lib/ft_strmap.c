/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:20:02 by jlemahie          #+#    #+#             */
/*   Updated: 2017/11/27 20:38:58 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		p;
	char	*r;

	p = ft_strlen(s) + 1;
	i = 0;
	r = malloc(p * sizeof(char));
	if (r == NULL)
		return (NULL);
	while (i < (p - 1))
	{
		r[i] = f(s[i]);
		i++;
	}
	r[i] = 0;
	return (r);
}
