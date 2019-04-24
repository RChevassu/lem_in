/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 01:23:34 by jlemahie          #+#    #+#             */
/*   Updated: 2018/10/16 03:02:22 by jlemahie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*ret;
	t_list	*tmp;

	if (!(lst))
		return (NULL);
	if (!(ret = f(lst)))
		return (NULL);
	new = ret;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp = f(lst)))
			return (NULL);
		new->next = tmp;
		new = new->next;
		lst = lst->next;
	}
	return (ret);
}
