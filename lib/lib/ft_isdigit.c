/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:39:02 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 19:51:38 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_ismath(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		return (1);
	return (0);
}

int	ft_issym(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_isnbr(char *str)
{
	int	i;
	int	x;

	x = 0;
	if (str[0] == '-' || str[0] == '+')
		x++;
	i = x;
	while (ft_isdigit(str[i]))
		i++;
	if (i == x)
		return (0);
	return (i);
}
