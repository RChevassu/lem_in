/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 16:34:05 by rchevass          #+#    #+#             */
/*   Updated: 2019/02/07 16:19:10 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_bfs_setorder(t_env *env, int j, int i, int k)
{
	if (env->matrix[env->n_room + 1][j] != k)
	{
		if (env->matrix[j][k] == 1 && env->matrix[env->n_room][k] <= 0
			&& j != env->end)
		{
			env->matrix[env->n_room + 1][k] = j;
			env->matrix[env->n_room][k] = i + 2;
		}
		if (env->matrix[j][k] == 4 && env->matrix[env->n_room][k] <= 0
			&& j != env->end)
		{
			if (env->matrix[env->n_room][j] > 1
				&& env->matrix[env->n_room][k] <= 0)
			{
				env->matrix[env->n_room + 1][k] = j;
				env->matrix[env->n_room][k] = i + 2;
			}
			else if (env->matrix[env->n_room][j] <= 1
				&& env->matrix[env->n_room][k] == 0)
			{
				env->matrix[env->n_room + 1][k] = j;
				env->matrix[env->n_room][k] = -(i + 2);
			}
		}
	}
}

static int	ft_bfssup(t_env *env, int j, int i)
{
	int k;

	k = 0;
	while (k < env->n_room)
	{
		ft_bfs_setorder(env, j, i, k);
		if (k == env->end && env->matrix[env->n_room][k] > 0)
			return (1);
		k++;
	}
	return (0);
}

static int	ft_bfs(t_env *env)
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
			if (env->matrix[env->n_room][j] == i + 1
				|| env->matrix[env->n_room][j] == -(i + 1))
				if (ft_bfssup(env, j, i))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_mark(t_env *env)
{
	if (!ft_bfs(env))
		return (0);
	env->curr = env->end;
	if (!(ft_mark_path(env)))
		return (0);
	return (1);
}
