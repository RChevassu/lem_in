/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseroom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 06:19:09 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 20:41:55 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	format_room(char *line)
{
	int		i;
	int		x;
	char	*ptr;

	i = 1;
	if ((ptr = ft_strbchr(line, '-', ' ')) != NULL || line[0] == 'L')
		return (0);
	if ((ptr = ft_strchr(line, ' ')) == NULL)
		return (0);
	if (!(x = ft_isnbr(ptr + i)))
		return (0);
	i = x + 1;
	if (ptr[i] != ' ')
		return (0);
	if (!(x = ft_isnbr(ptr + i + 1)))
		return (0);
	i += x + 1;
	if (ptr[i] != 0)
		return (0);
	return (1);
}

static int	ft_addroom(t_env *env, char *line)
{
	t_room	room;
	t_list	*new;
	int		overflowing;

	if (!(room.name = ft_strtronc(line, ' ')))
		return (-1);
	if (ft_lstnamchr(env->list, room.name))
	{
		free(room.name);
		return (-1);
	}
	overflowing = 0;
	room.id = env->n_room;
	room.ant = 0;
	room.x = ft_atoi_protected(&overflowing, ft_strchr(line, ' '));
	room.y = ft_atoi_protected(&overflowing, ft_strrchr(line, ' '));
	if (overflowing || !(new = ft_lstnew(&room, sizeof(room))))
	{
		free(room.name);
		return (-1);
	}
	ft_lstadd(&env->list, new);
	env->n_room++;
	return (1);
}

static int	ft_checkroom(char *line)
{
	if (!line || line[0] == 0)
		return (-1);
	else if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		return (2);
	else if (line[0] == '#')
		return (0);
	else if (format_room(line) == 1)
		return (1);
	return (3);
}

static int	ft_addspecroom(t_env *env, char *line, int fd)
{
	char	*l2;
	int		ret;
	int		e;

	while (get_next_line(fd, &l2) > 0)
	{
		if ((ret = ft_checkroom(l2)) == 1)
			e = ft_addroom(env, l2);
		ft_strdel(&l2);
		if (ret == 2 || ret == 3 || ret == -1)
			return (-1);
		if (ret == 1)
		{
			if (ft_strcmp(line, "##start") == 0 && e != -1 && env->start == -1)
				env->start = env->n_room - 1;
			else if (ft_strcmp(line, "##end") == 0 && e != -1 && env->end == -1)
				env->end = env->n_room - 1;
			else
				e = -1;
			return ((e != -1) ? 1 : -1);
		}
	}
	ft_strdel(&l2);
	return (0);
}

int			ft_parseroom(t_env *env, int fd)
{
	char	*line;
	int		ret;
	int		e;

	e = 0;
	env->tmpline = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!line)
			return (0);
		ret = ft_checkroom(line);
		if (ret == 1)
			e = ft_addroom(env, line);
		else if (ret == 2)
			e = ft_addspecroom(env, line, fd);
		else if (ret == 3 && env->n_room > 0)
			env->tmpline = ft_strdup(line);
		ft_strdel(&line);
		if (e == -1 || ret == -1)
			return (0);
		if (ret == 3)
			return ((env->n_room > 0) ? 1 : 0);
	}
	ft_strdel(&line);
	return (1);
}
