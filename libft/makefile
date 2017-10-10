# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 09:40:00 by ysan-seb          #+#    #+#              #
#    Updated: 2017/05/16 13:09:14 by ysan-seb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAG = -Wall -Werror -Wextra

SRC = 	\
		ft_atoi.c \
		ft_itoa.c \
		ft_bzero.c \
		ft_memset.c \
		ft_strlen.c \
		ft_memcpy.c \
		ft_strcmp.c \
		ft_putnbr.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strchr.c \
		ft_strcat.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strmap.c \
		ft_strequ.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_lstnew.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstmap.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_putstr.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_lstiter.c \
		ft_isgraph.c \
		ft_strtrim.c \
		ft_isupper.c \
		ft_islower.c \
		ft_ispunct.c \
		ft_isspace.c \
		ft_iscntrl.c \
		ft_strjoin.c \
		ft_memmove.c \
		ft_strmapi.c \
		ft_strnequ.c \
		ft_tolower.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_strncmp.c \
		ft_memccpy.c \
		ft_strrchr.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_striter.c \
		ft_striteri.c \
		ft_memalloc.c \
		ft_isxdigit.c \
		ft_strsplit.c \
		ft_lstdelone.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \

OBJ = $(SRC:.c=.o)

DIR_HEADER = -I./

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ -c $< -I./includes 
	@echo "\033[38;5;208mLibft: \c\r"
	@echo "\033[0m\c"
	@echo "$<\r\c"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
