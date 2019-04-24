/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchevass <rchevass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 00:58:05 by rchevass          #+#    #+#             */
/*   Updated: 2019/02/07 20:19:09 by rchevass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../lib/include/inclib.h"

typedef struct	s_room
{
	char	*name;
	int		id;
	int		ant;
	int		x;
	int		y;
}				t_room;

typedef struct	s_path
{
	int *path;
	int length;
	int id;
}				t_path;

typedef struct	s_ant
{
	int idant;
	int idpath;
	int idpos;
	int pos;
	int	end;
}				t_ant;

typedef struct	s_env{
	t_ant	*ants;
	int		**matrix;
	char	*tmpline;
	int		start;
	int		end;
	int		n_room;
	int		n_ants;
	int		n_path;
	int		n_end;
	int		size;
	int		tmpsize;
	int		tmp_n_path;
	int		curr;
	t_list	*list;
	t_list	*path_list;
	t_list	*tmp_path_list;
}				t_env;

int				ft_mark_path(t_env *env);
int				ft_mark(t_env *env);
void			ft_invalid_pipe(t_env *env);
void			ft_unused_room(t_env *env);
int				ft_is_better(t_env *env);
int				ft_bfs_modified(t_env *env);
void			delpath(void *content, size_t size_content);
void			ft_initlem(t_env *env);
int				ft_crmatrix(t_env *env);
int				ft_parselinks(t_env *env, int fd);
int				ft_freelem(t_env *env);
t_list			*ft_lstnamchr(t_list *lst, char *name);
t_list			*ft_lstidchr(t_list *lst, int id);
t_list			*ft_patidchr(t_list *lst, int id);
void			ft_print_map(t_env *env);
int				ft_parseant(t_env *env, int fd);
int				ft_parseroom(t_env *env, int fd);
int				ft_smpath(t_list *lst, t_env *env);
int				ft_mvant(t_env *env, int i);
int				ft_atoi_protected(int *overflowing, const char *str);

#endif
