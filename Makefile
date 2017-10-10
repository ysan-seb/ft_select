# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysan-seb <ysan-seb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 07:19:36 by ysan-seb          #+#    #+#              #
#    Updated: 2017/05/25 13:26:50 by ysan-seb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_select

SRCS	=	main.c \
			tools.c \
			core.c \
			core2.c \
			signal.c \

OBJS	=	main.o \
			tools.o \
			core.o \
			core2.o \
			signal.o \

CC	=	gcc

CFLAGS	=  -Wall -Werror -Wextra

HEADER = -I./

LIBFT = ./libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

.SILENT:
		
$(NAME)	:	$(OBJS)
		@make -C libft/
		@$(CC) -o $(NAME) $(OBJS) $(HEADER) $(LIBFT) -L. -ltermcap
		@echo "\033[38;5;208mLibft\033[0m : Is fully compiled\c\r"
		@echo "\n\033[38;5;208mft_select\033[0m : Ready"

clean	:
		@make -C libft/ clean
		@$(RM) $(OBJS)
		@echo "\033[38;5;208mft_select\033[0m : Clean"

fclean:
		@make -C libft/ fclean
		@$(RM) $(NAME) $(OBJS)
		@echo "\033[38;5;208mft_select\033[0m : Full clean"

re	:	fclean all
