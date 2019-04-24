/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 04:45:56 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 20:22:34 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_crmatrix(t_env *env)
{
	int i;
	int ret;

	ret = 1;
	if (!(env->matrix = (int **)malloc((env->n_room + 2) * sizeof(int*))))
		return (0);
	i = 0;
	while (i < env->n_room + 2)
	{
		if (!(env->matrix[i] = (int *)malloc(env->n_room * sizeof(int))))
			ret = 0;
		if (env->matrix[i])
			ft_filltab(env->matrix[i], 0, env->n_room);
		i++;
	}
	if (env->matrix[i - 1])
		ft_filltab(env->matrix[i - 1], -1, env->n_room);
	return (ret);
}

int		ft_atoi_protected(int *overflowing, const char *str)
{
	int			i;
	long long	total;
	int			positive;

	total = 0;
	positive = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		positive *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (total > 2147483647 || total < -2147483648)
			return (*overflowing = 1);
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	return (total * positive);
}

void	ft_initlem(t_env *env)
{
	env->n_end = 0;
	env->tmpline = NULL;
	env->n_room = 0;
	env->n_path = 0;
	env->end = -1;
	env->start = -1;
	env->matrix = NULL;
	env->list = NULL;
	env->path_list = NULL;
	env->ants = NULL;
}

void	ft_invalid_pipe(t_env *env)
{
	int x;
	int y;

	ft_filltab(env->matrix[env->n_room], 0, env->n_room);
	ft_filltab(env->matrix[env->n_room + 1], 0, env->n_room);
	y = 0;
	while (y < env->n_room)
	{
		x = 0;
		while (x < env->n_room)
		{
			if (env->matrix[x][y] == 3 || env->matrix[x][y] == 4)
				env->matrix[x][y] = 2;
			if ((env->matrix[x][y] == 2) && (env->matrix[y][x] == 2))
			{
				env->matrix[x][y] = 0;
				env->matrix[y][x] = 0;
			}
			x++;
		}
		y++;
	}
}

void	ft_unused_room(t_env *env)
{
	int x;
	int y;

	ft_filltab(env->matrix[env->n_room], 0, env->n_room);
	ft_filltab(env->matrix[env->n_room + 1], -1, env->n_room);
	y = 0;
	while (y < env->n_room)
	{
		x = 0;
		while (x < env->n_room)
		{
			if (env->matrix[x][y] == 2)
				env->matrix[x][y] = 4;
			x++;
		}
		y++;
	}
}
