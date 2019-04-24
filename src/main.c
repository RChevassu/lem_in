/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 02:07:25 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 19:02:24 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	find_path(t_env *env)
{
	env->tmp_n_path = 0;
	env->size = env->n_room * env->n_ants;
	env->path_list = NULL;
	while (ft_mark(env))
	{
		ft_invalid_pipe(env);
		ft_bfs_modified(env);
		ft_unused_room(env);
		if (!ft_is_better(env))
			break ;
		else
		{
			env->n_path = env->tmp_n_path;
			env->tmp_n_path = 0;
			env->size = env->tmpsize;
			ft_lstdel(&env->path_list, delpath);
			env->path_list = env->tmp_path_list;
			env->tmp_path_list = NULL;
		}
	}
	if (!env->path_list)
		return (0);
	return (1);
}

static int	lem_parse(t_env *env)
{
	int	ret;

	ret = 1;
	ret = (ret == 1 && ft_parseant(env, 0) != 0) ? 1 : 0;
	ret = (ret == 1 && ft_parseroom(env, 0) != 0) ? 1 : 0;
	if (ret == 1 && (env->end == -1 || env->start == -1))
		return (0);
	if (ret == 1 && ft_crmatrix(env) == 0)
		return (0);
	if (ret != 1)
		return (0);
	ft_parselinks(env, 0);
	return (ret);
}

static int	give_path(t_env *env)
{
	int i;

	if (!(env->ants = (t_ant *)malloc(sizeof(t_ant) * env->n_ants)))
		return (0);
	i = 0;
	while (i != env->n_ants)
	{
		env->ants[i].idant = i + 1;
		env->ants[i].idpath = ft_smpath(env->path_list, env);
		env->ants[i].pos = -1;
		env->ants[i].idpos = env->start;
		env->ants[i].end = 0;
		i++;
	}
	return (1);
}

static void	lem_in(t_env *env)
{
	int i;

	ft_print_map(env);
	while (env->n_end != env->n_ants)
	{
		i = 0;
		while (i != env->n_ants)
		{
			if (ft_mvant(env, i) == 1 && (i + 1) != env->n_ants)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
	}
}

int			main(int argc, char **argv)
{
	t_env env;

	(void)argv;
	(void)argc;
	ft_initlem(&env);
	if (!(lem_parse(&env)) || !(find_path(&env)) || !(give_path(&env)))
	{
		ft_printf("ERROR\n");
		return (ft_freelem(&env));
	}
	lem_in(&env);
	ft_freelem(&env);
	return (0);
}
