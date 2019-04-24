/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 02:07:13 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 17:50:49 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	format_ants(char *line)
{
	int i;

	i = 0;
	if ((line[0] != '#' && ft_isdigit(line[i]) != 1) || line[0] == 0)
		return (-1);
	if (line[0] == '#')
		return (0);
	while (ft_isdigit(line[i]) == 1)
		i++;
	if (ft_isprint(line[i]) == 1)
		return (-1);
	return (1);
}

int			ft_parseant(t_env *env, int fd)
{
	char	*line;
	int		ret;

	while ((get_next_line(fd, &line)) > 0)
	{
		if (!line)
			return (0);
		if ((ret = format_ants(line)) == -1)
		{
			ft_strdel(&line);
			return (0);
		}
		if (ret == 1)
			env->n_ants = ft_atoi(line);
		ft_strdel(&line);
		if (ret == 1)
			return ((env->n_ants > 0) ? 1 : 0);
	}
	ft_strdel(&line);
	return (0);
}
