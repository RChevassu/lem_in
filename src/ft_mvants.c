/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 02:38:34 by jlemahie          #+#    #+#             */
/*   Updated: 2018/10/28 02:36:46 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_mvtoend(t_env *env, int i)
{
	t_room *curroom;

	curroom = (t_room*)ft_lstidchr(env->list, env->ants[i].idpos)->content;
	curroom->ant = 0;
	env->ants[i].end = 1;
	curroom = (t_room*)ft_lstidchr(env->list, env->end)->content;
	ft_printf("L%d-%s", env->ants[i].idant, curroom->name);
	env->n_end++;
	return (1);
}

static int	ft_mvtonext(t_env *env, int i, int idnext)
{
	t_room *curroom;
	t_room *next;

	next = (t_room*)ft_lstidchr(env->list, idnext)->content;
	if (next->ant == 0)
	{
		curroom = (t_room*)ft_lstidchr(env->list, env->ants[i].idpos)->content;
		curroom->ant = 0;
		next->ant = 1;
		env->ants[i].pos++;
		env->ants[i].idpos = next->id;
		ft_printf("L%d-%s", env->ants[i].idant, next->name);
		return (1);
	}
	else
		return (0);
}

int			ft_mvant(t_env *env, int i)
{
	t_path *path;

	if (env->ants[i].end == 1)
		return (0);
	path = (t_path*)ft_patidchr(env->path_list, env->ants[i].idpath)->content;
	if (path->path[env->ants[i].pos + 1] == env->end)
		return (ft_mvtoend(env, i));
	else
		return (ft_mvtonext(env, i, path->path[env->ants[i].pos + 1]));
}
