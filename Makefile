# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlemahie <jlemahie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/16 03:23:05 by jlemahie          #+#    #+#              #
#    Updated: 2019/02/07 18:18:29 by rchevass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CFLAGS = -Wall -Wextra -Werror

INC = includes/lem_in.h
OBJ_PATH = obj
SRC_PATH = src
LIB_PATH = lib/libft.a

SOURCES = 	main.c \
		ft_parseroom.c \
		utils.c \
		ft_parseant.c \
		ft_parselink.c \
		ft_mark.c \
		ft_freelem.c \
		ft_lstnav.c \
		ft_mvants.c \
		ft_is_better.c \
		ft_findpath.c \
		ft_mark_path.c \
		ft_print_map.c

SRCS = $(addprefix $(SRC_PATH)/, $(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@make -C lib all
		@$(CC) $(CFLAGS) $(OBJS) $(LIB_PATH) -o $(NAME)
		@echo "Compilation $(NAME) OK"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
		@mkdir -p obj
		@gcc $(CFLAGS) -o $@ -c $<

clean:
		@make -C lib clean
		@rm -rf $(OBJ_PATH)


fclean:	clean
		@make -C lib fclean
		@rm -f $(NAME)

re: fclean all
