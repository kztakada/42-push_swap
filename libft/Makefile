# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 16:04:12 by katakada          #+#    #+#              #
#    Updated: 2024/10/28 23:26:10 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PRINTF = $(wildcard ft_printf/*.c)
SRCS = $(wildcard *.c) $(PRINTF)
BONUSSRCS =  $(wildcard bonus/*.c)
INCS			=	includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCS) 
ISBOUNS = 0

ifeq ($(ISBOUNS), 1)
	SRCS += $(BONUSSRCS)
endif

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) all ISBOUNS=1


clean:
	rm -f $(SRCS:.c=.o) $(BONUSSRCS:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re