# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 17:58:09 by katakada          #+#    #+#              #
#    Updated: 2024/11/16 01:11:23 by katakada         ###   ########.fr        #
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
SRCS			=	src/custom_operations.c \
					src/error_and_free.c \
					src/get_init_stack_funcs.c \
					src/get_init_stack.c \
					src/operations_funcs.c \
					src/operations_push.c \
					src/operations_reverse_rotate.c \
					src/operations_rotate.c \
					src/operations_swap.c \
					src/print_operations.c \
					src/sort_over_six_execute_min_op.c \
					src/sort_over_six_get_min_op_to_a_side.c \
					src/sort_over_six_get_min_op_to_b_side.c \
					src/sort_over_six_get_min_op.c \
					src/sort_over_six_to_b_side.c \
					src/sort_over_six_utils.c \
					src/sort_over_six.c \
					src/sort_three.c \
					src/sort_under_six.c \
					src/validation_sort.c
SRC_MONDATORY	=	src/push_swap_main.c

SRCS_BONUS		=	src/bonus/checker_main.c

OBJS			=	$(SRCS:src/%.c=objs/%.o)
OBJS_MONDATORY	=	$(SRC_MONDATORY:src/%.c=objs/%.o)
OBJS_BONUS		=	$(SRCS_BONUS:src/bonus/%.c=objs/bonus/%.o)


all:	$(NAME)

$(NAME): $(OBJS_MONDATORY) $(OBJS)
	make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_MONDATORY) $(OBJS) $(LIBFT)libft.a -o $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@


bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS) $(OBJS)
	make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS) $(LIBFT)libft.a -o $(NAME_BONUS)

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
