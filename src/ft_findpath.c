/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 23:44:34 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 18:59:26 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_get_pathsup(t_env *env, t_path path, int i, int prev)
{
	int j;

	while (i > 1)
	{
		j = 0;
		while (j < env->n_room)
		{
			if (env->matrix[env->n_room][j] == i - 1
				&& env->matrix[j][prev] == 2)
			{
				path.path[i - 2] = prev;
				env->matrix[j][prev] = 5;
				if (env->matrix[env->n_room + 1][j] == 1
					|| env->matrix[env->n_room + 1][j] == 5)
					return (0);
				if (j != env->start)
					env->matrix[env->n_room + 1][j] = 5;
				prev = j;
				j = env->n_room;
			}
			j++;
		}
		i--;
	}
	return (1);
}

static void	is_good(t_env *env, int m, int lsupp)
{
	int x;
	int y;

	x = 0;
	while (x < env->n_room)
	{
		y = 0;
		while (y < env->n_room)
		{
			if (env->matrix[x][y] == 5)
				env->matrix[x][y] = m;
			y++;
		}
		x++;
	}
	x = 0;
	while (x != env->n_room)
	{
		if (env->matrix[env->n_room + 1][x] == 5)
			env->matrix[env->n_room + 1][x] = lsupp;
		x++;
	}
}

static int	ft_get_path(t_env *env, int i)
{
	t_path path;
	t_list *list;

	path.length = i - 1;
	if (!(path.path = (int *)malloc(sizeof(int) * path.length)))
		return (0);
	path.id = env->tmp_n_path + 1;
	if (!(ft_get_pathsup(env, path, i, env->end)))
	{
		is_good(env, 2, 0);
		free(path.path);
		return (2);
	}
	env->tmp_n_path++;
	is_good(env, 3, 1);
	if (!(list = ft_lstnew(&path, sizeof(t_path))))
		return (0);
	ft_lstadd(&env->tmp_path_list, list);
	return (1);
}

static int	ft_bfssup_modified(t_env *env, int j, int i)
{
	int k;

	k = 0;
	while (k < env->n_room)
	{
		if (env->matrix[j][k] == 2 && env->matrix[env->n_room][k] == 0)
		{
			if (k == env->end)
			{
				if (!(ft_get_path(env, i + 2)))
					return (0);
			}
			else
				env->matrix[env->n_room][k] = i + 2;
		}
		k++;
	}
	return (1);
}

int			ft_bfs_modified(t_env *env)
{
	int i;
	int j;

	env->matrix[env->n_room][env->start] = 1;
	i = 0;
	while (i < env->n_room)
	{
		j = 0;
		while (j < env->n_room)
		{
			if (env->matrix[env->n_room][j] == i + 1)
			{
				if (!(ft_bfssup_modified(env, j, i)))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
