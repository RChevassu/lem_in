/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 00:51:04 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 18:26:19 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delist(void *content, size_t size_content)
{
	t_room	*room;

	room = (t_room*)content;
	ft_strdel(&room->name);
	free(room);
	(void)size_content;
}

void	delpath(void *content, size_t size_content)
{
	t_path *path;

	path = (t_path*)content;
	free(path->path);
	free(path);
	(void)size_content;
}

int		ft_freelem(t_env *env)
{
	int	i;

	ft_lstdel(&env->list, delist);
	ft_lstdel(&env->path_list, delpath);
	ft_strdel(&env->tmpline);
	if (env->matrix != NULL)
	{
		i = 0;
		while (i < env->n_room + 2)
		{
			free(env->matrix[i]);
			i++;
		}
		free(env->matrix);
	}
	free(env->ants);
	return (0);
}
