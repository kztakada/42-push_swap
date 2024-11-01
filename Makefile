# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 17:58:09 by katakada          #+#    #+#              #
#    Updated: 2024/11/01 18:39:05 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_BONUS		=	checker

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -I $(INCS) 

LIBFT			=	libft/
INCS			=	includes/
OBJS_PATH		=	objs/
OBJS_BONUS_PATH	=	objs/bonus/
SRCS_PATH		=	src/
SRCS_BONUS_PATH	=	src/bonus/
SRCS			=	$(wildcard src/*.c)
SRCS_BONUS		=	$(wildcard src/bonus/*.c)
OBJS			=	$(SRCS:src/%.c=objs/%.o)
OBJS_BONUS		=	$(SRCS_BONUS:src/bonus/%.c=objs/bonus/%.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT)libft.a -o $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@


bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
	make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT)libft.a -o $(NAME_BONUS)

$(OBJS_BONUS_PATH)%.o : $(SRCS_BONUS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@


clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJS_PATH)

fclean:
	make fclean -C $(LIBFT)
	rm -rf $(OBJS_PATH)
	rm -f $(NAME) $(NAME_BONUS)

re:		fclean all

.PHONY:	all bonus clean fclean re
