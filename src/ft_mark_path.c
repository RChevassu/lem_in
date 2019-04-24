/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:59:58 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 16:20:34 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_mark_neg(t_env *env, int i, int j)
{
	while (i < 0)
	{
		j = 0;
		while (j < env->n_room)
		{
			if (env->matrix[env->n_room][j] == i + 1
				&& (env->matrix[j][env->curr] == 1
				|| env->matrix[j][env->curr] == 4))
			{
				env->matrix[j][env->curr] = 2;
				env->curr = j;
				break ;
			}
			j++;
		}
		if (j == env->n_room)
			break ;
		i++;
	}
	if (i == -2)
		return (1);
	return (0);
}

int			ft_mark_path(t_env *env)
{
	int i;
	int j;

	i = env->matrix[env->n_room][env->end];
	while (i > 1)
	{
		j = 0;
		while (j < env->n_room)
		{
			if (env->matrix[env->n_room][j] == i - 1
				&& (env->matrix[j][env->curr] == 1
				|| env->matrix[j][env->curr] == 4))
			{
				env->matrix[j][env->curr] = 2;
				env->curr = j;
				break ;
			}
			j++;
		}
		if (j == env->n_room)
			break ;
		i--;
	}
	return (i == 1 ? 1 : ft_mark_neg(env, -i, j));
}
