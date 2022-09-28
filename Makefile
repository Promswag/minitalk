# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 14:35:47 by gbaumgar          #+#    #+#              #
#    Updated: 2022/09/28 16:29:25 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minitalk
SERVER			= server
CLIENT			= client

INCLUDE_DIR		= ./include/
SRC_DIR			= ./src/
OUT_DIR			= ./

SERVER_SRC		= server.c
CLIENT_SRC		= client.c
SERVER_OBJS		= ${SERVER_SRC:%.c=${OUT_DIR}%.o}
CLIENT_OBJS		= ${CLIENT_SRC:%.c=${OUT_DIR}%.o}

INCLUDE			= -I${INCLUDE_DIR}
LIB_FT			= -L libft -lft
LIB_PRINTF		= -L ft_printf -lftprintf

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: ${NAME}

${NAME}: ${SERVER} ${CLIENT}

${CLIENT}: ${CLIENT_OBJS}
	make -C libft
	make -C ft_printf
	${CC} -o ${CLIENT} ${LIB_FT} ${LIB_PRINTF} ${INCLUDE} ${CLIENT_OBJS}

${SERVER}: ${SERVER_OBJS}
	make -C libft
	make -C ft_printf
	${CC} -o ${SERVER} ${LIB_FT} ${LIB_PRINTF} ${INCLUDE} ${SERVER_OBJS}

${OUT_DIR}%.o: ${SRC_DIR}%.c 
	${CC} ${CFLAGS} ${INCLUDE} $< -c -o $@

clean:
	make clean -C libft
	make clean -C ft_printf
	${RM} ${SERVER_OBJS} ${CLIENT_OBJS}

fclean:	clean
	make fclean -C libft
	make fclean -C ft_printf
	${RM} ${SERVER} ${CLIENT}

re: fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re bonus
