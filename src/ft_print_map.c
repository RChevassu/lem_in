/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 18:16:32 by rchevass          #+#    #+#             */
/*   Updated: 2019/02/07 18:25:50 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ft_print_rooms(t_env *env, t_list *list, int i)
{
	t_room *room;

	if (list)
	{
		ft_print_rooms(env, list->next, i - 1);
		if (i == env->start)
			ft_printf("##start\n");
		else if (i == env->end)
			ft_printf("##end\n");
		room = (t_room *)list->content;
		ft_printf("%s %i %i\n", room->name, room->x, room->y);
	}
}

static void	ft_print_links(t_env *env)
{
	int		i;
	int		j;
	t_list	*list;
	t_room	*room;
	t_room	*room2;

	i = 0;
	while (i < env->n_room)
	{
		j = 0;
		list = ft_lstidchr(env->list, i);
		room = (t_room *)list->content;
		while (j < i)
		{
			if (env->matrix[i][j] != 0)
			{
				list = ft_lstidchr(env->list, j);
				room2 = (t_room *)list->content;
				ft_printf("%s-%s\n", room->name, room2->name);
			}
			j++;
		}
		i++;
	}
}

void		ft_print_map(t_env *env)
{
	ft_printf("%d\n", env->n_ants);
	ft_print_rooms(env, env->list, env->n_room - 1);
	ft_print_links(env);
	ft_printf("\n");
}
