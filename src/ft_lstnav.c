/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 00:46:21 by jlemahie          #+#    #+#             */
/*   Updated: 2019/02/07 21:34:19 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list	*ft_lstidchr(t_list *lst, int id)
{
	t_room	*room;

	while (lst)
	{
		room = (t_room*)lst->content;
		if (room->id == id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*ft_lstnamchr(t_list *lst, char *name)
{
	t_room	*room;

	if (name == NULL)
		return (NULL);
	while (lst)
	{
		room = (t_room*)lst->content;
		if (ft_strcmp(name, room->name) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*ft_patidchr(t_list *lst, int id)
{
	t_path *path;

	while (lst)
	{
		path = (t_path*)lst->content;
		if (path->id == id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int		ft_smpath(t_list *lst, t_env *env)
{
	int		s;
	t_path	*p;
	int		id;

	s = env->n_room * env->n_ants;
	while (lst)
	{
		p = (t_path*)lst->content;
		if (s > p->length)
		{
			s = p->length;
			id = p->id;
		}
		lst = lst->next;
	}
	lst = ft_patidchr(env->path_list, id);
	p = (t_path*)lst->content;
	if (p->length > 1)
		p->length++;
	return (id);
}
