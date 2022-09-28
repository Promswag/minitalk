# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 10:13:56 by gbaumgar          #+#    #+#              #
#    Updated: 2022/02/28 14:07:50 by gbaumgar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero\
			ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr\
			ft_strncmp ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup\
			ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri\
			ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

BSRC	=	ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus\
			ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus
			
SRCC	= ${SRC:%=%.c}
BSRCC	= ${BSRC:%=%.c}
OBJS	= ${SRCC:%.c=%.o}
BOBJS	= ${BSRCC:%.c=%.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	rm -f ${OBJS} ${BOBJS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

bonus: ${BOBJS} ${OBJS}
	ar rc ${NAME} ${OBJS} ${BOBJS}

