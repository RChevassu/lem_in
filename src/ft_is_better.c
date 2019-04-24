/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_better.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:22:19 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/06 21:22:53 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	calc_ratio(t_env *env, t_list *tmp_path)
{
	int		i;
	t_path	*test;
	int		longest_path;
	int		sum;

	i = 0;
	test = (t_path*)tmp_path->content;
	longest_path = test->length;
	sum = 0;
	while (tmp_path)
	{
		test = (t_path*)tmp_path->content;
		sum += longest_path - test->length;
		tmp_path = tmp_path->next;
	}
	if (sum > env->n_ants)
		return (-1);
	sum = (((env->n_ants - sum) + env->tmp_n_path - 1)
		/ env->tmp_n_path) + longest_path - 1;
	return (sum);
}

int			ft_is_better(t_env *env)
{
	if (env->tmp_path_list == NULL)
		return (0);
	if ((env->tmpsize = calc_ratio(env, env->tmp_path_list)) == -1)
		return (0);
	if (env->path_list == NULL)
		return (1);
	if (env->tmp_n_path > env->n_ants)
		return (0);
	if (env->tmpsize <= env->size)
		return (1);
	return (0);
}
