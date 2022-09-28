# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:33:16 by gbaumgar          #+#    #+#              #
#    Updated: 2022/03/23 18:34:57 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

INCLUDE_DIR 	= ./include/
SRC_DIR 		= ./src/
OUT_DIR			= ./
SRC				=	ft_printf.c ft_printf_utils.c ft_printf_utils2.c\
					ft_printf_display_char.c ft_printf_display_str.c ft_printf_display_ptr.c\
					ft_printf_display_int.c ft_printf_display_uint.c ft_printf_display_hex.c\
					ft_printf_display_hash.c ft_printf_display_space.c ft_printf_display_sign.c 
OBJS			= ${SRC:%.c=${OUT_DIR}%.o}

AR				= ar rc
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I${INCLUDE_DIR}
RM				= rm -f

all: ${NAME}

$(NAME): ${OBJS}
	${AR} ${NAME} ${OBJS} 

${OUT_DIR}%.o: ${SRC_DIR}%.c 
	${CC} ${CFLAGS} $< -c -o $@

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean ${NAME}

bonus:	all

.PHONY:	all clean fclean re bonus