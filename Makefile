# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprofett <marvin@42->fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 14:04:13 by mprofett          #+#    #+#              #
#    Updated: 2022/10/03 14:05:41 by mprofett         ###   ########->fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_utils.c

SRCSB		= ft_printf_bonus.c ft_printf_printvars_bonus.c \
			ft_printf_getvalues_bonus.c ft_printf_putvalues_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJSB		= ${SRCSB:.c=.o}

LIB_NAME	= ./libft/libft.a

LIB_PATH	= ./libft/

CC			= gcc

RM			= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${LIB_NAME} ${OBJS}
	ar rc ${NAME} ${OBJS}

${LIB_NAME}:
	${MAKE} -C ${LIB_PATH}
	mv ${LIB_NAME} ${NAME}

all: ${NAME}

bonus: ${LIB_NAME} ${OBJSB}
	ar rc ${NAME} ${OBJSB}

clean:
	${MAKE} clean -C ${LIB_PATH}
	${RM} ${OBJSB} ${OBJS}

fclean: clean
	${RM} ${NAME} ${LIB_NAME}

re:	fclean all

.PHONY:	all bonus clean fclean re
