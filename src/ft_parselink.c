/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselink.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 22:36:50 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 17:50:44 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	format_link(char *line)
{
	char	*ptr;

	if (ft_strchr(line, ' ') != NULL)
		return (0);
	if ((ptr = ft_strchr(line, '-')) == NULL)
		return (0);
	if (ptr[1] == 0)
		return (0);
	if (ft_strchr(ptr + 1, '-') != NULL)
		return (0);
	if (line[0] == 'L')
		return (0);
	return (1);
}

static int	ft_setmatrix(t_env *env, t_list *l1, t_list *l2)
{
	t_room	*r1;
	t_room	*r2;

	r1 = (t_room*)l1->content;
	r2 = (t_room*)l2->content;
	env->matrix[r1->id][r2->id] = 1;
	env->matrix[r2->id][r1->id] = 1;
	return (1);
}

static int	ft_addlink(t_env *env, char *line)
{
	char	*n1;
	char	*n2;
	t_list	*l1;
	t_list	*l2;
	int		ret;

	if (line[0] == 0)
		return (0);
	n1 = ft_strtronc(line, '-');
	n2 = ft_strdup(ft_strchr(line, '-') + 1);
	l1 = ft_lstnamchr(env->list, n1);
	l2 = ft_lstnamchr(env->list, n2);
	if (!l1 || !l2)
		ret = (n1 != NULL && n2 != NULL) ? 0 : -1;
	else
		ret = ft_setmatrix(env, l1, l2);
	ft_strdel(&n1);
	ft_strdel(&n2);
	return (ret);
}

static int	ft_checklink(char *line)
{
	if (line[0] == '#')
		return (0);
	else if (format_link(line) == 1 || line[0] == 0)
		return (1);
	return (-1);
}

int			ft_parselinks(t_env *env, int fd)
{
	int		ret;
	char	*line;
	int		e;

	if (!env->tmpline || (ret = ft_checklink(env->tmpline)) == -1)
		return (0);
	if (ret == 1 && (e = ft_addlink(env, env->tmpline)) != 1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!line)
			return (0);
		if ((ret = ft_checklink(line)) == 1)
			e = ft_addlink(env, line);
		ft_strdel(&line);
		if (e == -1 || e == 0)
			return (0);
		if (ret == -1)
			return (0);
	}
	ft_strdel(&line);
	return (1);
}
